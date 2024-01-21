/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

void dump_new_client_in_db_help(ClientData_t *dataClient, char *name, DataManage_t *data)
{
    UNUSED(data);
    UNUSED(name);

    for (int a = 0; a < 4; a++)
        dataClient->context[a] = NULL;
    for (int a = 0; a < 100; a++)
        dataClient->DataMessage[a].message = NULL;
    // create_file_in_directory(name, dataClient->path_dir_client);
    // dataClient->DataMessage[0].message = malloc(sizeof(char) * 5);
    // dataClient->DataMessage[0].message[4] = '\0';
    // sprintf(dataClient->DataMessage[0].message, "test");
    // dataClient->DataMessage[0].otherUserUid[strlen(dataClient->uid)] = '\0';
    // sprintf(dataClient->DataMessage[0].otherUserUid,"%s", dataClient->uid);
    // dataClient->DataMessage[0].time = malloc(sizeof(char) * 5);
    // dataClient->DataMessage[0].time[4] = '\0';
    // sprintf(dataClient->DataMessage[0].time, "test");

    //     dataClient->DataMessage[1].message = malloc(sizeof(char) * 5);
    // dataClient->DataMessage[1].message[4] = '\0';
    // sprintf(dataClient->DataMessage[1].message, "test");
    // dataClient->DataMessage[1].otherUserUid[strlen(dataClient->uid)] = '\0';
    // sprintf(dataClient->DataMessage[1].otherUserUid,"%s", dataClient->uid);
    // dataClient->DataMessage[1].time = malloc(sizeof(char) * 5);
    // dataClient->DataMessage[1].time[4] = '\0';
    // sprintf(dataClient->DataMessage[1].time, "test");

    dump_data_client(dataClient);
    data->len_client++;
}

void dump_new_client_in_db(ClientData_t *dataClient, char *name, DataManage_t *data)
{
    uuid_t stuuid;
    int len = strlen(name);
    dataClient->name = malloc(sizeof(char) * (len + 1));
    if (dataClient->name == NULL)
        exit(84);
    dataClient->name[len] = '\0';
    strcpy(dataClient->name, name);
    dataClient->status = FALSE;
    dataClient->path_dir_client = malloc(sizeof(char) * (strlen(data->path_dir_client) + len + 2));
    if (dataClient->path_dir_client == NULL)
        exit(84);
    dataClient->path_dir_client[strlen(data->path_dir_client) + len + 1] = '\0';
    sprintf(dataClient->path_dir_client, "%s/%s", data->path_dir_client, dataClient->name);
    uuid_generate(stuuid);
    uuid_unparse_lower(stuuid, dataClient->uid);
    dataClient->uid[36] = '\0';
    dataClient->context = malloc(sizeof(char *) * 4);
    if (dataClient->context == NULL)
        exit(84);
    dump_new_client_in_db_help(dataClient,name, data);
}
