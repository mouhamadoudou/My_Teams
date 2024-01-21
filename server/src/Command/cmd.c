/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void current_time(char **str)
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    asprintf(str, "\"%02d:%02d:%02d le %02d/%02d/%d\"",
    t->tm_hour, t->tm_min, t->tm_sec, t->tm_mday, t->tm_mon + 1, t->tm_year + 1900);
}

void send_cmd_set_msg_client(Server_t *server, ClientData_t *client, int i)
{
    int len = 0;
    client->DataMessage[client->pos_msg].message = malloc(sizeof(char) * (strlen(server->client.buffer_array[2]) + 1));
    client->DataMessage[client->pos_msg].message[len] = '\0';
    strcpy(client->DataMessage[client->pos_msg].message, server->client.buffer_array[2]);

    client->DataMessage[client->pos_msg].otherUserUid[36] = '\0'; 
    strcpy(client->DataMessage[client->pos_msg].otherUserUid, server->client.buffer_array[1]);

    current_time(&client->DataMessage[client->pos_msg].time);    
    dump_data_client(client);
    client->pos_msg++;
}

ClientData_t *find_client_with_uid(ClientData_t *all_client, DataManage_t *data, char *uid)
{
    for (int a = 0; a < data->len_client; a++) {
        if (strcmp(all_client[a].uid, uid) == 0)
            return &all_client[a];
    }
    return NULL;
}

void send_cmd_set_msg_other_client(Server_t *server, ClientData_t *client, int i, char *uid)
{
    int len = 0;

    client->DataMessage[client->pos_msg].message = malloc(sizeof(char) *
    (strlen(server->client.buffer_array[2]) + 1));
    client->DataMessage[client->pos_msg].message[len] = '\0';
    strcpy(client->DataMessage[client->pos_msg].message, server->client.buffer_array[2]);

    client->DataMessage[client->pos_msg].otherUserUid[36] = '\0'; 
    strcpy(client->DataMessage[client->pos_msg].otherUserUid, uid);

    current_time(&client->DataMessage[client->pos_msg].time);
    dump_data_client(client);
    client->pos_msg++;
}

int send_msg_with_uid(Map_t *pos_msg, DataManage_t *data, Server_t *server, char *uid)
{
    int len = (31 + strlen(server->client.pos_msg[get_map_pos(server, server->sd)].client_data->uid) + strlen(server->client.buffer_array[2]));
    char *tmp = malloc(sizeof(char) * (len + 1));
    tmp[len] = '\0';
    sprintf(tmp, "New private message from %s: [%s]\r\n", server->client.pos_msg[get_map_pos(server, server->sd)].client_data->uid, server->client.buffer_array[2]);
    for (int a = 1; a < 10; a++) { 
     //   printf("pos == %d\n", a);
        if (server->client.pos_msg[get_map_pos(server, a)].key != -1 &&
         server->client.pos_msg[get_map_pos(server, a)].client_data != NULL)
            if (strcmp(server->client.pos_msg[get_map_pos(server, a)].client_data->uid, uid) == 0) {
            //    printf("youpii == %s\n", server->client.pos_msg[get_map_pos(server, a)].client_data->name);
                send(server->client.pos_msg[get_map_pos(server, a)].key, tmp, strlen(tmp), 0);
            }
    }
    return 0;
}

void send_cmd(Server_t *server, DataManage_t *data, int i)
{
    if (server->client.buffer_array[1] == NULL && server->client.buffer_array[2] == NULL)
        return;
    ClientData_t *tmp_other_client = find_client_with_uid(data->dataClient, data, server->client.buffer_array[1]);
    // printf("pos sd == %d\n", server->client.pos_msg[get_map_pos(server, server->sd)].client_data->pos_msg);
    // printf("sd == %d", server->sd);
    send_cmd_set_msg_client(server, server->client.pos_msg[get_map_pos(server, server->sd)].client_data, i);
   
   // printf("--%s--\n", tmp_other_client->name);
    send_cmd_set_msg_other_client(server, tmp_other_client, i,
    server->client.pos_msg[get_map_pos(server, server->sd)].client_data->uid);

    send_msg_with_uid(server->client.pos_msg, data, server, server->client.buffer_array[1]);

}
