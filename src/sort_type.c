/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort_type
*/

#include "../include/organized.h"

void bubble_nrtype(int count, list_t *current)
{
    for (int j = 0; j < count - 1; j++) {
        if (my_strcmp(current->type, current->next->type) < 0) {
            swap(current, current->next);
        }
        current = current->next;
    }
}

void bubble_rtype(list_t *list, int len)
{
    list_t *current;

    for (int i = 0; i < len; i++) {
        current = list;
        bubble_nrtype(len - i, current);
    }
}

void bubble_ntype(int count, list_t *current)
{
    for (int j = 0; j < count - 1; j++) {
        if (my_strcmp(current->type, current->next->type) > 0) {
            swap(current, current->next);
        }
        current = current->next;
    }
}

void bubble_type(list_t *list, int len)
{
    list_t *current;

    for (int i = 0; i < len; i++) {
        current = list;
        bubble_ntype(len - i, current);
    }
}

int sort_type(void *data, bool rev)
{
    list_t *list = *(list_t **)data;
    list_t *counter = list;
    int len = 0;

    if (!list)
        return (84);
    while (counter != NULL) {
        len++;
        counter = counter->next;
    }
    if (!rev)
        bubble_type(list, len);
    else
        bubble_rtype(list, len);
    return (0);
}
