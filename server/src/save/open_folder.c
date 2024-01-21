/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include <dirent.h>
#include <fcntl.h>

int ending_file_reading(ssize_t res_read)
{
    if (res_read < 0) {
        printf("Read Failed\n");
        return -1;
    } else if (res_read == 0) {
        printf("File's empty\n");
        return -1;
    } else
        return res_read;
}

int get_file_size(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int res_read;
    char *buffer;

    if (fd < 0) {
        printf("Open failed, file doesn't exist\n");
        close(fd);
        return -1;
    } else {
        buffer = malloc(sizeof(char) * 30000);
        res_read = read(fd, buffer, 30000);
        free(buffer);
        close(fd);
        return ending_file_reading(res_read);
    }
}

char *get_content_file(char *filepath)
{
    char *content_file;
    int file_size = get_file_size(filepath);
    int fd = open(filepath, O_RDONLY);

    if (file_size != -1) {
        content_file = malloc(sizeof(char) * file_size + 1);
        content_file[file_size] = '\0';
        read(fd, content_file, file_size);
    } else
        return NULL;
    close(fd);
    printf("%s\n", content_file);
    return content_file;
}

int len_folder(const char* path)
{
    int len = 0;
    DIR* dir = opendir(path);
    if (dir != NULL) {
        struct dirent* direct;
        while ((direct = readdir(dir)) != NULL) {
            if (direct->d_type == DT_REG) {
                len++;
            }
        }
        closedir(dir);
    }
    return len;
}
