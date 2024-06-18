/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flagg
*/

#include "../../include/my.h"

void flagg(va_list list)
{
    double nb = va_arg(list, double);
    long long integer = nb;

    my_put_nbr(integer);
}
