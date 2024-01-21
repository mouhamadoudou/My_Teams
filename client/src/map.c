/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

int get_map_pos(Server_t *server, int key)
{
    for (int a = 0; a < server->max_clients; a++) {
        if ( server->client.pos_msg[a].key == key) {
            return a;
        }
    }
    return -1;
}

int get_mapstr_pos(Server_t *server, char *value)
{
    for (int a = 0; a < 14; a++) {
        if (strcmp(server->client.cmd[a].value, value) == 0) {
            return a;
        }
    }
    return -1;
}

int get_mapstr_resp_pos(Server_t *server, int key)
{
    for (int a = 0; a < 18; a++) {
        if (server->resp_cmd[a].key == key) {
            return a;
        }
    }
    return -1;
}
