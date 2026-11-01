/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** sokoban game
*/

#include "./include/my.h"

struct poz getpoz(char **map)
{
    struct poz player = {-1, -1};
    for (int i = 0; map[i] != NULL; i++)
        if (ifplayer(map[i], i, &player) == 1)
            return player;
    return player;
}

void gagne(struct maps mymap)
{
    displaymap(mymap.map, mymap.vanillamap, 1);
    napms(1500);
    endwin();
}

struct maps inimap(char *name)
{
    char *tmp = fs_open_file(name);
    struct maps mymap;
    mymap.map = my_str_to_word_array(tmp);
    mymap.vanillamap = my_str_to_word_array(tmp);
    free(tmp);
    mymap.name = name;
    return mymap;
}

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("USAGE\n"
               "\t./my_sokoban map\n"
               "DESCRIPTION\n"
               "\tmap   file representing the warehouse map, containing '#' for walls,\n"
               "\t\t'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
        exit(84);
    }
    char prec = ' ';
    struct maps mymap = inimap(argv[1]);
    init_display();
    while (1) {
        displaymap(mymap.map, mymap.vanillamap, 0);
        deplacer(&mymap, &prec);
        if (ifwin(mymap) == 1) {
            gagne(mymap);
            return 0;
        }
    }
    endwin();
    return 0;
}
