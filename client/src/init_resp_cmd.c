/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "my.h"

void init_resp_key(Server_t *server)
{
    server->resp_cmd[0].key = 331;
    server->resp_cmd[1].key = 230;
    server->resp_cmd[2].key = 120;
    server->resp_cmd[3].key = 125;
    server->resp_cmd[4].key = 150;
    server->resp_cmd[5].key = 200;
    server->resp_cmd[6].key = 214;
    server->resp_cmd[7].key = 220;
    server->resp_cmd[8].key = 221;
    server->resp_cmd[9].key = 226;
    server->resp_cmd[10].key = 227;
    server->resp_cmd[11].key = 230;
    server->resp_cmd[12].key = 250;
    server->resp_cmd[13].key = 257;
    server->resp_cmd[14].key = 331;
    server->resp_cmd[15].key = 332;
    server->resp_cmd[16].key = 22;
    server->resp_cmd[17].key = FALSE;
}

char *my_strcpy(char *dest, char *src)
{
    int len = strlen(src);
    dest = malloc(sizeof(char) * (len + 1));
    check_malloc(dest);

    for (int a = 0; src[a] != '\0'; a++) {
        dest[a] = src[a];
        dest[a + 1] = '\0';
    }
    return dest;
}

void init_resp_value_help(Server_t *server)
{
    server->resp_cmd[11].value = my_strcpy(server->resp_cmd[11].value,
    "230\r\n");
    server->resp_cmd[12].value = my_strcpy(server->resp_cmd[12].value,
    "250\r\n");
    server->resp_cmd[13].value = my_strcpy(server->resp_cmd[13].value,
    "257\r\n");
    server->resp_cmd[14].value = my_strcpy(server->resp_cmd[14].value,
    "331\r\n");
    server->resp_cmd[15].value = my_strcpy(server->resp_cmd[15].value,
    "332\r\n");
    server->resp_cmd[16].value = my_strcpy(server->resp_cmd[16].value,
    "Not connected \r\n");
    server->resp_cmd[17].value = my_strcpy(server->resp_cmd[16].value,
    "False\r\n");
}

void init_resp_value(Server_t *server)
{
    server->resp_cmd[0].value = my_strcpy(server->resp_cmd[0].value, "331\r\n");
    server->resp_cmd[1].value = my_strcpy(server->resp_cmd[1].value, "230\r\n");
    server->resp_cmd[2].value = my_strcpy(server->resp_cmd[2].value, "120\r\n");
    server->resp_cmd[3].value = my_strcpy(server->resp_cmd[3].value, "125\r\n");
    server->resp_cmd[4].value = my_strcpy(server->resp_cmd[4].value, "150\r\n");
    server->resp_cmd[5].value = my_strcpy(server->resp_cmd[5].value, "200\r\n");
    server->resp_cmd[6].value = my_strcpy(server->resp_cmd[6].value, "214\r\n");
    server->resp_cmd[7].value = my_strcpy(server->resp_cmd[7].value, "220\r\n");
    server->resp_cmd[8].value = my_strcpy(server->resp_cmd[8].value, "221\r\n");
    server->resp_cmd[9].value = my_strcpy(server->resp_cmd[9].value, "226\r\n");
    server->resp_cmd[10].value = my_strcpy(server->resp_cmd[10].value,
    "227\r\n");
    init_resp_value_help(server);
}

void init_resp(Server_t *server)
{
    init_resp_key(server);
    init_resp_value(server);
}
