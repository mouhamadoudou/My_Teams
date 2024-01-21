/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void init_default_value_server(Server_t *server)
{
    server->client.activity = 0;
    server->addrlen = 0;
    server->master_socket = 0;
    server->max_clients = 10;
    server->max_sd = 0;
    server->new_socket = 0;
    server->client.valread = 0;
    server->sd = 0;
}

void init_client_socket_and_pos_msg(Server_t *server)
{
    for (int i = 0; i < server->max_clients; i++) {
        server->client_socket[i] = 0;
    }
    for (int i = 0; i < server->max_clients; i++) {
        server->client.pos_msg[i].key = -1;
        server->client.pos_msg[i].value = 0;
        server->client.pos_msg[i].client_data = NULL;
    }
}

void init_master_socket_and_adress(Server_t *server)
{
    server->master_socket = socket(AF_INET, SOCK_STREAM, 0);
    server->address.sin_family = AF_INET;
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->address.sin_port = htons(server->PORT);
    bind(server->master_socket, (struct sockaddr *)&server->address,
    sizeof(server->address));
}

void init_server(Server_t *server, DataManage_t *data)
{
    init_default_value_server(server);
    init_client_socket_and_pos_msg(server);
    init_master_socket_and_adress(server);
    init_cmd(server, data);
    init_resp(server);
    listen(server->master_socket, 10);
    server->addrlen = sizeof(server->address);
}
