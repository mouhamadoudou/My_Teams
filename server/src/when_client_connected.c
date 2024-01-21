/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"


int is_connected(Server_t *server, DataManage_t *data, int i)
{
    int resp_22 = get_mapstr_resp_pos(server, 22);
    int pos = get_mapstr_pos(server, server->client.buffer_array[0]);
    if (server->client.pos_msg[get_map_pos(server, server->sd)].value == 2) {
        return TRUE;
    }
    if (pos == -1) {
        send(server->sd, server->resp_cmd[resp_22].value,
        strlen(server->resp_cmd[resp_22].value), 0);
        return FALSE;
    }
    if (pos != 0 && pos != 1 &&
    server->client.pos_msg[get_map_pos(server, server->sd)].value < 3 )
        send(server->sd, server->resp_cmd[resp_22].value,
        strlen(server->resp_cmd[resp_22].value), 0);
    server->f[pos](server, data, i);
    return FALSE;
}

int check_valid_cmd(Server_t *server, DataManage_t *data)
{
    UNUSED(data);
    for (int a = 0; a < 14; a++) {
        if (strcmp(server->client.cmd[a].value, server->client.buffer_array[0])
        == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

int is_login(Server_t *server, int pos)
{
    if (server->client.pos_msg[get_map_pos(server, server->client_socket[pos])].client_data == NULL)
        return FALSE;
    return TRUE;
}

void send_to_all_im_out_me(Server_t *server, DataManage_t *data, int i)
{
    int name_len = strlen(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->name);
    int uid_len = strlen(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->uid);
    int len = 15 + name_len + uid_len;
    char *str_me = malloc(sizeof(char) * (len + 1));
    str_me[len] = '\0';
    snprintf(str_me, len + 1, "USER    [%s]->%s\r\n", server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->uid,
    server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->name);
    send(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].key,
    str_me, strlen(str_me), 0);
}

void send_to_all_im_out(Server_t *server, DataManage_t *data, int i)
{
    int tmp = 0;
    int name_len = strlen(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->name);
    int uid_len = strlen(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->uid);
    int len = 32 + name_len + uid_len;
    char *str_me = malloc(sizeof(char) * (len + 1));
    str_me[len] = '\0';
    send_to_all_im_out_me(server, data, i);
    snprintf(str_me, len + 1, "Client %s logged out with login %s\r\n", server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->uid,
    server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->name);
    send(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].key,
    str_me, strlen(str_me), 0);
    for (int a = 0; a < server->max_clients; a++) {
        if (get_map_pos(server, server->client_socket[a]) == -1)
            continue;
        tmp = server->client.pos_msg[get_map_pos(server, server->client_socket[a])].key;
        if (tmp == server->client.pos_msg[get_map_pos(server, server->client_socket[i])].key)
            continue;
        if (!is_login(server, a))
            continue;
        if (tmp != 0) {
            send(server->client.pos_msg[get_map_pos(server, server->client_socket[a])].key,
            str_me, strlen(str_me), 0);
        }
        tmp = 0;
    }
    free(str_me);
}

void send_to_all_im_connected(Server_t *server, DataManage_t *data, int i)
{
    int tmp = 0;
    int name_len = strlen(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->name);
    int uid_len = strlen(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->uid);
    int len = 31 + name_len + uid_len;
    char *str_me = malloc(sizeof(char) * (len + 1));
    str_me[len] = '\0';
    snprintf(str_me, len + 1, "Client %s logged in with login %s\r\n", server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->uid,
    server->client.pos_msg[get_map_pos(server, server->client_socket[i])].client_data->name);
    send(server->client.pos_msg[get_map_pos(server, server->client_socket[i])].key,
    str_me, strlen(str_me), 0);
    for (int a = 0; a < server->max_clients; a++) {
        if (get_map_pos(server, server->client_socket[a]) == -1)
            continue;
        tmp = server->client.pos_msg[get_map_pos(server, server->client_socket[a])].key;
        if (tmp == server->client.pos_msg[get_map_pos(server, server->client_socket[i])].key)
            continue;
        if (!is_login(server, a))
            continue;
        if (tmp != 0) {
            send(server->client.pos_msg[get_map_pos(server, server->client_socket[a])].key,
            str_me, strlen(str_me), 0);
        }
        tmp = 0;
    }
    free(str_me);
}

void manage_client_account_execute(Server_t *server, DataManage_t *data, int i)
{
    int resp_22 = get_mapstr_resp_pos(server, 22);
    int pos = get_mapstr_pos(server, server->client.buffer_array[0]);
    char *resp_connected = "Error your are connected\r\n";

    if (pos == -1)
        send(server->sd, server->resp_cmd[resp_22].value,
        strlen(server->resp_cmd[resp_22].value), 0);
    if (pos != 0 && server->client.pos_msg[get_map_pos(server, server->sd)].value == 2 ) {
        // send(server->sd, server->resp_cmd[resp_22].value,
        // strlen(server->resp_cmd[resp_22].value), 0);
        // printf("yiiiieg\n");
        //printf("in out off connexion == %d\n", i);
          //  printf("===%s===\n", server->client.pos_msg[get_map_pos(server, i)].client_data->uid);

        server->f[pos](server, data, i);
    } else {
        send(server->sd, resp_connected, strlen(resp_connected), 0);
    }
}

void manage_client_account(Server_t *server, DataManage_t *data, int i)
{
    char *resp_xxx = "Error cmd not valid\r\r\n";

    if (!check_valid_cmd(server, data)) {
        send(server->sd, resp_xxx, strlen(resp_xxx), 0);
        return;
    }
    manage_client_account_execute(server, data, i);
}
