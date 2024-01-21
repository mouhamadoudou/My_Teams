/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"
#include <dirent.h>
#include <fcntl.h>

int check_if_file_exists(char* directory, char* str)
{
    DIR* dir;
    struct dirent* entry;
    int check = FALSE;

    dir = opendir(directory);
    if (dir == NULL) {
        printf("Erreur : Impossible d'ouvrir le dossier %s.\n", directory);
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && strcmp(entry->d_name, str) == 0) {
            check = TRUE;
            break;
        }
    }
    closedir(dir);
    return check;
}

void write_string_to_file(char* file_path, char** data)
{
    FILE* file;
    file = fopen(file_path, "w");

    if (file == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s en mode écriture.\n", file_path);
        exit(EXIT_FAILURE);
    }
    for (int a = 0; data[a] != NULL; a++) {
        printf("-%s-", data[a]);
        fprintf(file, "%s", data[a]);
        if (data[a + 1] != NULL)
            fprintf(file, "\n");
    }
    fclose(file);
}

void create_file_in_directory(char* file_name, char *path)
{
    FILE* file = fopen(path, "w");
    if (file_name == NULL) {
        printf("Erreur : Impossible de créer le fichier %s dans le dossier %s.\n", file_name, path);
        exit(EXIT_FAILURE);
    }
    fclose(file);
}

char **get_file_names(const char* path)
{
    DIR* dir = opendir(path);
    int file_len = len_folder(path);
    struct dirent* entry;

    char** tab = malloc(sizeof(char*) * (file_len + 1));
    tab[file_len] = NULL;
    rewinddir(dir);
    int i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            tab[i] = malloc(sizeof(char) * (strlen(entry->d_name) + 1));
            tab[i][strlen(entry->d_name)] = '\0';
            strcpy(tab[i], entry->d_name);
            i++;
        }
    }
    closedir(dir);
    return tab;
}
