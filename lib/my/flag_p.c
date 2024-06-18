/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flagp
*/

#include "../../include/my.h"

void flagp(va_list list)
{
    void *ptr = va_arg(list, void *);

    my_putchar('0');
    my_putchar('x');
    my_put_xmin((unsigned int)ptr);
}
