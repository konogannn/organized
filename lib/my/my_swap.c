/*
** EPITECH PROJECT, 2023
** my_swap
** File description:
** my_swap
*/

#include "../../include/my.h"

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
