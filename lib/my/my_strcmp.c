/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int my_strcmp(char *a, char *b)
{
    int i;

    for (i = 0; a[i] == b[i]; i++) {
        if (a[i] == '\0')
            return (0);
    }
    return (a[i] - b[i]);
}
