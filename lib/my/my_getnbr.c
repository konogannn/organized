/*
** EPITECH PROJECT, 2023
** libc
** File description:
** m_getnbr
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int nb = 0;
    int neg = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++) {
        if (str[i] == '-')
            neg *= -1;
    }
    for (; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nb = (nb * 10) + str[i] - '0';
        } else
            return (nb * neg);
    }
    return (nb * neg);
}

int how_many(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    if (count != 0) {
        return (count);
    } else {
        return (-1);
    }
}
