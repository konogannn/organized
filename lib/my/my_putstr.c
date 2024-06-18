/*
** EPITECH PROJECT, 2023
** libc
** File description:
** my_putstr
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}

int my_putstr_frompos(char const *str, int pos)
{
    for (int i = pos; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return (0);
}

int my_putstr_topos(char const *str, int pos)
{
    for (int i = 0; str[i] != '\0' && i <= pos; i++) {
        my_putchar(str[i]);
    }
    return (0);
}
