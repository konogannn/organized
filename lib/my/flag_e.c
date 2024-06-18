/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flage
*/

#include "../../include/my.h"

void convert_fake_float(double dec, long long decimal,
    long long integer)
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

void fake_float(double nb)
{
    long long decimal = 0;
    long long integer = nb;
    double cpy_nb = (nb -integer) * 1000000;

    nb *= 1000000;
    if ((long long)cpy_nb != 999999) {
        nb += 0.5;
    } else {
        nb += 0.44;
    }
    cpy_nb /= 1000000;
    nb /= 1000000;
    integer = (long long)nb;
    convert_fake_float(nb - integer, decimal, integer);
}

void big_exposant(double nb, int count)
{
    for (; nb > 1; count++) {
        nb /= 10;
    }
    nb *= 10;
    fake_float(nb);
    my_putstr("e+");
    if (count < 10) {
        my_putchar('0');
    }
    my_put_nbr(count - 1);
}

void little_exposant(double nb, int count)
{
    for (; nb <= 1; count++) {
        nb *= 10;
    }
    fake_float(nb);
    my_putstr("e-");
    if (count < 10 && count > -10) {
        my_putchar('0');
    }
    if (count < 0) {
        count *= -1;
    }
    my_put_nbr(count);
}

void flage(va_list list)
{
    double nb = va_arg(list, double);
    int count = 0;

    if (nb == 0.0) {
        my_putstr("0.000000e+00");
    }
    if (nb < 1 && nb > 0) {
        little_exposant(nb, count);
    }
    if (nb < 0 && nb > -1) {
        my_putchar('-');
        little_exposant(-nb, count);
    }
    if (nb >= 1) {
        big_exposant(nb, count);
    }
    if (nb <= -1) {
        my_putchar('-');
        big_exposant(-nb, count);
    }
}
