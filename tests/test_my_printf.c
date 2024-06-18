/*
** EPITECH PROJECT, 2023
** tests
** File description:
** test_my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, flagd, .init = redirect_all_std)
{
    my_printf("%d", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, flagi, .init = redirect_all_std)
{
    my_printf("%i", 0);
    cr_assert_stdout_eq_str("0");
}

Test(my_printf, flago, .init = redirect_all_std)
{
    my_printf("%o", 42);
    cr_assert_stdout_eq_str("52");
}

Test(my_printf, flagu, .init = redirect_all_std)
{
    my_printf("%u", 42);
    cr_assert_stdout_eq_str("42");
}

Test(my_printf, flagx, .init = redirect_all_std)
{
    my_printf("%x", 42);
    cr_assert_stdout_eq_str("2a");
}

Test(my_printf, flagX, .init = redirect_all_std)
{
    my_printf("%X", 42);
    cr_assert_stdout_eq_str("2A");
}

Test(my_printf, flage, .init = redirect_all_std)
{
    my_printf("%e\n%e\n%e\n%e", 0.0, 0.1234, -1024.32, -0.32);
    cr_assert_stdout_eq_str("0.000000e+00\n1.234000e-01\n-1.024320e+03\n-3.200000e-01");
}

Test(my_printf, flagE, .init = redirect_all_std)
{
    my_printf("%E\n%E\n%E\n%E\n%E", 0.0, 0.1234, 1.999999, -1024.32, -0.32);
    cr_assert_stdout_eq_str("0.000000E+00\n1.234000E-01\n1.999999E+00\n-1.024320E+03\n-3.200000E-01");
}

Test(my_printf, flagf, .init = redirect_all_std)
{
    my_printf("%f\n%f", 42, 10.999999, -42.05);
    cr_assert_stdout_eq_str("10.999999\n-42.050000");
}

Test(my_printf, flagg, .init = redirect_all_std)
{
    my_printf("%g", 1234.0);
    cr_assert_stdout_eq_str("1234");
}

Test(my_printf, flagG, .init = redirect_all_std)
{
    my_printf("%G", 1234.0);
    cr_assert_stdout_eq_str("1234");
}

Test(my_printf, test_flagc, .init = redirect_all_std)
{
    my_printf("hello worl%c", 'd');
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, test_flags, .init = redirect_all_std)
{
    my_printf("%s", "hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, test_flagp, .init = redirect_all_std)
{
    int x = 42;
    my_printf("%p", x);
    cr_assert_stdout_eq_str("0x2a");
}

Test(my_printf, test_flagmodulo, .init = redirect_all_std)
{
    my_printf("%%hello%% %%world%%");
    cr_assert_stdout_eq_str("%hello% %world%");
}

Test(my_printf, test_flaghashtag, .init = redirect_all_std)
{
    my_printf("%#x", 42);
    cr_assert_stdout_eq_str("0x2a");
}

Test(my_printf, test_flagmulti, .init = redirect_all_std)
{
    int x = 321;

    my_printf("%d%i%o%u%x%X%e%E%f%F%c%s%p%%%#o%#x%#X%k", 42, 42, 42, 42, 42, 42, 42.1, 42.1, 42.1, 42.1, 'c', "str", x, 42, 42, 42);
    cr_assert_stdout_eq_str("424252422a2A4.210000e+014.210000E+0142.10000042.100000cstr0x141%0520x2a0X2A%k");
}

Test(my_printf, test_flagl, .init = redirect_all_std)
{
    my_printf("%ld\n%lo\n%lu\n%lx\n%lX\n%le\n%lE\n%lf\n%lg", 42, 42, 42, 42, 42, 1234.31, 1234.31, 1234.31, 1234.00);
    cr_assert_stdout_eq_str("42\n52\n42\n2a\n2A\n1.234310e+03\n1.234310E+03\n1234.310000\n1234");
}