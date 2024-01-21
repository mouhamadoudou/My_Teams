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
#include "../../libs/myteams/logging_server.h"
#include <uuid.h>
#include "save_data.h"

#define UNUSED(x) (void)(x)
#define TRUE 1
#define FALSE 0

typedef struct map_T {
    int key;
    int value;
    ClientData_t *client_data;
} Map_t;

typedef struct mapStr_T {
    int key;
    char *value;
} MapStr_t;

typedef struct client_T {
    char buffer[1000];
    char **buffer_array;
    Map_t pos_msg[30];
    MapStr_t cmd[14];
    
    int max_cmd;
    int activity;
    int valread;
    
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
    int client_socket[30];
    int addrlen;
    int new_socket;
    int max_clients;
    int sd;
    int max_sd;
    int PORT;
    void (*f[14]) (struct Server_t *, DataManage_t *, int);
    MapStr_t resp_cmd[18];
    Client_t client;
    Directory_t arg_directory;
    MapDirectory_T client_directory[30];
} Server_t;


//manage connexion 
void manage_client(Server_t *server, DataManage_t *data);

// manage commande
void commande_manage(Server_t *server, DataManage_t *data, int i);

//basic function
int error_manage(int ac, char **av, Server_t *server);
void parse(Server_t *server);
char **str_to_word_array(char *str, char separator);
char *my_strcpy(char *dest, char *src);
char *concat_path(Server_t *server, char *cmd);
void free_array(char **tab);
void current_time(char **str);

//function check
void check_malloc(char *test);
int check_valid_cmd(Server_t *server, DataManage_t *data);
void check_accept_add_to_list(Server_t *server, DataManage_t *data);
int is_connected(Server_t *server, DataManage_t *data, int i);

//manage client 
void manage_client_account_execute(Server_t *server, DataManage_t *data, int i);
void manage_client_account(Server_t *server, DataManage_t *data, int i);
void add_file_descriptor_in_readfds(Server_t *server, DataManage_t *data);

//function for manip map
int get_mapstr_pos(Server_t *server, char *value);
int get_mapstr_resp_pos(Server_t *server, int key);
int get_map_pos(Server_t *server, int key);

//init server
void init_default_value_server(Server_t *server);
void init_server(Server_t *server, DataManage_t *data);
void init_client_socket(Server_t *server, DataManage_t *data);
void init_master_socket_and_adress(Server_t *server);
void init_directory(Server_t *server, char *path);
void init_resp(Server_t *server);
void init_cmd(Server_t *server, DataManage_t *data);

//when client connected
void send_to_all_im_connected(Server_t *server, DataManage_t *data, int i);
void send_to_all_im_out(Server_t *server, DataManage_t *data, int i);

//command 
void quit_cmd(Server_t *server, DataManage_t *data, int i);
void check_identifier(Server_t *server, DataManage_t *data, int i);
void send_cmd(Server_t *server, DataManage_t *data, int i);
void users_cmd(Server_t *server, DataManage_t *data, int i);