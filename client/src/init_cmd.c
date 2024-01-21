/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void init_cmd_function(Server_t *server)
{
    server->f[0] = check_identifier;
    server->f[1] = quit_cmd;
    server->f[2] = quit_cmd;
    server->f[3] = cwd_cmd;
    server->f[4] = quit_cmd;
    server->f[5] = quit_cmd;
    server->f[6] = quit_cmd;
    server->f[7] = quit_cmd;
    server->f[8] = quit_cmd;
    server->f[9] = quit_cmd;
    server->f[10] = quit_cmd;
    server->f[11] = quit_cmd;
    server->f[12] = quit_cmd;
    server->f[13] = quit_cmd;
}

void init_cmd(Server_t *server)
{
    int len = 0;
    char *cmd [14] = {"USER", "PASS", "QUIT", "CWD", "CDUP",
    "DELE", "PWD", "PASV", "PORT", "HELP", "NOOP", "RETR", "STOR", "LIST"};

    init_cmd_function(server);
    for (int a = 0; a < 14; a++) {
        server->client.cmd[a].key = a;
        len = strlen(cmd[a]);
        server->client.cmd[a].value = malloc(sizeof(char) * (len + 1));
        check_malloc(server->client.cmd[a].value);
        server->client.cmd[a].value[len] = '\0';
        strcpy(server->client.cmd[a].value, cmd[a]);
    }
}
