/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** my_strdup
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
    int len = my_strlen(src);
    char *dest = malloc((len + 1) * sizeof(char));
    int i;

    if (!src)
        return NULL;
    for (i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
