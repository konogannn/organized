/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** put_nbr_base
*/

#include "../../include/my.h"

void my_put_onbr(unsigned int nb)
{
    int i;

    i = nb % 8;
    if (nb > 7) {
        nb = nb / 8;
        my_put_onbr(nb);
        my_putchar('0' + i);
    } else {
        my_putchar(nb + '0');
    }
}

void my_put_unbr(unsigned int nb)
{
    int i;

    i = nb % 10;
    if (nb > 9) {
        nb = nb / 10;
        my_put_unbr(nb);
        my_putchar('0' + i);
    } else {
        my_putchar(nb + '0');
    }
}

void display_spe_x(int nb, int state)
{
    if (nb < 10) {
        my_putchar('0' + nb);
    }
    if (nb >= 10 && nb <= 15 && state == 0) {
        my_putchar('a' + (nb - 10));
    }
    if (nb >= 10 && nb <= 15 && state == 1) {
        my_putchar('A' + (nb - 10));
    }
}

void my_put_xmin(unsigned int nb)
{
    int i;

    i = nb % 16;
    if (nb > 15) {
        nb = nb / 16;
        my_put_xmin(nb);
        display_spe_x(i, 0);
    } else {
        display_spe_x(nb, 0);
    }
}

void my_put_xmaj(unsigned int nb)
{
    int i;

    i = nb % 16;
    if (nb > 15) {
        nb = nb / 16;
        my_put_xmaj(nb);
        display_spe_x(i, 1);
    } else {
        display_spe_x(nb, 1);
    }
}
