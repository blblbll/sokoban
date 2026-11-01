/*
** EPITECH PROJECT, 2022
** deplacement.c
** File description:
** déplacement du joueur
*/

#include "./include/my.h"

void deplacerdroite(struct maps *mymap, struct poz player, char *prec)
{
    int i = player.i;
    int j = player.j;
    struct offset coord;
    coord.offseti = 0;
    coord.offsetj = 1;
    if (j + 1 < my_strlen(mymap->vanillamap[i]) + 1
        && mymap->map[i][j + 1] != '#') {
        if (isbox(mymap, player, prec, coord) == 1)
            return;
        mymap->map[i][j] = *prec;
        *prec = mymap->map[i][j + 1];
        mymap->map[i][j + 1] = 'P';
        return;
    }
}

void deplacergauche(struct maps *mymap, struct poz player, char *prec)
{
    int i = player.i;
    int j = player.j;
    struct offset coord;
    coord.offseti = 0;
    coord.offsetj = -1;
    if (j - 1 >= 0 && mymap->map[i][j - 1] != '#') {
        if (isbox(mymap, player, prec, coord) == 1)
            return;
        mymap->map[i][j] = *prec;
        *prec = mymap->map[i][j - 1];
        mymap->map[i][j - 1] = 'P';
        return;
    }
}

void deplacerhaut(struct maps *mymap, struct poz player, char *prec)
{
    int i = player.i;
    int j = player.j;
    struct offset coord;
    coord.offseti = -1;
    coord.offsetj = 0;
    if (i - 1 >= 0 && mymap->map[i - 1][j] != '#') {
        if (isbox(mymap, player, prec, coord) == 1)
            return;
        mymap->map[i][j] = *prec;
        *prec = mymap->map[i - 1][j];
        mymap->map[i - 1][j] = 'P';
        return;
    }
}

void deplacerbas(struct maps *mymap, struct poz player, char *prec)
{
    int i = player.i;
    int j = player.j;
    struct offset coord;
    coord.offseti = 1;
    coord.offsetj = 0;
    if (i + 1 < collen(mymap->map) && mymap->map[i + 1][j] != '#') {
        if (isbox(mymap, player, prec, coord) == 1)
            return;
        mymap->map[i][j] = *prec;
        *prec = mymap->map[i + 1][j];
        mymap->map[i + 1][j] = 'P';
        return;
    }
}

void reload_map(struct maps *mymap, char *prec)
{
    char *tmp = fs_open_file(mymap->name);

    free_map(mymap->map);
    mymap->map = my_str_to_word_array(tmp);
    free(tmp);
    *prec = ' ';
}

void deplacer(struct maps *mymap, char *prec)
{
    struct poz player = getpoz(mymap->map);
    int key = getch();
    if (key == KEY_RIGHT)
        deplacerdroite(mymap, player, prec);
    if (key == KEY_LEFT)
        deplacergauche(mymap, player, prec);
    if (key == KEY_UP)
        deplacerhaut(mymap, player, prec);
    if (key == KEY_DOWN)
        deplacerbas(mymap, player, prec);
    if (key == ' ')
        reload_map(mymap, prec);
}
