/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

int is_connected(Server_t *server, char *id_mp, int i)
{
    int resp_22 = get_mapstr_resp_pos(server, 22);
    int pos = get_mapstr_pos(server, server->client.buffer_array[0]);
    if (server->client.pos_msg[get_map_pos(server, server->sd)].value == 3) {
        return TRUE;
    }
    if (pos == -1) {
        send(server->sd, server->resp_cmd[resp_22].value,
        strlen(server->resp_cmd[resp_22].value), 0);
        return FALSE;
    }
    if (pos != 0 && pos != 1 && pos != 2 &&
    server->client.pos_msg[get_map_pos(server, server->sd)].value < 3 )
        send(server->sd, server->resp_cmd[resp_22].value,
        strlen(server->resp_cmd[resp_22].value), 0);
    server->f[pos](server, id_mp, i);
    return FALSE;
}

int check_valid_cmd(Server_t *server)
{
    for (int a = 0; a < 14; a++) {
        if (strcmp(server->client.cmd[a].value, server->client.buffer_array[0])
        == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void manage_client_account_execute(Server_t *server, int i)
{
    int resp_22 = get_mapstr_resp_pos(server, 22);
    int pos = get_mapstr_pos(server, server->client.buffer_array[0]);

    if (pos == -1)
        send(server->sd, server->resp_cmd[resp_22].value,
        strlen(server->resp_cmd[resp_22].value), 0);
    if (pos != 0 && pos != 1 && pos != 2 &&
    server->client.pos_msg[get_map_pos(server, server->sd)].value < 3 )
        send(server->sd, server->resp_cmd[resp_22].value,
        strlen(server->resp_cmd[resp_22].value), 0);
    server->f[pos](server, "none", i);
}

void manage_client_account(Server_t *server, int i)
{
    int check_mp = strcmp(server->client.cmd[0].value,
    server->client.buffer_array[0]);
    int check_id = strcmp(server->client.cmd[1].value,
    server->client.buffer_array[0]);
    char *resp_xxx = "Error cmd not valid\r\r\n";
    char *resp_connected = "Error your are connected\r\n";

    if (!check_valid_cmd(server)) {
        send(server->sd, resp_xxx, strlen(resp_xxx), 0);
        return;
    }
    if (check_mp == 0 || check_id == 0) {
        send(server->sd, resp_connected, strlen(resp_connected), 0);
        return;
    }
    manage_client_account_execute(server, i);
}
