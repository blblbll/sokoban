/*
** EPITECH PROJECT, 2022
** lib
** File description:
** lib.c
*/
#include "./include/my.h"

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int collen(char **map)
{
    int i = 0;
    for (i; map[i] != NULL; i++);
    return i;
}
