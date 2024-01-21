/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

int dump_data_channel_message(PublicMessageData_t *dataMessage, char **tab, int tab_len)
{
    int len_tmp = 0;
    tab[tab_len] = malloc(sizeof(char) * (strlen("-* msg =") + 1));
    tab[tab_len][strlen("-* msg =")] = '\0';
    sprintf(tab[tab_len], "-* msg =");
    tab_len++;
    if (dataMessage[0].message == NULL)
        return tab_len;
    for (int a = 0; dataMessage[a].message != NULL; a++) {
        len_tmp = (strlen(dataMessage[a].message)
        + strlen(dataMessage[a].UserSendUid)
        + strlen(dataMessage[a].time) + 8);
        tab[tab_len] = malloc(sizeof(char) * (len_tmp + 1));
        tab[tab_len][len_tmp] = '\0';
        sprintf(tab[tab_len], "--- \"%s\" %s %s", dataMessage[a].message,
        dataMessage[a].UserSendUid, dataMessage[a].time);
        tab_len++;
    }
    return tab_len;
}

int dump_data_thread_message(PublicMessageData_t *dataMessage, char **tab, int tab_len)
{
    int len_tmp = 0;
    tab[tab_len] = malloc(sizeof(char) * (strlen("--@ msg =") + 1));
    tab[tab_len][strlen("--@ msg =")] = '\0';
    sprintf(tab[tab_len], "--@ msg =");
    tab_len++;
    if (dataMessage[0].message == NULL)
        return tab_len;
    for (int a = 0; dataMessage[a].message != NULL; a++) {
        len_tmp = (strlen(dataMessage[a].message)
        + strlen(dataMessage[a].UserSendUid)
        + strlen(dataMessage[a].time) + 8);
        tab[tab_len] = malloc(sizeof(char) * (len_tmp + 1));
        tab[tab_len][len_tmp] = '\0';
        sprintf(tab[tab_len], "-- \"%s\" %s %s", dataMessage[a].message,
        dataMessage[a].UserSendUid, dataMessage[a].time);
        tab_len++;
    }
    return tab_len;
}

int dump_data_channel_thread(Thread_t *thread, char **tab, int tab_pos)
{
    if (thread[0].name == NULL)
        return tab_pos;
 
    for (int a = 0; thread[a].name != NULL; a++) {
        tab[tab_pos] = malloc(sizeof(char) * (strlen("-* thread =") + 1));
        tab[tab_pos][strlen("-* thread =")] = '\0';
        sprintf(tab[tab_pos], "-* thread =");
        tab_pos++;
        tab[tab_pos] = malloc(sizeof(char) * (strlen(thread[a].name) + 12));
        tab[tab_pos][strlen(thread[a].name) + 11] = '\0';
        tab[tab_pos + 1] = malloc(sizeof(char) * (strlen(thread[a].uid) + 12));
        tab[tab_pos + 1][strlen(thread[a].uid) + 11] = '\0';
        sprintf(tab[tab_pos], "--@ name = %s", thread[a].name);
        sprintf(tab[tab_pos + 1], "--@ uuid = %s", thread[a].uid);
        tab_pos = tab_pos + 2;
        tab_pos = dump_data_thread_message(thread[a].DataMessage, tab, tab_pos);
    }
    return tab_pos;
}

int dump_channel(ChannelData_t *channel, char **tab, int tab_pos)
{
    if (channel[0].name == NULL)
        return tab_pos;
 
    for (int a = 0; channel[a].name != NULL; a++) {
        tab[tab_pos] = malloc(sizeof(char) * (strlen("# channel =") + 1));
        tab[tab_pos][strlen("# channel =")] = '\0';
        sprintf(tab[tab_pos], "# channel =");
        tab_pos++;
        tab[tab_pos] = malloc(sizeof(char) * (strlen(channel[a].name) + 11));
        tab[tab_pos][strlen(channel[a].name) + 10] = '\0';
        tab[tab_pos + 1] = malloc(sizeof(char) * (strlen(channel[a].uid) + 11));
        tab[tab_pos + 1][strlen(channel[a].uid) + 10] = '\0';
        sprintf(tab[tab_pos], "-* name = %s", channel[a].name);
        sprintf(tab[tab_pos + 1], "-* uuid = %s", channel[a].uid);
        tab_pos = tab_pos + 2;
        tab_pos = dump_data_channel_message(channel[a].DataMessage, tab, tab_pos);
        tab_pos = dump_data_channel_thread(channel[a].thread, tab, tab_pos);
    }
    return tab_pos;
}

void dump_data_team(TeamData_t *dataTeam)
{
    int len = 4 + get_len_team(dataTeam);
    int tab_pos = 3;
    char **tab = malloc(sizeof(char*) * (len + 1));
    if (tab == NULL)
        exit(84);
    tab[len] = NULL;
    tab[0] = malloc(sizeof(char) * (strlen(dataTeam->name) + 11));
    tab[0][strlen(dataTeam->name) + 10] = '\0';
    tab[1] = malloc(sizeof(char) * (strlen(dataTeam->uid) + 11));
    tab[1][strlen(dataTeam->uid) + 10] = '\0';
    tab[2] = malloc(sizeof(char) * (strlen(dataTeam->path_dir_team) + 10));
    tab[2][strlen(dataTeam->path_dir_team) + 9] = '\0';
    sprintf(tab[0], "# name = %s", dataTeam->name);
    sprintf(tab[1], "# uuid = %s", dataTeam->uid);
    sprintf(tab[2], "# path = %s", dataTeam->path_dir_team);    
    tab_pos = dump_members(dataTeam->teamMembers, tab, tab_pos);
    tab_pos = dump_channel(dataTeam->channel, tab, tab_pos);
    write_string_to_file(dataTeam->path_dir_team, tab);
    free_array(tab);
}