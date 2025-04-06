/*
** EPITECH PROJECT, 2022
** box
** File description:
** déplacement des box
*/
#include "./include/my.h"

char getubox(char **vmap, int i, int j)
{
    if (vmap[i][j] == 'X' || vmap[i][j] == 'P')
        return ' ';
    else
        return vmap[i][j];
}

int isbox(struct maps *mymap, struct poz playr, char *prec, struct offset coord)
{
    int i = playr.i;
    int j = playr.j;
    int offseti = coord.offseti;
    int offsetj = coord.offsetj;
    if (mymap->map[i + offseti][j + offsetj] == 'X') {
        if (mymap->map[i + (offseti * 2)][j + (offsetj * 2)] != 'X'
            && mymap->map[i + (offseti * 2)][j + (offsetj * 2)] != '#') {
            mymap->map[i][j] = *prec;
            *prec = getubox(mymap->vanillamap, i + offseti, j + offsetj);
            mymap->map[i + (offseti * 2)][j + (offsetj * 2)] = 'X';
            mymap->map[i + offseti][j + offsetj] = 'P';
            return 1;
        }
        if (mymap->map[i + (offseti * 2)][j + (offsetj * 2)] == '#' ||
            mymap->map[i + (offseti * 2)][j + (offsetj * 2)] == 'X')
            return 1;
    }
    return -1;
}
