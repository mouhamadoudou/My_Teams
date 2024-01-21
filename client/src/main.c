/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void input_output_check(Server_t *server, char *id_mp, int i)
{
    if ((server->client.valread =
    read(server->sd, server->client.buffer, 1000)) == 0) {
        quit_cmd(server, id_mp, i);
    } else {
        parse(server);
        commande_manage(server, id_mp, i);
    }
}

int input_output_help(Server_t *server, char *id_mp, int i)
{
    if (FD_ISSET(server->sd, &server->readfds)) {
        input_output_check(server, id_mp, i);
    }
    return 0;
}

int input_output(Server_t *server)
{
    char *id_mp = "";
    for (int i = 0; i < server->max_clients; i++) {
        server->sd = server->client_socket[i];
        if (FD_ISSET(server->sd, &server->readfds)) {
            input_output_help(server, id_mp, i);
        }
    }
    return 0;
}

void manage_client(Server_t *server)
{
    int resp_230 = get_mapstr_resp_pos(server, 230);
    while (TRUE) {
        FD_ZERO(&server->readfds);
        FD_SET(server->master_socket, &server->readfds);
        server->max_sd = server->master_socket;
        add_file_descriptor_in_readfds(server);
        server->client.activity = select(server->max_sd + 1,
        &server->readfds, NULL, NULL, NULL);
        if ((server->client.activity < 0) && (errno != EINTR)) {
            printf("select error");
        }
        if (FD_ISSET(server->master_socket, &server->readfds)) {
            check_accept_add_to_list(server);
        } else
        input_output(server);
    }
}

int main(int ac, char **av)
{
    Server_t *server = malloc(sizeof(Server_t));
    if (server == NULL)
        exit(84);
    error_manage(ac, av, server);
    init_server(server);
    init_directory(server, av[2]);
    manage_client(server);
    free(server);
    return 0;
}
