/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** convert a str to word array
*/

#include "./include/my.h"

static int nb_lines(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
        else if (str[i + 1] == '\0')
            count++;
    }
    return count;
}

static int row_len(char const *str)
{
    int len = 0;

    while (str[len] != '\0' && str[len] != '\n')
        len++;
    return len;
}

char **my_str_to_word_array(char const *str)
{
    char **result = malloc(sizeof(char *) * (nb_lines(str) + 1));
    int e = 0;
    int len = 0;

    if (result == NULL)
        my_fail("memory allocation failed");
    while (*str != '\0') {
        len = row_len(str);
        result[e] = malloc(sizeof(char) * (len + 1));
        if (result[e] == NULL)
            my_fail("memory allocation failed");
        for (int i = 0; i < len; i++)
            result[e][i] = str[i];
        result[e][len] = '\0';
        e++;
        str += len;
        if (*str == '\n')
            str++;
    }
    result[e] = NULL;
    return result;
}
