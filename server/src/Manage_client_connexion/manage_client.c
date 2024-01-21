/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void input_output_check(Server_t *server, DataManage_t *data, int i)
{
    if ((server->client.valread =
    read(server->sd, server->client.buffer, 1000)) == 0) {
        quit_cmd(server, data, i);
    } else {
        parse(server);
        commande_manage(server,data, i);
    }
}

int input_output_help(Server_t *server, DataManage_t *data, int i)
{
    input_output_check(server, data, i);
    return 0;
}

int input_output(Server_t *server, DataManage_t *data)
{
    for (int i = 0; i < server->max_clients; i++) {
        server->sd = server->client_socket[i];
        if (FD_ISSET(server->sd, &server->readfds)) {
            input_output_help(server, data, i);
        }
    }
    return 0;
}

void manage_client(Server_t *server, DataManage_t *data)
{
    while (TRUE) {
        FD_ZERO(&server->readfds);
        FD_SET(server->master_socket, &server->readfds);
        server->max_sd = server->master_socket;
        add_file_descriptor_in_readfds(server, data);
        server->client.activity = select(server->max_sd + 1,
        &server->readfds, NULL, NULL, NULL);
        if ((server->client.activity < 0) && (errno != EINTR)) {
            printf("select error");
        }
        if (FD_ISSET(server->master_socket, &server->readfds)) {
            check_accept_add_to_list(server, data);
        } else
        input_output(server, data);
    }
}
