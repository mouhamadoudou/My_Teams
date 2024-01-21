/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void helper(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens\n");
    printf("\tpath is the path to the home directory for the Anonymous user\n");
}

void call_helper(void)
{
    printf("Please try: ./myftp -h\n");
}

int get_if_is_in(char comp, char *list)
{
    for (int a = 0; list[a] != '\0'; a++) {
        if (list[a] == comp)
            return TRUE;
    }
    return FALSE;
}

int get_if_number(char *str)
{
    char *number = "-1234567890";

    for (int a = 0; str[a] != '\0'; a++) {
        if (!get_if_is_in(str[a], number))
            return FALSE;
    }
    return TRUE;
}

int error_manage(int ac, char **av, Server_t *server)
{
    if (ac == 2 && strcmp(av[1], "-h") == FALSE) {
        helper();
        exit(84);
    }
    if (ac != 3) {
        call_helper();
        exit(84);
    }
    if (!get_if_number(av[1])) {
        call_helper();
        exit(84);
    }
    server->PORT = atoi(av[1]);
    return TRUE;
}
