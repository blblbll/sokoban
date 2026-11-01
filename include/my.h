/*
** EPITECH PROJECT, 2022
** my.h
** File description:
** include file
*/

#ifndef MYHSOKO
    #define MYHSOKO
    #include <ncurses.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdio.h>
struct poz{
    int i;
    int j;
};

struct maps{
    char **map;
    char **vanillamap;
    char *name;
};

struct offset{
    int offseti;
    int offsetj;
};

char *fs_open_file(const char *pathfile);
char **my_str_to_word_array(char const *str);
int my_strlen(char const *str);
int collen(char **map);
void my_fail(char *msg);
void free_map(char **map);
void reload_map(struct maps *mymap, char *prec);

int cptmot(char const *str);
int lentotal(char const *str);
int len_mot(char const *str, int *j);
void mot_suivant(char const *str, int *j);
int my_lenligne(char const *str);

void deplacerdroite(struct maps *mymap, struct poz player, char *prec);
void deplacergauche(struct maps *mymap, struct poz player, char *prec);
void deplacerhaut(struct maps *mymap, struct poz player, char *prec);
void deplacerbas(struct maps *mymap, struct poz player, char *prec);
void deplacer(struct maps *mymap, char *prec);

char getubox(char **vmap, int i, int j);
int isbox(struct maps *mymap, struct poz py, char *prec, struct offset coord);

struct poz getpoz(char **map);
void init_display(void);
void displaymap(char **map, char **van, int won);

int ifwin(struct maps mymap);
int ifwin2(struct maps mymap, int i);
int ifplayer(char *str, int i, struct poz *player);
#endif
