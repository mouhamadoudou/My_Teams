/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void check_password(Server_t *server, char *id_mp, int i)
{
    int resp_230 = get_mapstr_resp_pos(server, 230);
    char *resp_xxx = "Error identifier or password not valid\r\n";
    int resp_332 = get_mapstr_resp_pos(server, 332);

    if (server->client.pos_msg[get_map_pos(server, server->sd)].value == 2) {
        if (strcmp(server->client.buffer_array[1], id_mp) == 0
        && server->client.buffer_array[1] != NULL) {
            send(server->sd, server->resp_cmd[resp_230].value,
            strlen(server->resp_cmd[resp_230].value), 0);
            server->client.pos_msg[get_map_pos(server, server->sd)].value++;
        } else
        send(server->sd, resp_xxx, strlen(resp_xxx), 0);
    }
}
