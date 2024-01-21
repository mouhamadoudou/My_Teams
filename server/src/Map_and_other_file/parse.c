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

char* strtrim(char* str)
{
    char* end;
    while (*str == ' ' || *str == '\t' || *str == '\n') str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t' || *end == '\n')) end--;
    *(end + 1) = 0;
    return str;
}

char** separate_strings(char* input)
{
    char** result = NULL;
    char* token;
    int count = 0;
    token = strtok(input, "\"");
    while (token != NULL) {
        count++;
        result = realloc(result, count * sizeof(char*));
        result[count - 1] = strdup(strtrim(token));
        token = strtok(NULL, "\"");
    }
    count++;
    result = realloc(result, count * sizeof(char*));
    result[count - 1] = NULL;

    return result;
}

char* add_quotes(char* input)
{
    int input_len = strlen(input);
    char* output = malloc((input_len + 3) * sizeof(char));
    output[0] = '\"';
    strcpy(&output[1], input);
    output[input_len + 1] = '\"'; 
    output[input_len + 2] = '\0';
    return output;
}

void parse(Server_t *server)
{
    strtok(server->client.buffer, "\r");
    // char **tmp = str_to_word_array(server->client.buffer, ' ');
    // if (tmp[1] != NULL)
       // printf("-%s-\n", server->client.buffer);

            server->client.buffer_array = separate_strings(server->client.buffer);
    // else

    if (server->client.buffer_array[2] != NULL) {
        free(server->client.buffer_array[2]);
        server->client.buffer_array[2] = malloc(sizeof(char) * (strlen(server->client.buffer_array[3]) + 1));
        server->client.buffer_array[2][strlen(server->client.buffer_array[3])] = '\0';
        strcpy(server->client.buffer_array[2], server->client.buffer_array[3]);
        free(server->client.buffer_array[3]);
        server->client.buffer_array[3] = NULL;
    //    printf("-%s-\n", server->client.buffer_array[2]);
    }
    // if (server->client.buffer_array[1] != NULL)
    //     server->client.buffer_array[1] =
    //     delete_char(server->client.buffer_array[1]);
}
