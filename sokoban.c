/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** sokoban game
*/

#include "./include/my.h"

struct poz getpoz(char **map)
{
    struct poz player;
    for (int i = 0; map[i] != NULL; i++)
        if (ifplayer(map[i], i, &player) == 1)
            return player;
}

void displaymap(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        printw(map[i]);
        printw("\n");
    }
    refresh();
}

void gagne(char **map)
{
    clear();
    displaymap(map);
    refresh();
    usleep(200000);
    endwin();
}

struct maps inimap(char *name)
{
    char *tmp = fs_open_file(name);
    struct maps mymap;
    mymap.map = my_str_to_word_array(tmp);
    mymap.vanillamap = my_str_to_word_array(tmp);
    mymap.name = name;
    return mymap;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exit(84);
    char prec = ' ';
    struct maps mymap = inimap(argv[1]);
    initscr();
    keypad(stdscr, TRUE);
    while (1) {
        clear();
        displaymap(mymap.map);
        deplacer(&mymap, &prec);
        if (ifwin(mymap) == 1) {
            gagne(mymap.map);
            return 0;
        }
    }
    endwin();
    return 0;
}
