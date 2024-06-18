/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** length_l
*/

#include "../../include/my.h"

void upart(const char *format, int i, va_list list)
{
    long unsigned int nb = va_arg(list, int);

    if (format[i] == 'o') {
        my_put_onbr(nb);
    }
    if (format[i] == 'u') {
        my_put_unbr(nb);
    }
    if (format[i] == 'x') {
        my_put_xmin(nb);
    }
    if (format[i] == 'X') {
        my_put_xmaj(nb);
    }
}

void intpart(va_list list)
{
    long int nb = va_arg(list, int);

    my_put_nbr(nb);
}

void length_l2(const char *format, va_list list, int i)
{
    if (format[i] == 'g' || format[i] == 'G') {
        flagg(list);
    }
}

void length_l(const char *format, va_list list, int i)
{
    if (format[i] == 'd' || format[i] == 'i') {
        intpart(list);
    }
    if (format[i] == 'o' || format[i] == 'u' ||
        format[i] == 'x' || format[i] == 'X') {
        upart(format, i, list);
    }
    if (format[i] == 'e') {
        flage(list);
    }
    if (format[i] == 'E') {
        flagemaj(list);
    }
    if (format[i] == 'f' || format[i] == 'F') {
        flagf(list);
    }
    length_l2(format, list, i);
}
