/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

int set_uuid_team(char **tab, TeamData_t *team)
{
    char **tab_tmp = str_to_word_array(tab[1], ' ');
    team->uid[36] = '\0';
    sprintf(team->uid, "%s", tab_tmp[3]);
    free_array(tab_tmp);
    return 3;
}

int set_channel_name_uuid(char **tab, int a, ChannelData_t *channel)
{
    a++;
    char **tab_tmp = str_to_word_array(tab[a], ' ');
    char **tab_uuid = str_to_word_array(tab[a + 1], ' ');

    channel->name = malloc(sizeof(char) * (strlen(tab_tmp[3]) + 1));
    channel->name[strlen(tab_tmp[3])] = '\0';
    strcpy(channel->name, tab_tmp[3]);
    channel->uid[36] = '\0';
    strcpy(channel->uid, tab_uuid[3]);
    free_array(tab_tmp);
    free_array(tab_uuid);
    a = a + 2;
    return a;
}

int set_channel(char **tab, ChannelData_t *channel, int tab_pos)
{
    if (check_is_is_in(tab[tab_pos], "channel", 1) == 0)
        return tab_pos;
    channel->pos = 0;

    for (int a = tab_pos; check_is_is_in(tab[a], "channel", 1); a++) {
        a = set_channel_name_uuid(tab, a, &channel[channel->pos]);
        a = set_channel_msg(tab, a, channel[channel->pos].DataMessage);
        a = set_channel_thread(tab, channel[channel->pos].thread, a);
        break;
        tab_pos = a;
        channel->pos++;
    }
    return tab_pos;
}

void load_team(TeamData_t *team, DataManage_t *data, char *name)
{
    set_all_name_null(team);
    int tab_pos = 0;
    team->name = malloc(sizeof(char) * (strlen(name) + 1));
    team->name[strlen(name)] = '\0';
    int len = strlen(data->path_dir_team) + strlen(name);
    team->path_dir_team = malloc(sizeof(char) * (len + 2));
    team->path_dir_team[(len + 1)] = '\0';
    sprintf(team->name, "%s", name);  
    sprintf(team->path_dir_team, "%s/%s", data->path_dir_team, name);
   
    char **tab = get_data_file(team->path_dir_team);
    tab_pos = set_uuid_team(tab, team);
    tab_pos = set_member(tab, team->teamMembers, tab_pos);

    tab_pos = set_channel(tab, team->channel, tab_pos);
    free_array(tab);
}

void load_all_teams(TeamData_t *team, DataManage_t *data)
{
    data->len_team = len_folder(data->path_dir_team);
    char **team_name = get_file_names(data->path_dir_team);
    if (data->len_team == 0)
        return;
    for (int a = 0; a < data->len_team; a++) {
        load_team(&team[a], data, team_name[a]);
    }
    free_array(team_name);
}