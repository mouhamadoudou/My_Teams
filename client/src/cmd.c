/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

int is_can_be_dir(char *test)
{
    struct stat st;

    if (test == NULL)
        return FALSE;
    if (stat(test, &st) == -1)
        return FALSE;
    if (S_ISDIR(st.st_mode)) {
        return TRUE;
    } else
        return FALSE;
    return FALSE;
}

void cwd_cmd(Server_t *server, char *none, int i)
{
    char *resp_xxx = "Error not valid directory\r\n";
    int resp_250 = get_mapstr_resp_pos(server, 250);
    char *all_right = "Directory changed\r\n";
    int pos = get_map_pos(server, server->sd);

    if (!is_can_be_dir(server->client.buffer_array[1])) {
        send(server->sd, resp_xxx, strlen(resp_xxx), 0);
        return;
    }
    free(server->client_directory[pos].value.path);
    server->client_directory[pos].value.path =
    my_strcpy(server->client_directory[pos].value.path,
        server->client.buffer_array[0]);
    chdir(server->client_directory[pos].value.path);
    send(server->sd, server->resp_cmd[resp_250].value,
        strlen(server->resp_cmd[resp_250].value), 0);
    send(server->sd, all_right, strlen(all_right), 0);

}

void cdup_cmd(Server_t *server, char *none, int i)
{
    char *resp_xxx = "Error not valid directory\r\n";
    int resp_250 = get_mapstr_resp_pos(server, 250);
    char *all_right = "Directory changed\r\n";
    int pos = get_map_pos(server, server->sd);

    chdir("..");
}

void quit_cmd(Server_t *server, char *none, int i)
{
    int resp_221 = get_mapstr_resp_pos(server, 221);
    getpeername(server->sd, (struct sockaddr *)&server->address,
        (socklen_t *)&server->addrlen);
    send(server->sd, server->resp_cmd[resp_221].value,
        strlen(server->resp_cmd[resp_221].value), 0);
    close(server->sd);
    server->client_socket[i] = 0;
    server->client.pos_msg[get_map_pos(server,
        server->client_socket[i])].key = -1;
    free(server->client_directory[i].value.path);
    server->client_directory[i].value.path =
    my_strcpy(server->client_directory[i].value.path,
    server->arg_directory.path);
}

void check_identifier(Server_t *server, char *id_mp, int i)
{
    int resp_230 = get_mapstr_resp_pos(server, 230);
    char *resp_xxx = "Error indifier not valid\r\n";
    int resp_331 = get_mapstr_resp_pos(server, 331);

    if (server->client.pos_msg[get_map_pos(server, server->sd)].value == 1) {
        if (server->client.buffer_array[1] != NULL &&
        strcmp(server->client.buffer_array[1], "Anonymous") == 0) {
            send(server->sd, server->resp_cmd[resp_230].value,
                strlen(server->resp_cmd[resp_230].value), 0);
            send(server->sd, server->resp_cmd[resp_331].value,
                strlen(server->resp_cmd[resp_331].value), 0);
            server->client.pos_msg[get_map_pos(server, server->sd)].value++;
        } else
            send(server->sd, resp_xxx, strlen(resp_xxx), 0);
    }
}
