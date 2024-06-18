/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** flag#
*/

#include "../../include/my.h"

void flaghashtag(char const *format, int i)
{
    if (format[i] == 'o') {
        my_putchar('0');
    }
    if (format[i] == 'x') {
        my_putchar('0');
        my_putchar('x');
    }
    if (format[i] == 'X') {
        my_putchar('0');
        my_putchar('X');
    }
}
