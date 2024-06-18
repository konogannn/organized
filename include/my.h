/*
** EPITECH PROJECT, 2023
** libc
** File description:
** my.h
*/

#pragma once

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// my_printf
void fake_float(double nb);
void flagc(va_list list);
void flagd(va_list list);
void flage(va_list list);
void flagemaj(va_list list);
void flagf(va_list list);
void flagg(va_list list);
void flaghashtag(char const *format, int i);
void flagi(va_list list);
void flago(va_list list);
void flagp(va_list list);
void flags(va_list list);
void flagu(va_list list);
void flagxmin(va_list list);
void flagxmaj(va_list list);
void length_l(const char *format, va_list list, int i);
void my_printf(const char *format, ...);
void my_put_onbr(unsigned int nb);
void my_put_unbr(unsigned int nb);
void my_put_xmin(unsigned int nb);
void my_put_xmaj(unsigned int nb);

// libc
int my_compute_power_rec(int nb, int p);
// sqrt, find prime
int my_getnbr(char const *str);
// is_prime
int my_isneg(int n);
int my_put_nbr(long long nb);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
// showmem, showstr, sort_int_array
int my_str_isalpha(char const *str);
// islower
int my_str_isnum(char const *str);
// isprintable, isupper, str capitalize
char *my_strcat(char *dest, const char *src);
int my_strcmp(char *a, char *b);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *str);
int my_strlen(char const *str);
// str lowcase, strncat, strncmp, strncpy, strstr, str upcase
void my_swap(int *a, int *b);

// annex functions
int how_many(char *str, char c);
int my_first_pos(char const *str, char c);
int my_last_pos(char const *str, char c);
int my_putstr_frompos(char const *str, int pos);
int my_putstr_topos(char const *str, int pos);
