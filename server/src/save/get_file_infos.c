/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include <dirent.h>
#include <fcntl.h>

char** get_data_file(const char* path) {
  //  printf("-%s-\n", path);
    FILE* file = fopen(path, "r");
    int buffer_size = 1000, line_pos = 0;
    char* buffer = (char*) malloc(buffer_size * sizeof(char));
    char** tab = (char**) malloc((buffer_size + 1) * sizeof(char*));
    while (fgets(buffer, buffer_size, file) != NULL) {
        tab[line_pos] = strdup(buffer);
        line_pos++;
        if (line_pos >= buffer_size) {
            buffer_size *= 2;
            char** tmp_tab = (char**) realloc(tab, (buffer_size + 1) * sizeof(char*));
            if (tmp_tab == NULL) {
                fclose(file);
                return NULL;
            }
            tab = tmp_tab;
        }
    }
    tab[line_pos] = NULL;
    fclose(file);
    free(buffer);
    return tab;
}

char* get_string_between_quotes(const char* str)
{
    char* start = strchr(str, '"');
    if (start == NULL)
        return NULL;
    start++;
    char* end = strchr(start, '"');
    if (end == NULL)
        return NULL;
    int len = end - start;
    char* result = (char*) malloc((len + 1) * sizeof(char));
    if (result == NULL)
        return NULL;
    strncpy(result, start, len);
    result[len] = '\0';
    return result;
}
