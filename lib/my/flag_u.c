/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flagu
*/

#include "../../include/my.h"

void flagu(va_list list)
{
    int temp = va_arg(list, int);

    my_put_unbr(temp);
}
