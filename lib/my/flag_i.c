/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flagi
*/

#include "../../include/my.h"

void flagi(va_list list)
{
    int temp = va_arg(list, int);

    my_put_nbr(temp);
}
