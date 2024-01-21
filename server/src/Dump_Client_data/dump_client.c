/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

int lenMessage(PrivateMessageData_t *DataMessage)
{
    int result = 0;

    for (int a = 0; DataMessage[a].message != NULL; a++)
        result++;
    return result;
}

void dump_data_client_message(ClientData_t *dataClient, char **tab, int len)
{
    int i = 0;
    int len_tmp = 0;
    tab[3] = malloc(sizeof(char) * 12);
    tab[3][11] = '\0';
    sprintf(tab[3], "# private =");
    if (len < 4)
        return;
    for (int a = 4; a < len; a++) {
        len_tmp = (strlen(dataClient->DataMessage[i].message)
        + strlen(dataClient->DataMessage[i].otherUserUid)
        + strlen(dataClient->DataMessage[i].time) + 4);
        tab[a] = malloc(sizeof(char) * (len_tmp + 1));
        tab[a][len_tmp] = '\0';
        sprintf(tab[a], "\"%s\" %s %s", dataClient->DataMessage[i].message,
        dataClient->DataMessage[i].otherUserUid, dataClient->DataMessage[i].time);
        i++;
    }
}

void dump_data_client(ClientData_t *dataClient)
{
    int len = 4 + lenMessage(dataClient->DataMessage);
    char **tab = malloc(sizeof(char*) * (len + 1));
    if (tab == NULL)
        exit(84);
    tab[len] = NULL;
    tab[0] = malloc(sizeof(char) * (strlen(dataClient->name) + 11));
    tab[0][strlen(dataClient->name) + 10] = '\0';
    tab[1] = malloc(sizeof(char) * (strlen(dataClient->uid) + 11));
    tab[1][strlen(dataClient->uid) + 10] = '\0';
    tab[2] = malloc(sizeof(char) * (strlen(dataClient->path_dir_client) + 10));
    tab[2][strlen(dataClient->path_dir_client) + 9] = '\0';
    sprintf(tab[0], "# name = %s", dataClient->name);
    sprintf(tab[1], "# uuid = %s", dataClient->uid);
    sprintf(tab[2], "# path = %s", dataClient->path_dir_client);    
    dump_data_client_message(dataClient, tab, len);
    write_string_to_file(dataClient->path_dir_client, tab);
    free_array(tab);
}
