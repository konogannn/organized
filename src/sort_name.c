/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort_name
*/


#include "../include/organized.h"

void bubble_nrname(int count, list_t *current)
{
    for (int j = 0; j < count - 1; j++) {
        if (my_strcmp(current->name, current->next->name) < 0) {
            swap(current, current->next);
        }
        current = current->next;
    }
}

void bubble_rname(list_t *list, int len)
{
    list_t *current;

    for (int i = 0; i < len; i++) {
        current = list;
        bubble_nrname(len - i, current);
    }
}

void bubble_nname(int count, list_t *current)
{
    for (int j = 0; j < count - 1; j++) {
        if (my_strcmp(current->name, current->next->name) > 0) {
            swap(current, current->next);
        }
        current = current->next;
    }
}

void bubble_name(list_t *list, int len)
{
    list_t *current;

    for (int i = 0; i < len; i++) {
        current = list;
        bubble_nname(len - i, current);
    }
}

int sort_name(void *data, bool rev)
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
        bubble_name(list, len);
    else
        bubble_rname(list, len);
    return (0);
}
