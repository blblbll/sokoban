/*
** EPITECH PROJECT, 2022
** openf
** File description:
** open a file and get it in a char *
*/
#include "./include/my.h"

void verifbuf(char *buff)
{
    int cpto = 0;
    int cptx = 0;
    int cptp = 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != ' ' && buff[i] != '\n' && buff[i] != '#'
            && buff[i] != 'X' && buff[i] != 'O' && buff[i] != 'P')
            exit(84);
        if (buff[i] == 'P')
            cptp++;
        if (buff[i] == 'O')
            cpto++;
        if (buff[i] == 'X')
            cptx++;
    }
    if (cptp != 1 || cpto == 0 || cpto != cptx)
        exit(84);
}

char *fs_open_file(const char *pathfile)
{
    char *buff;
    struct stat stati;
    int fd = open(pathfile, O_RDONLY);
    if (fd < 0)
        exit(84);
    stat(pathfile, &stati);
    int taille = stati.st_size;
    buff = malloc(sizeof(char) * (taille + 2));
    read(fd, buff, taille);
    buff[taille] = '\0';
    verifbuf(buff);
    return (buff);
}
