/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

char *add_slash(char *dest, char *src)
{
    int len = strlen(src);
    dest = malloc(sizeof(char) * (len + 2));

    check_malloc(dest);
    for (int a = 0; src[a] != '\0'; a++) {
        dest[a] = src[a];
    }
    dest[len] = '/';
    dest[len + 1] = '\0';
    free(src);
    return dest;
}

int is_dir(Server_t *server)
{
    struct stat st;

    if (server->arg_directory.path == NULL)
        exit(84);
    if (stat(server->arg_directory.path, &st) == -1)
        exit(84);
    if (S_ISDIR(st.st_mode)) {
        return TRUE;
    } else
        return FALSE;
    return FALSE;
}

void as_slash(Server_t *server)
{
    char *tmp = NULL;
    if (server->arg_directory.path[strlen(server->arg_directory.path) - 1]
    != '/')
        server->arg_directory.path = add_slash(tmp, server->arg_directory.path);
}

void init_client_directroy(Server_t *server)
{
    for (int i = 0; i < server->max_clients; i++) {
        server->client_directory[i].key = i;
        server->client_directory[i].value.path =
        my_strcpy(server->client_directory[i].value.path,
        server->arg_directory.path);
    }
}

void init_directory(Server_t *server, char *path)
{
    server->arg_directory.path = my_strcpy(server->arg_directory.path, path);
    if (!is_dir(server))
        exit(84);
    as_slash(server);
    init_client_directroy(server);
    chdir(server->arg_directory.path);
}
