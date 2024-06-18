/*
** EPITECH PROJECT, 2023
** libc
** File description:
** my_putchar
*/

#include "../../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_first_pos(char const *str, char c)
{
    int pos = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            pos = i;
            count = 1;
            break;
        }
    }
    if (count == 1) {
        return (pos);
    } else {
        return (-1);
    }
}

int my_last_pos(char const *str, char c)
{
    int pos = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            pos = i;
            count++;
        }
    }
    if (count != 0) {
        return (pos);
    } else {
        return (-1);
    }
}
