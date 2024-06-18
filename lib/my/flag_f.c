/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flagf
*/

#include "../../include/my.h"

void convert_float(double dec, long long decimal, long long integer)
{
    my_put_nbr(integer);
    my_putchar('.');
    for (int i = 0; i < 5; i++) {
        dec = dec * 10;
        decimal = (long long)(dec);
        my_put_nbr(decimal);
        dec = dec - decimal;
    }
        dec = dec * 10;
        decimal = (long long)(dec);
        my_put_nbr(decimal);
}

void flagf(va_list list)
{
    double nb = va_arg(list, double);
    long long decimal = 0;
    long long integer = nb;
    double cpy_nb = (nb -integer) * 1000000;

    if (nb < 0) {
        nb *= -1;
        my_putchar('-');
    }
    nb *= 1000000;
    if ((long long)cpy_nb != 999999) {
        nb += 0.5;
    } else {
        nb += 0.44;
    }
    cpy_nb /= 1000000;
    nb /= 1000000;
    integer = (long long)nb;
    convert_float(nb - integer, decimal, integer);
}
