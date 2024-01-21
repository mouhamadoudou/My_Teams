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
#include <uuid.h>

typedef struct privateMessageData_T {
    char otherUserUid[37];
    char *time;
    char *message;
} PrivateMessageData_t;

typedef struct publicMessageData_T {
    char UserSendUid[37];
    char *time;
    char *message;
    int pos;
} PublicMessageData_t;


typedef struct clientData_T { 
    char *name;
    char uid[37];
    char **context; // im not sure it will be char *
    int status; /// bool
    PrivateMessageData_t DataMessage[100];
    int pos_msg;
    char *path_dir_client;
} ClientData_t;

typedef struct memberData_T { 
    int pos;
    char *name;
    char uid[37];
    int isSubscribe; // un boool de base est definit a false 
} MemberData_t;

typedef struct thread_T {
    int pos;
    char *name;
    char uid[37];
    PublicMessageData_t DataMessage[100];
} Thread_t;

typedef struct channelData_T { 
    char *name;
    char uid[37];
    PublicMessageData_t DataMessage[100];
    int pos;
    Thread_t thread[30];
   // char *context; // im not sure it will be char *
} ChannelData_t;

typedef struct teamData_T { 
    char *name;
    char uid[37];
   //// char *context; // im not sure it will be char *
    ChannelData_t channel[30];
    MemberData_t teamMembers[30];
    char *path_dir_team;
} TeamData_t;

typedef struct dataManage_T {
    ClientData_t dataClient[30];
    int len_client;
    TeamData_t team[30];
    int len_team;
    char *path_dir_client;
    char *path_dir_team;
} DataManage_t;

//FUNCTION FOR SAVE AND COMMUNICATE WITH DATA FOLDER
void create_file_with_string(char* string);
int get_file_size(char *filepath);
char *get_content_file(char *filepath);
void create_file_in_directory(char* file_name, char *path);
int check_if_file_exists(char* directory, char* str);
void write_string_to_file(char* file_path, char** data);
int len_folder(const char* path);
char** get_file_names(const char* path);
char** get_data_file(const char* path);
char* get_string_between_quotes(const char* str);


//init data
void init_manage_data(DataManage_t *data);

//dump client 
void dump_data_client(ClientData_t *dataClient);

//dump new client 
void dump_new_client_in_db(ClientData_t *dataClient, char *name, DataManage_t *data);

//dump team
void set_all_name_null(TeamData_t *dataTeam);
int get_len_team(TeamData_t *dataTeam);
int dump_members(MemberData_t *teamMembers, char **tab, int tab_pos);
int dump_data_channel_message(PublicMessageData_t *dataMessage, char **tab, int tab_len);
int dump_data_thread_message(PublicMessageData_t *dataMessage, char **tab, int tab_len);
int dump_data_channel_thread(Thread_t *thread, char **tab, int tab_pos);
int dump_channel(ChannelData_t *channel, char **tab, int tab_pos);
void dump_data_team(TeamData_t *dataTeam);
void dump_new_team_in_db_help(TeamData_t *dataTeam, char *name, DataManage_t *data);
void dump_new_team_in_db(TeamData_t *dataTeam, char *name, DataManage_t *data);

//Load client 
int set_uuid_client(char **tab, ClientData_t *clientData);
void set_client_msg_help(char *str, PrivateMessageData_t *private_msg);
int set_client_msg(char **tab, PrivateMessageData_t *private_msg, ClientData_t *client, int tab_pos);
void load_client(ClientData_t *clientData, DataManage_t *data, char *name);
void load_all_client(ClientData_t *clientData, DataManage_t *data);
ClientData_t *get_client_data(ClientData_t *all_client, char *name, DataManage_t *data);
char** separate_strings(char* input);
char* add_quotes(char* input);

//Load teams
int set_uuid_team(char **tab, TeamData_t *team);
void set_member_help(char *str, MemberData_t *teamMembers);
int set_member(char **tab, MemberData_t *teamMembers, int tab_pos);
int set_channel_name_uuid(char **tab, int a, ChannelData_t *channel);
void set_channel_msg_help(char *str, PublicMessageData_t *msg);
int set_channel_msg (char **tab, int tab_pos, PublicMessageData_t *msg);
int set_thread_name_uuid(char **tab, int a, Thread_t *thread);
void set_thread_msg_help(char *str, PublicMessageData_t *msg);
int set_thread_msg (char **tab, int tab_pos, PublicMessageData_t *msg);
int set_channel_thread(char **tab, Thread_t *thread, int tab_pos);
int set_channel(char **tab, ChannelData_t *channel, int tab_pos);
void load_team(TeamData_t *team, DataManage_t *data, char *name);
void load_all_teams(TeamData_t *team, DataManage_t *data);
int check_is_is_in(char *str, char *comp, int pos);