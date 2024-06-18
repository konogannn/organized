/*
** EPITECH PROJECT, 2023
** organized
** File description:
** disp
*/

#include "../include/organized.h"

int disp(void *data, char **args)
{
    list_t *current = *(list_t **)data;

    if (args[0])
        return (84);
    while (current != NULL) {
        my_printf("%s n°%i - \"%s\"\n", current->type,
            current->id, current->name);
        current = current->next;
    }
    return (0);
}
