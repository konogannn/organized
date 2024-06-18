/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flagc
*/

#include "../../include/my.h"

void flagc(va_list list)
{
    char c = va_arg(list, int);

    my_putchar(c);
}
