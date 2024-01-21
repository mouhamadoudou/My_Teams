/*
** EPITECH PROJECT, 2023
** str_to_word_array.c
** File description:
** str_to_word_array
*/

#include "my.h"

int llen_point(char *str, char separator)
{
    int result = 0;
    int len = strlen(str);

    for (int a = 0; a < len; a++) {
        if (str[a] == separator)
            result++;
    }
    return result;
}

char *mmy_strcpy(char *dest, char *src, int pos, char separator)
{
    int i = pos;
    int comp = 0;

    while (src[i] != separator && src[i] != '\n' && src[i] != '\0') {
        dest[comp] = src[i];
        i++;
        comp++;
    }
    dest[comp] = '\0';
    return dest;
}

int llen_mot(char *buffer, int pos_d, char separator)
{
    int compteur = 0;
    int i = pos_d;

    while (buffer[i] != separator && buffer[i] != '\n' && buffer[i] != '\0') {
        compteur++;
        i++;
    }
    return compteur;
}

void word_to_tab(char *str, int i, int *comp, char **tab)
{
    mmy_strcpy(tab[*comp], str, i, ' ');
    *comp += 1;

    return;
}

char **str_to_word_array(char *str, char separator)
{
    int len_p = llen_point(str, ' '), comp = 0, len_m = 0;;
    char **tab = malloc(sizeof(char *) * (len_p + 2));
    if (tab == NULL)
        exit(84);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator) {
            len_m = llen_mot(str, i + 1, ' ');
            tab[comp] = malloc(sizeof(char) * len_m + 1);
            check_malloc(tab[comp]);
            word_to_tab(str, i + 1, &comp, tab);
        }
        if (i == 0) {
            len_m = llen_mot(str, i, ' ');
            tab[comp] = malloc(sizeof(char) * len_m + 1);
            check_malloc(tab[comp]);
            word_to_tab(str, i, &comp, tab);
        }
    }
    tab[len_p + 1] = NULL;
    return tab;
}
