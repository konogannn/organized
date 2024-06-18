/*
** EPITECH PROJECT, 2023
** organized
** File description:
** organized
*/

#pragma once

    #include "my.h"
    #include "shell.h"

typedef struct list_s {
    char *type;
    char *name;
    int id;

    struct list_s *next;
} list_t;

int check_argdel(char *str);
int sort_id(void *data, bool rev);
int sort_name(void *data, bool rev);
int sort_type(void *data, bool rev);
void swap(list_t *current, list_t *next);
