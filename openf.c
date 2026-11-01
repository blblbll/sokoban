/*
** EPITECH PROJECT, 2022
** openf
** File description:
** open a file and get it in a char *
*/
#include "./include/my.h"

void strip_cr(char *buff)
{
    int j = 0;

    for (int i = 0; buff[i] != '\0'; i++)
        if (buff[i] != '\r')
            buff[j++] = buff[i];
    buff[j] = '\0';
}

void verifbuf(char *buff)
{
    int cpto = 0;
    int cptx = 0;
    int cptp = 0;
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] != ' ' && buff[i] != '\n' && buff[i] != '#'
            && buff[i] != 'X' && buff[i] != 'O' && buff[i] != 'P')
            my_fail("invalid character in the map "
                "(only ' ', '#', 'P', 'X' and 'O' are allowed)");
        if (buff[i] == 'P')
            cptp++;
        if (buff[i] == 'O')
            cpto++;
        if (buff[i] == 'X')
            cptx++;
    }
    if (cptp != 1)
        my_fail("the map must contain exactly one 'P'");
    if (cpto == 0)
        my_fail("the map must contain at least one 'O'");
    if (cpto != cptx)
        my_fail("the number of 'X' must be equal to the number of 'O'");
}

static char *read_map(int fd, long size)
{
    char *buff = malloc(sizeof(char) * (size + 2));
    long total = 0;
    long n = 1;

    if (buff == NULL)
        my_fail("memory allocation failed");
    while (total < size && n > 0) {
        n = read(fd, buff + total, size - total);
        total += (n > 0) ? n : 0;
    }
    if (n < 0)
        my_fail("cannot read the map file");
    buff[total] = '\0';
    return buff;
}

char *fs_open_file(const char *pathfile)
{
    char *buff;
    struct stat stati;
    int fd = open(pathfile, O_RDONLY);

    if (fd < 0)
        my_fail("cannot open the map file");
    if (fstat(fd, &stati) == -1 || !S_ISREG(stati.st_mode))
        my_fail("the map is not a regular file");
    buff = read_map(fd, stati.st_size);
    close(fd);
    strip_cr(buff);
    verifbuf(buff);
    return (buff);
}
