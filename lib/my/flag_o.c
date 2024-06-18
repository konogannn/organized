/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flago
*/

#include "../../include/my.h"

void flago(va_list list)
{
    int temp = va_arg(list, int);

    my_put_onbr(temp);
}
