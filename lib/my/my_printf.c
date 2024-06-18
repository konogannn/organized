/*
** EPITECH PROJECT, 2023
** my_printf
** File description:
** my_printf
*/

#include "../../include/my.h"

void flag_test2(const char *format, va_list list, int i)
{
    void (*tab2_convspe[20])(va_list) = {&flagd, &flagi, &flago,
        &flagu, &flagxmin, &flagxmaj, &flage, &flagemaj, &flagf, &flagf,
        &flagg, &flagg, &flagc, &flags, &flagp};
    char tab_convspe[20] = {'d', 'i', 'o', 'u', 'x', 'X', 'e', 'E', 'f', 'F',
        'g', 'G', 'c', 's', 'p'};

    for (int j = 0; tab_convspe[j] != '\0'; j++) {
        if ('%' == format[i]) {
            my_putchar('%');
            break;
        }
        if (tab_convspe[j] == format[i]) {
            tab2_convspe[j](list);
        }
    }
}

int is_flag(const char *format, int i)
{
    char *str = "diouyxXeEfFgGcsp#%lh";
    int c = 0;

    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == format[i]) {
            c++;
        }
    }
    return (c);
}

int my_two(const char *format, va_list list, int i)
{
    if (is_flag(format, i) == 0) {
        my_putchar('%');
        my_putchar(format[i]);
    }
    if (format[i] == 'l') {
        length_l(format, list, i + 1);
        return (i + 1);
    }
    if (format[i] == '#') {
        flaghashtag(format, i + 1);
        flag_test2(format, list, i + 1);
        return (i + 1);
    } else {
        flag_test2(format, list, i);
        return (i);
    }
}

void my_printf(const char *format, ...)
{
    va_list(list);
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            my_putchar(format[i]);
        } else {
            i++;
            i = my_two(format, list, i);
        }
    }
    va_end(list);
}
