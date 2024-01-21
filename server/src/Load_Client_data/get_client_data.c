/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

ClientData_t *get_client_data(ClientData_t *all_client, char *name, DataManage_t *data)
{
    for (int a = 0; a < data->len_client; a++) {
        if (strcmp(name, all_client[a].name) == 0)
            return &all_client[a];
    }
    dump_new_client_in_db(&data->dataClient[data->len_client], name, data);
    return get_client_data(all_client, name, data);
}