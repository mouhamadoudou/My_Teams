/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"

void set_all_name_null(TeamData_t *dataTeam)
{
    dataTeam->name = NULL;
    for (int a = 0; a < 30; a++) {
        dataTeam->channel[a].name = NULL;
        for (int i = 0; i < 30 ; i++) {
            dataTeam->channel[a].thread[i].name = NULL;
            for (int j = 0; j < 100; j++)
                dataTeam->channel[a].thread[i].DataMessage[j].message = NULL;
        }
        for (int i = 0; i < 100; i++)
            dataTeam->channel[a].DataMessage[i].message = NULL;
    }
    for (int a = 0; a < 30; a++)
        dataTeam->teamMembers[a].name = NULL;
}

int get_len_team(TeamData_t *dataTeam)
{
    int len = 0;
    int nb_channel = 1;
    for (int a = 0; dataTeam->channel[a].name != NULL; a++) {
        len = len + 4;
        nb_channel++;
        for (int i = 0; dataTeam->channel[a].thread[i].name != NULL; i++) {
            for (int j = 0; dataTeam->channel[a].thread[i].DataMessage[j].message != NULL; j++) {
                len++;
            }
         len = len + 4;

        }
        for (int i = 0; dataTeam->channel[a].DataMessage[i].message != NULL; i++) {
            len++;
        }
    }
    for (int a = 0; dataTeam->teamMembers[a].name != NULL; a++) {
        len++;
    }
    return len;
}

int dump_members(MemberData_t *teamMembers, char **tab, int tab_pos)
{
    int len_tmp = 0;
    tab[tab_pos] = malloc(sizeof(char) * (strlen("# teamMemebers =") + 1));
    tab[tab_pos][strlen("# teamMemebers =")] = '\0';
    sprintf(tab[tab_pos], "# teamMemebers =");
    tab_pos++;
    if (teamMembers[0].name == NULL)
        return tab_pos;
    for (int a = 0; teamMembers[a].name != NULL; a++) {
        len_tmp = (strlen(teamMembers[a].name) + strlen(teamMembers[a].uid) + 5);
        tab[tab_pos] = malloc(sizeof(char) * (len_tmp + 1));
        tab[tab_pos][len_tmp] = '\0';
        sprintf(tab[tab_pos], "- %s %s %d", teamMembers[a].name,
        teamMembers[a].uid, teamMembers[a].isSubscribe);
        tab_pos++;
    }
    return tab_pos;
}

void dump_new_team_in_db_help(TeamData_t *dataTeam, char *name, DataManage_t *data)
{
    // dataTeam->channel->thread[0].name = malloc(sizeof(char) * 6);
    // dataTeam->channel->thread[0].name[5] = '\0';
    // strcpy(dataTeam->channel->thread[0].name, "tests");
    // dataTeam->channel->thread[0].uid[36] = '\0';
    // strcpy(dataTeam->channel->thread[0].uid, dataTeam->uid);
    
    // dataTeam->channel[0].thread[0].DataMessage[0].message = malloc(sizeof(char) * 5);
    // dataTeam->channel[0].thread[0].DataMessage[0].message[4] = '\0';
    // sprintf(dataTeam->channel[0].thread[0].DataMessage[0].message, "test");
    // dataTeam->channel[0].thread[0].DataMessage->UserSendUid[strlen(dataTeam->channel->thread[0].uid)] = '\0';
    // sprintf(dataTeam->channel[0].thread[0].DataMessage->UserSendUid,"%s", dataTeam->channel->thread[0].uid);
    // dataTeam->channel[0].thread[0].DataMessage->time = malloc(sizeof(char) * 5);
    // dataTeam->channel[0].thread[0].DataMessage->time[4] = '\0';
    // sprintf(dataTeam->channel[0].thread[0].DataMessage->time, "test");




    // dataTeam->channel[0].name = malloc(sizeof(char) * 6);
    // dataTeam->channel[0].name[5] = '\0';
    // strcpy(dataTeam->channel[0].name, "tests");
    // dataTeam->channel[0].uid[36] = '\0';
    // strcpy(dataTeam->channel[0].uid, dataTeam->uid);
    
    // dataTeam->channel[0].DataMessage[0].message = malloc(sizeof(char) * 5);
    // dataTeam->channel[0].DataMessage[0].message[4] = '\0';
    // sprintf(dataTeam->channel[0].DataMessage[0].message, "test");
    // dataTeam->channel[0].DataMessage[0].UserSendUid[strlen(dataTeam->channel[0].uid)] = '\0';
    // sprintf(dataTeam->channel[0].DataMessage[0].UserSendUid,"%s", dataTeam->channel[0].uid);
    // dataTeam->channel[0].DataMessage[0].time = malloc(sizeof(char) * 5);
    // dataTeam->channel[0].DataMessage[0].time[4] = '\0';
    // sprintf(dataTeam->channel[0].DataMessage[0].time, "test");

    //     dataTeam->channel[0].DataMessage[1].message = malloc(sizeof(char) * 5);
    // dataTeam->channel[0].DataMessage[1].message[4] = '\0';
    // sprintf(dataTeam->channel[0].DataMessage[1].message, "test");
    // dataTeam->channel[0].DataMessage[1].UserSendUid[strlen(dataTeam->channel[0].uid)] = '\0';
    // sprintf(dataTeam->channel[0].DataMessage[1].UserSendUid,"%s", dataTeam->channel[0].uid);
    // dataTeam->channel[0].DataMessage[1].time = malloc(sizeof(char) * 5);
    // dataTeam->channel[0].DataMessage[1].time[4] = '\0';
    // sprintf(dataTeam->channel[0].DataMessage[1].time, "test");

    // dataTeam->channel[1].name = malloc(sizeof(char) * 6);
    // dataTeam->channel[1].name[5] = '\0';
    // strcpy(dataTeam->channel[1].name, "tests");
    // dataTeam->channel[1].uid[36] = '\0';
    // strcpy(dataTeam->channel[1].uid, dataTeam->uid);

    //     dataTeam->channel[1].DataMessage[0].message = malloc(sizeof(char) * 5);
    // dataTeam->channel[1].DataMessage[0].message[4] = '\0';
    // sprintf(dataTeam->channel[1].DataMessage[0].message, "test");
    // dataTeam->channel[1].DataMessage[0].UserSendUid[strlen(dataTeam->channel[1].uid)] = '\0';
    // sprintf(dataTeam->channel[1].DataMessage[0].UserSendUid,"%s", dataTeam->channel[1].uid);
    // dataTeam->channel[1].DataMessage[0].time = malloc(sizeof(char) * 5);
    // dataTeam->channel[1].DataMessage[0].time[4] = '\0';
    // sprintf(dataTeam->channel[1].DataMessage[0].time, "test");

    //     dataTeam->channel[1].DataMessage[1].message = malloc(sizeof(char) * 5);
    // dataTeam->channel[1].DataMessage[1].message[4] = '\0';
    // sprintf(dataTeam->channel[1].DataMessage[1].message, "test");
    // dataTeam->channel[1].DataMessage[1].UserSendUid[strlen(dataTeam->channel[1].uid)] = '\0';
    // sprintf(dataTeam->channel[1].DataMessage[1].UserSendUid,"%s", dataTeam->channel[1].uid);
    // dataTeam->channel[1].DataMessage[1].time = malloc(sizeof(char) * 5);
    // dataTeam->channel[1].DataMessage[1].time[4] = '\0';
    // sprintf(dataTeam->channel[1].DataMessage[1].time, "test");

    //     dataTeam->channel[2].name = malloc(sizeof(char) * 6);
    // dataTeam->channel[2].name[5] = '\0';
    // strcpy(dataTeam->channel[2].name, "tests");
    // dataTeam->channel[2].uid[36] = '\0';
    // strcpy(dataTeam->channel[2].uid, dataTeam->uid);

    //     dataTeam->channel[2].DataMessage[0].message = malloc(sizeof(char) * 5);
    // dataTeam->channel[2].DataMessage[0].message[4] = '\0';
    // sprintf(dataTeam->channel[2].DataMessage[0].message, "test");
    // dataTeam->channel[2].DataMessage[0].UserSendUid[strlen(dataTeam->channel[2].uid)] = '\0';
    // sprintf(dataTeam->channel[2].DataMessage[0].UserSendUid,"%s", dataTeam->channel[2].uid);
    // dataTeam->channel[2].DataMessage[0].time = malloc(sizeof(char) * 5);
    // dataTeam->channel[2].DataMessage[0].time[4] = '\0';
    // sprintf(dataTeam->channel[2].DataMessage[0].time, "test");

    //     dataTeam->channel[2].DataMessage[1].message = malloc(sizeof(char) * 5);
    // dataTeam->channel[2].DataMessage[1].message[4] = '\0';
    // sprintf(dataTeam->channel[2].DataMessage[1].message, "test");
    // dataTeam->channel[2].DataMessage[1].UserSendUid[strlen(dataTeam->channel[2].uid)] = '\0';
    // sprintf(dataTeam->channel[2].DataMessage[1].UserSendUid,"%s", dataTeam->channel[2].uid);
    // dataTeam->channel[2].DataMessage[1].time = malloc(sizeof(char) * 5);
    // dataTeam->channel[2].DataMessage[1].time[4] = '\0';
    // sprintf(dataTeam->channel[2].DataMessage[1].time, "test");



    // dataTeam->teamMembers[0].name = malloc(sizeof(char) * 6);
    // dataTeam->teamMembers[0].name[5] = '\0';
    // strcpy(dataTeam->teamMembers[0].name, "tests");
    // dataTeam->teamMembers[0].uid[36] = '\0';
    // strcpy(dataTeam->teamMembers[0].uid, dataTeam->uid);
    // dataTeam->teamMembers[0].isSubscribe = TRUE;
    
    //     dataTeam->teamMembers[1].name = malloc(sizeof(char) * 6);
    // dataTeam->teamMembers[1].name[5] = '\0';
    // strcpy(dataTeam->teamMembers[1].name, "tests");
    // dataTeam->teamMembers[1].uid[36] = '\0';
    // strcpy(dataTeam->teamMembers[1].uid, dataTeam->uid);
    // dataTeam->teamMembers[1].isSubscribe = TRUE;

    create_file_in_directory(name, dataTeam->path_dir_team);
    dump_data_team(dataTeam);
    data->len_team++;
}

void dump_new_team_in_db(TeamData_t *dataTeam, char *name, DataManage_t *data)
{
    
    uuid_t stuuid;
    int len = strlen(name);
    set_all_name_null(dataTeam);
    
    dataTeam->name = malloc(sizeof(char) * (len + 1));
    if (dataTeam->name == NULL)
        exit(84);
    dataTeam->name[len] = '\0';
    strcpy(dataTeam->name, name);

    dataTeam->path_dir_team = malloc(sizeof(char) * (strlen(data->path_dir_team) + len + 2));
    if (dataTeam->path_dir_team == NULL)
        exit(84);
    dataTeam->path_dir_team[strlen(data->path_dir_team) + len + 1] = '\0';
    sprintf(dataTeam->path_dir_team, "%s/%s", data->path_dir_team, dataTeam->name);
    uuid_generate(stuuid);
    uuid_unparse_lower(stuuid, dataTeam->uid);
    dataTeam->uid[36] = '\0';
    dump_new_team_in_db_help(dataTeam, name, data);
}
