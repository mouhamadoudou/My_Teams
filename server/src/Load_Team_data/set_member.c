/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

int check_is_is_in(char *str, char *comp, int pos)
{
    if (str == NULL)
        return FALSE;
    char **tab_tmp = str_to_word_array(str, ' ');

    if (strcmp(tab_tmp[pos], comp) == 0) {
        free_array(tab_tmp);
        return TRUE;
    }
    free_array(tab_tmp);
    return FALSE;
}

void set_member_help(char *str, MemberData_t *teamMembers)
{
    char **tab_tmp = str_to_word_array(str, ' ');
    teamMembers->name = malloc(sizeof(char) * (strlen(tab_tmp[1]) + 1));
    teamMembers->name[strlen(tab_tmp[1])] = '\0';
    strcpy(teamMembers->name, tab_tmp[1]);
    teamMembers->uid[36] = '\0';
    strcpy(teamMembers->uid, tab_tmp[2]);
    teamMembers->isSubscribe = atoi(tab_tmp[3]);
    free_array(tab_tmp);
}

int set_member(char **tab, MemberData_t *teamMembers, int tab_pos)
{
    if (check_is_is_in(tab[tab_pos], "teamMemebers", 1) == 0)
        return tab_pos;
    tab_pos++;
    teamMembers->pos = 0;

    for (int a = tab_pos; check_is_is_in(tab[a], "-", 0); a++) {
        set_member_help(tab[a], &teamMembers[teamMembers->pos]);
        teamMembers->pos++;
        tab_pos++;
    }
    return tab_pos;
}
