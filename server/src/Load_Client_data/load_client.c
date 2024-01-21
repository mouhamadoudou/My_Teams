/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

int set_uuid_client(char **tab, ClientData_t *clientData)
{
    char **tab_tmp = str_to_word_array(tab[1], ' ');
    clientData->uid[36] = '\0';
    sprintf(clientData->uid, "%s", tab_tmp[3]);
    free_array(tab_tmp);
    return 3;
}

void set_client_msg_help(char *str, PrivateMessageData_t *private_msg)
{
    char **tab_tmp = str_to_word_array(str, ' ');
    char *message = get_string_between_quotes(str);
    char **time = separate_strings(str);
    time[2] = add_quotes(time[2]);
    private_msg->message = malloc(sizeof(char) * (strlen(message) + 1));
    private_msg->message[strlen(message)] = '\0';
    strcpy(private_msg->message, message);
    private_msg->otherUserUid[36] = '\0';
    strcpy(private_msg->otherUserUid, tab_tmp[2]);
    private_msg->time = malloc(sizeof(char) * (strlen(time[2]) + 1));
    private_msg->time[strlen(time[2])] = '\0';
    strcpy(private_msg->time, time[2]);
    free(message);
    free_array(tab_tmp);
    free_array(time);
}

int set_client_msg(char **tab, PrivateMessageData_t *private_msg, ClientData_t *client, int tab_pos)
{
    if (check_is_is_in(tab[tab_pos], "private", 1) == 0)
        return tab_pos;
    tab_pos++;
    client->pos_msg = 0;


    for (int a = tab_pos; tab[a] != NULL; a++) {
        set_client_msg_help(tab[a], &private_msg[client->pos_msg]);
        client->pos_msg++;
        tab_pos++;
    }
    return tab_pos;
}

void load_client(ClientData_t *clientData, DataManage_t *data, char *name)
{
    int tab_pos = 0;
    clientData->name = malloc(sizeof(char) * (strlen(name) + 1));
    clientData->name[strlen(name)] = '\0';
    int len = strlen(data->path_dir_client) + strlen(name);
    clientData->path_dir_client = malloc(sizeof(char) * (len + 2));
    clientData->path_dir_client[(len + 1)] = '\0';
    sprintf(clientData->name, "%s", name);  
    sprintf(clientData->path_dir_client, "%s/%s", data->path_dir_client, name);
   
    char **tab = get_data_file(clientData->path_dir_client);
    tab_pos = set_uuid_client(tab, clientData);
    tab_pos = set_client_msg(tab, clientData->DataMessage, clientData, tab_pos);
    free_array(tab);
}

void load_all_client(ClientData_t *clientData, DataManage_t *data)
{
    data->len_client = len_folder(data->path_dir_client);
    char **client_name = get_file_names(data->path_dir_client);
    if (data->len_client == 0)
        return;
    for (int a = 0; a < data->len_client; a++) {
        load_client(&clientData[a], data, client_name[a]);
    }
    free_array(client_name);
}
