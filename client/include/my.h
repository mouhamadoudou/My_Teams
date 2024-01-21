/*
** EPITECH PROJECT, 2023
** str_to_word_array.c
** File description:
** str_to_word_array
*/

#pragma once

#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/time.h>


#define TRUE 1
#define FALSE 0

typedef struct map_T {
    int key;
    int value;
} Map_t;

typedef struct mapStr_T {
    int key;
    char *value;
} MapStr_t;

typedef struct client_T {
    char buffer[1000];
    char **buffer_array;
    Map_t pos_msg[10];
    MapStr_t cmd[14];
    int max_cmd;
    int activity;
    int valread;
    int id_mp;
} Client_t;

typedef struct directory_T {
    char *path;
} Directory_t;

typedef struct mapDirectory_T {
    int key;
    Directory_t value;
} MapDirectory_T;

typedef struct Server_t {
    struct sockaddr_in address;
    fd_set readfds;
    int master_socket;
    int client_socket[10];
    int addrlen;
    int new_socket;
    int max_clients;
    int sd;
    int max_sd;
    int PORT;
    void (*f[14]) (struct Server_t *, char *, int);
    MapStr_t resp_cmd[18];
    Client_t client;
    Directory_t arg_directory;
    MapDirectory_T client_directory[10];
} Server_t;

char *concat_path(Server_t *server, char *cmd);
int is_connected(Server_t *server, char *id_mp, int i);
int check_valid_cmd(Server_t *server);
void manage_client_account_execute(Server_t *server, int i);
void manage_client_account(Server_t *server, int i);
void cwd_cmd(Server_t *server, char *none, int i);
void init_directory(Server_t *server, char *path);
void check_malloc(char *test);
char *my_strcpy(char *dest, char *src);
void init_resp(Server_t *server);
int get_mapstr_resp_pos(Server_t *server, int key);
char **str_to_word_array(char *str, char separator);
void init_cmd(Server_t *server);
int get_mapstr_pos(Server_t *server, char *value);
void quit_cmd(Server_t *server, char *none, int i);
void check_identifier(Server_t *server, char *id_mp, int i);
void check_password(Server_t *server, char *id_mp, int i);
void add_file_descriptor_in_readfds(Server_t *server);
void check_accept_add_to_list(Server_t *server);
int error_manage(int ac, char **av, Server_t *server);
void parse(Server_t *server);
int get_map_pos(Server_t *server, int key);
void init_default_value(Server_t *server);
void init_server(Server_t *server);
void init_client_socket(Server_t *server);
void init_master_socket_and_adress(Server_t *server);
