/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flagx
*/

#include "../../include/my.h"

void flagxmin(va_list list)
{
    int temp = va_arg(list, int);

    my_put_xmin(temp);
}

void flagxmaj(va_list list)
{
    int temp = va_arg(list, int);

    my_put_xmaj(temp);
}
