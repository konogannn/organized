/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** my_str_isalpha
*/

#include "../../include/my.h"

int my_str_isalpha(char const *str)
{
    int s = 0;

    for (int i = 0; i != my_strlen(str); i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z')) {
            s++;
        } else {
            return (84);
        }
    }
    return (0);
}
