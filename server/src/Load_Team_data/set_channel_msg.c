/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

void set_channel_msg_help(char *str, PublicMessageData_t *msg)
{
    char **tab_tmp = str_to_word_array(str, ' ');
    char *message = get_string_between_quotes(str);
    msg->message = malloc(sizeof(char) * (strlen(message) + 1));
    msg->message[strlen(message)] = '\0';
    strcpy(msg->message, message);
    msg->UserSendUid[36] = '\0';
    strcpy(msg->UserSendUid, tab_tmp[2]);

    msg->time = malloc(sizeof(char) * (strlen(tab_tmp[3]) + 1));
    msg->time[strlen(tab_tmp[3])] = '\0';
    strcpy(msg->time, tab_tmp[3]);
    free_array(tab_tmp);
}

int set_channel_msg (char **tab, int tab_pos, PublicMessageData_t *msg)
{
    if (check_is_is_in(tab[tab_pos], "msg", 1) == 0)
        return tab_pos;
    tab_pos++;
    msg->pos = 0;
    for (int a = tab_pos; check_is_is_in(tab[a], "---", 0); a++) {
        set_channel_msg_help(tab[a], &msg[msg->pos]);
        msg->pos++;
        tab_pos++;
    }
    return tab_pos;
}