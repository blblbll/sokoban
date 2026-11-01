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
    while (map[i] != NULL)
        i++;
    return i;
}

void my_fail(char *msg)
{
    write(2, "my_sokoban: ", 12);
    write(2, msg, my_strlen(msg));
    write(2, "\n", 1);
    exit(84);
}

void free_map(char **map)
{
    for (int i = 0; map != NULL && map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
