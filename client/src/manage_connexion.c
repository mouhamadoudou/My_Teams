/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void init_pos_msg(Server_t *server, int i)
{
    for (int a = 0; a < server->max_clients; a++) {
        if (server->client.pos_msg[a].key == -1) {
            server->client.pos_msg[a].key = i;
            printf("%d\n", server->client.pos_msg[a].key);
            break;
        }
    }
}

void add_to_list_socket(Server_t *server)
{
    for (int i = 0; i < server->max_clients; i++) {
        if (server->client_socket[i] == 0) {
            server->client_socket[i] = server->new_socket;
            init_pos_msg(server, server->new_socket);
            server->client.pos_msg[get_map_pos(server,
            server->new_socket)].value++;
            break;
        }
    }
}

void add_file_descriptor_in_readfds(Server_t *server)
{
    for (int i = 0; i < server->max_clients; i++) {
        server->sd = server->client_socket[i];
        if (server->sd > 0)
            FD_SET(server->sd, &server->readfds);
        if (server->sd > server->max_sd)
            server->max_sd = server->sd;
    }
}

void check_accept_add_to_list(Server_t *server)
{
    char *resp_220 = "220\r\n";

    if ((server->new_socket = accept(server->master_socket,
    (struct sockaddr *)&server->address, (socklen_t *)&server->addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    send(server->new_socket, resp_220, strlen(resp_220), 0);
    add_to_list_socket(server);
}

void commande_manage(Server_t *server, char *id_mp, int i)
{
    if (is_connected(server, id_mp, i))
        manage_client_account(server, i);
}
