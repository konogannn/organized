/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** my_str_isnum
*/

#include "../../include/my.h"

int my_str_isnum(char const *str)
{
    int s = 0;
    int i = 0;

    for (; i != my_strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            s++;
        }
    }
    return (s == my_strlen(str));
}
