/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"
#include "save_data.h"

void set_all_clieent_msg_null(ClientData_t *all_client, int a)
{
    for (int i = 0; i < 100; i++) {
        all_client[a].DataMessage[i].message = NULL;
    }
}

void set_all_clieent_msg_pos(ClientData_t *all_client)
{
    for (int a = 0; a < 30; a++) {
        all_client[a].name = NULL;
        all_client[a].DataMessage->message = NULL;
        set_all_clieent_msg_null(all_client, a);
        all_client[a].pos_msg = 0;
    }
}

void init_manage_data(DataManage_t *data)
{
    data->len_client = 0;
    data->len_team = 0;
    data->path_dir_client = malloc(sizeof(char) * 23);
    if (data->path_dir_client == NULL)
        exit(84);
    data->path_dir_client[22] = '\0';
    strcpy(data->path_dir_client, "src/Data_folder/Client");

    data->path_dir_team = malloc(sizeof(char) * 21);
    if (data->path_dir_team == NULL)
        exit(84);
    data->path_dir_team[20] = '\0';
    strcpy(data->path_dir_team, "src/Data_folder/Team");
    set_all_clieent_msg_pos(data->dataClient);
    load_all_teams(data->team, data);
    load_all_client(data->dataClient, data);
}
