/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort
*/

#include "../include/organized.h"

bool is_validarg(char *a)
{
    if (my_strcmp(a, "TYPE") == 0)
        return (true);
    if (my_strcmp(a, "NAME") == 0)
        return (true);
    if (my_strcmp(a, "ID") == 0)
        return (true);
    if (my_strcmp(a, "-r") == 0)
        return (true);
    return (false);
}

int sorter(void *data, char *param, char *opt)
{
    if (!my_strcmp(param, "TYPE") && (opt != NULL && !my_strcmp(opt, "-r"))) {
        if (sort_type(data, true) == 84)
            return (84);
    }
    if (!my_strcmp(param, "NAME") && (opt != NULL && !my_strcmp(opt, "-r"))) {
        if (sort_name(data, true) == 84)
            return (84);
    }
    if (!my_strcmp(param, "ID") && (opt != NULL && !my_strcmp(opt, "-r"))) {
        if (sort_id(data, true) == 84)
            return (84);
    }
    return (0);
}

int sorterf(void *data, char *param)
{
    if (!my_strcmp(param, "TYPE")) {
        if (sort_type(data, false) == 84)
            return (84);
    }
    if (!my_strcmp(param, "NAME")) {
        if (sort_name(data, false) == 84)
            return (84);
    }
    if (!my_strcmp(param, "ID")) {
        if (sort_id(data, false) == 84)
            return (84);
    }
    return (0);
}

int sort(void *data, char **args)
{
    int i;

    if (!args[0])
        return (84);
    for (i = 0; args[i] != NULL && args[i + 1] != NULL; i++) {
        if (is_validarg(my_strdup(args[i])) == false)
            return (84);
        if (sorter(data, my_strdup(args[i]), my_strdup(args[i + 1])) == 84)
            return (84);
    }
    if (is_validarg(my_strdup(args[i])) == false)
        return (84);
    if (sorterf(data, my_strdup(args[i])) == 84)
        return (84);
    return (0);
}

void swap(list_t *current, list_t *next)
{
    char *temp_type = current->type;
    char *temp_name = current->name;
    int temp_id = current->id;

    current->type = next->type;
    current->name = next->name;
    current->id = next->id;
    next->type = temp_type;
    next->name = temp_name;
    next->id = temp_id;
}
