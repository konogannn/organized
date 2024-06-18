/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flage maj
*/

#include "../../include/my.h"

void big_exposant2(double nb, int count)
{
    for (; nb > 1; count++) {
        nb /= 10;
    }
    nb *= 10;
    fake_float(nb);
    my_putstr("E+");
    if (count < 10) {
        my_putchar('0');
    }
    my_put_nbr(count - 1);
}

void little_exposant2(double nb, int count)
{
    for (; nb <= 1; count++) {
        nb *= 10;
    }
    fake_float(nb);
    my_putstr("E-");
    if (count < 10 && count > -10) {
        my_putchar('0');
    }
    if (count < 0) {
        count *= -1;
    }
    my_put_nbr(count);
}

void flagemaj(va_list list)
{
    double nb = va_arg(list, double);
    int count = 0;

    if (nb == 0.0) {
        my_putstr("0.000000E+00");
    }
    if (nb < 1 && nb > 0) {
        little_exposant2(nb, count);
    }
    if (nb < 0 && nb > -1) {
        my_putchar('-');
        little_exposant2(-nb, count);
    }
    if (nb >= 1) {
        big_exposant2(nb, count);
    }
    if (nb <= -1) {
        my_putchar('-');
        big_exposant2(-nb, count);
    }
}
