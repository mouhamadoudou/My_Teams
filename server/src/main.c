/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

int main(int ac, char **av)
{
    Server_t *server = malloc(sizeof(Server_t));
    DataManage_t *data = malloc(sizeof(DataManage_t));
    if (server == NULL || data == NULL)
        exit(84);
    init_manage_data(data);

    if (server == NULL)
        exit(84);
    error_manage(ac, av, server);
    init_server(server, data);
    load_all_teams(data->team, data);
    load_all_client(data->dataClient, data);
    init_directory(server, av[2]);
    manage_client(server, data);
    free(server);
    free(data);
    return 0;
}
