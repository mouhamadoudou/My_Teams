/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

char *concat_path(Server_t *server, char *cmd)
{
    char *tmp_concat = malloc(sizeof(char)
    *(strlen(server->arg_directory.path) + strlen(cmd) + 1));
    tmp_concat[(strlen(server->arg_directory.path) + strlen(cmd) + 1)] = '\0';
    strcpy(tmp_concat, server->arg_directory.path);
    strcat(tmp_concat, cmd);
    return tmp_concat;
}

void check_malloc(char *test)
{
    if (test == NULL)
        exit(84);
}

char *delete_char(char *str)
{
    int len = strlen(str);
    int a = 0;

    for (int i = 0; i < len; i++) {
        if (str[i] != '\"') {
            str[a++] = str[i];
        }
    }
    str[a] = '\0';
    return str;
}

void parse(Server_t *server)
{
    strtok(server->client.buffer, "\r");
    server->client.buffer_array = str_to_word_array(server->client.buffer, ' ');
    if (server->client.buffer_array[1] != NULL)
        server->client.buffer_array[1] =
        delete_char(server->client.buffer_array[1]);
}
