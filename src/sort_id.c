/*
** EPITECH PROJECT, 2023
** organized
** File description:
** sort_id
*/

#include "../include/organized.h"

void bubble_nrid(int count, list_t *current)
{
    for (int j = 0; j < count - 1; j++) {
        if (current->id < current->next->id) {
            swap(current, current->next);
        }
        current = current->next;
    }
}

void bubble_rid(list_t *list, int len)
{
    list_t *current;

    for (int i = 0; i < len; i++) {
        current = list;
        bubble_nrid(len - i, current);
    }
}

void bubble_nid(int count, list_t *current)
{
    for (int j = 0; j < count - 1; j++) {
        if (current->id > current->next->id) {
            swap(current, current->next);
        }
        current = current->next;
    }
}

void bubble_id(list_t *list, int len)
{
    list_t *current;

    for (int i = 0; i < len; i++) {
        current = list;
        bubble_nid(len - i, current);
    }
}

int sort_id(void *data, bool rev)
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
        bubble_id(list, len);
    else
        bubble_rid(list, len);
    return (0);
}
