/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flags
*/

#include "../../include/my.h"

void flags(va_list list)
{
    char *str = va_arg(list, char *);

    my_putstr(str);
}
