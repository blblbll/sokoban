/*
** EPITECH PROJECT, 2022
** if.c
** File description:
** if conditions
*/
#include "./include/my.h"

int ifplayer(char *str, int i, struct poz *player)
{
    for (int j = 0; str[j] != '\0'; j++)
        if (str[j] == 'P') {
            player->i = i;
            player->j = j;
            return 1;
        }
    return -1;
}

int ifwin2(struct maps mymap, int i)
{
    for (int j = 0; mymap.vanillamap[i][j] != '\0'; j++)
        if (mymap.vanillamap[i][j] == 'O' && mymap.map[i][j] != 'X')
            return -1;
    return 0;
}

int ifwin(struct maps mymap)
{
    for (int i = 0; mymap.vanillamap[i] != NULL; i++)
        if (ifwin2(mymap, i) == -1)
            return -1;
    return 1;
}
