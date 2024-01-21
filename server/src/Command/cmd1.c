/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void users_cmd(Server_t *server, DataManage_t *data, int i)
{
    int len_tmp = 0;
    char *str_tmp =  NULL;

    for (int a = 0; a < data->len_client; a++) {
        len_tmp = (15 + strlen(data->dataClient[a].name) + strlen(data->dataClient[a].uid)); 
        str_tmp = malloc(sizeof(char) * (len_tmp + 1));
        str_tmp[len_tmp] = '\0';
        snprintf(str_tmp, len_tmp + 1, "User \"%s\" (%s): %d\r\n", data->dataClient[a].name, data->dataClient[a].uid, data->dataClient[a].status);
        send(server->client.pos_msg[get_map_pos(server, server->sd)].key,
            str_tmp, strlen(str_tmp), 0);
            free(str_tmp);
        printf("--%s--\n", data->dataClient[a].name);
    }
}

void quit_cmd(Server_t *server, DataManage_t *data, int i)
{
    UNUSED(data);
    int resp_221 = get_mapstr_resp_pos(server, 221);
    getpeername(server->sd, (struct sockaddr *)&server->address,
        (socklen_t *)&server->addrlen);
    // send(server->sd, server->resp_cmd[resp_221].value,
    //     strlen(server->resp_cmd[resp_221].value), 0);
    
    printf("User %s logged out.\n", server->client.pos_msg[get_map_pos(server, server->sd)].client_data->uid);
    send_to_all_im_out(server, data, i);
    server->client_socket[i] = 0; 
    // printf("la QUIT => %d\n", server->client.pos_msg[get_map_pos(server, server->sd)].value);
    // printf("la QUIT key => %d\n", server->client.pos_msg[get_map_pos(server, server->sd)].key);

    server->client.pos_msg[get_map_pos(server, server->sd)].key = -1;
    server->client.pos_msg[get_map_pos(server, server->sd)].value = 0;
    server->client.pos_msg[get_map_pos(server, server->sd)].client_data->status = 0;
    dump_data_client(server->client.pos_msg[get_map_pos(server, server->sd)].client_data);
    server->client.pos_msg[get_map_pos(server, server->sd)].client_data = NULL;
    free(server->client_directory[i].value.path);
    server->client_directory[i].value.path =
    my_strcpy(server->client_directory[i].value.path,
    server->arg_directory.path);
    // printf("close == %d\n", server->sd);
    close(server->sd);
}

void check_identifier(Server_t *server, DataManage_t *data, int i)
{
    int resp_230 = get_mapstr_resp_pos(server, 230);
    char *resp_xxx = "Error indifier not valid\r\n";
    int resp_331 = get_mapstr_resp_pos(server, 331);
    UNUSED(data);
    //     printf("la SERVER KEY => %d\n", server->client.pos_msg[get_map_pos(server, server->sd)].key);
    // printf("la SERVER => %d\n", server->client.pos_msg[get_map_pos(server, server->sd)].value);
    if (server->client.pos_msg[get_map_pos(server, server->sd)].value == 1) {
        if (server->client.buffer_array[1] != NULL && !check_if_file_exists(data->path_dir_client, server->client.buffer_array[1]) && strcmp(server->client.buffer_array[1], "") != 0) {
            dump_new_client_in_db(&data->dataClient[data->len_client], server->client.buffer_array[1], data);
           // send(server->sd, server->resp_cmd[resp_230].value, strlen(server->resp_cmd[resp_230].value), 0);
           // send(server->sd, server->resp_cmd[resp_331].value, strlen(server->resp_cmd[resp_331].value), 0);
            server->client.pos_msg[get_map_pos(server, server->sd)].client_data = &data->dataClient[(data->len_client - 1)];
            server->client.pos_msg[get_map_pos(server, server->sd)].value++;
            server->client.pos_msg[get_map_pos(server, server->sd)].client_data->status = 1;
            send_to_all_im_connected(server, data, i);
            printf("New user: %s (%s).\n",  server->client.pos_msg[get_map_pos(server, server->sd)].client_data
            ->name,  server->client.pos_msg[get_map_pos(server, server->sd)].client_data->uid);
            printf("User %s logged in.\n", server->client.pos_msg[get_map_pos(server, server->sd)].client_data->uid);
        } else if (server->client.buffer_array[1] != NULL && strcmp(server->client.buffer_array[1], "") != 0) {
            server->client.pos_msg[get_map_pos(server, server->sd)].client_data = get_client_data(data->dataClient, server->client.buffer_array[1], data);
            server->client.pos_msg[get_map_pos(server, server->sd)].client_data->status = 1;
            // send(server->sd, server->resp_cmd[resp_230].value, strlen(server->resp_cmd[resp_230].value), 0);
            // send(server->sd, server->resp_cmd[resp_331].value, strlen(server->resp_cmd[resp_331].value), 0);
            server->client.pos_msg[get_map_pos(server, server->sd)].value++;
            send_to_all_im_connected(server, data, i);
       //     printf("--%d--\n", server->sd);
            printf("User %s logged in.\n", server->client.pos_msg[get_map_pos(server, server->sd)].client_data->uid);
        } else
            send(server->sd, resp_xxx, strlen(resp_xxx), 0);
    }
}
