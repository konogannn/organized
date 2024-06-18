/*
** EPITECH PROJECT, 2023
** libc
** File description:
** my_put_nbr
*/

#include "../../include/my.h"

int my_put_nbr(long long nb)
{
    int i;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        i = nb % 10;
        if (nb > 9) {
            nb = nb / 10;
            my_put_nbr(nb);
            my_putchar('0' + i);
        } else {
            my_putchar(nb + '0');
        }
    }
    return (0);
}
