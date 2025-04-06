/*
** EPITECH PROJECT, 2022
** lib
** File description:
** functions for my_str_to_word_array
*/
#include "./include/my.h"

int cptmot(char const *str)
{
    int i = 0;
    int cpt = 0;
    for (i; str[i] != '\0'; i++) {
        if (str[i + 1] == '\n' || str[i + 1] == '\0')
            cpt++;
    }
    return cpt;
}

int lentotal(char const *str)
{
    int i = 0;
    int cpt = 0;
    for (i; str[i] != '\0'; i++) {
        if (str[i] != '\n')
            cpt++;
    }
    return cpt;
}

int len_mot(char const *str, int *j)
{
    int cpt = 0;
    while (*j < my_strlen(str) && str[*j] != '\n') {
        *j = *j + 1;
        cpt++;
    }
    return cpt;
}

void mot_suivant(char const *str, int *j)
{
    while (str[*j] == '\n')
        *j = *j + 1;
}

int my_lenligne(char const *str)
{
    int backslach = 0;
    int cpt = 0;
    for (int i = 0; backslach != 2; i++) {
        if (str[i] == '\n')
            backslach++;
        if (backslach == 1)
            cpt++;
    }
    return cpt;
}
