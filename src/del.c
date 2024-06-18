/*
** EPITECH PROJECT, 2023
** organized
** File description:
** del
*/

#include "../include/organized.h"

int del_nodee(list_t *current, int id)
{
    list_t *prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }
    if (!current)
        return (84);
    my_printf("%s n°%i - \"%s\" deleted.\n", current->type,
        current->id, current->name);
    prev->next = current->next;
    free(current);
    return (0);
}

int check_argdel(char *str)
{
    int res;

    if (my_str_isnum(str) == 0)
        return (84);
    res = my_getnbr(str);
    return (res);
}

int del_node(void *data, char *str)
{
    list_t **list = (list_t **)data;
    list_t *current = *list;
    int id = check_argdel(str);

    if (!*list || !current)
        return (84);
    if (current->id == id) {
        *list = (*list)->next;
        my_printf("%s n°%i - \"%s\" deleted.\n", current->type,
            current->id, current->name);
        free(current);
        return (0);
    } else {
        if (del_nodee(current, id) == 84)
            return (84);
    }
    free(str);
    return (0);
}

int del(void *data, char **args)
{
    if (!args[0])
        return (84);
    for (int i = 0; args[i] != NULL; i++) {
        if (del_node(data, my_strdup(args[i])) == 84)
            return (84);
    }
    return (0);
}
