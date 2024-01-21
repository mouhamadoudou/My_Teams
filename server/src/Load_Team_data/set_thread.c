/*
** EPITECH PROJECT, 2023
** FileName
** File description:
** FileDescription
*/

#include "save_data.h"
#include "my.h"

int set_thread_name_uuid(char **tab, int a, Thread_t *thread)
{
    a++;
    char **tab_tmp = str_to_word_array(tab[a], ' ');
    char **tab_uuid = str_to_word_array(tab[a + 1], ' ');

    thread->name = malloc(sizeof(char) * (strlen(tab_tmp[3]) + 1));
    thread->name[strlen(tab_tmp[3])] = '\0';
    strcpy(thread->name, tab_tmp[3]);
    thread->uid[36] = '\0';
    strcpy(thread->uid, tab_uuid[3]);
    free_array(tab_tmp);
    free_array(tab_uuid);
    a = a + 2;
    return a;
}

void set_thread_msg_help(char *str, PublicMessageData_t *msg)
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

int set_thread_msg (char **tab, int tab_pos, PublicMessageData_t *msg)
{
    if (check_is_is_in(tab[tab_pos], "msg", 1) == 0)
        return tab_pos;
        
    tab_pos++;
    msg->pos = 0;
    for (int a = tab_pos; check_is_is_in(tab[a], "--", 0); a++) {
        set_thread_msg_help(tab[a], &msg[msg->pos]);
        msg->pos++;
        tab_pos++;
    }
    return tab_pos;
}

int set_channel_thread(char **tab, Thread_t *thread, int tab_pos)
{
    if (check_is_is_in(tab[tab_pos], "thread", 1) == 0)
        return tab_pos;
    thread->pos = 0;

    for (int a = tab_pos; check_is_is_in(tab[a], "thread", 1); a++) {
        a = set_thread_name_uuid(tab, a, &thread[thread->pos]);
        a = set_thread_msg(tab, a, thread[thread->pos].DataMessage);
        tab_pos = a;
        thread->pos++;
        a--;
    }
    return tab_pos;
}