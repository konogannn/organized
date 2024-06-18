/*
** EPITECH PROJECT, 2023
** tests
** File description:
** test_libc
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/my.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// Test for my_compute_power_rec function
Test(libc, my_compute_power_rec)
{
    int return_value = my_compute_power_rec(5, 2);
    cr_assert_eq(return_value, 25, "Expected return_value to be 25.");
    return_value = my_compute_power_rec(5, -2);
    cr_assert_eq(return_value, 0, "Expected return_value to be 0.");
}

// Test for my_getnbr function
Test(libc, my_getnbr)
{
    int return_value = my_getnbr("0");
    cr_assert_eq(return_value, 0, "Expected return_value to be 0.");
    return_value = my_getnbr("01a");
    cr_assert_eq(return_value, 01, "Expected return_value to be 01.");
    return_value = my_getnbr("-1");
    cr_assert_eq(return_value, -1, "Expected return_value to be -1.");
}

// Test for how_many function
Test(libc, how_many)
{
    int return_value = how_many("tigidou", 'i');
    cr_assert_eq(return_value, 2, "Expected return_value to be 2.");
    return_value = how_many("tigidou", 'a');
    cr_assert_eq(return_value, -1, "Expected return_value to be -1.");
}

// Test for my_isneg function
Test(libc, my_isneg, .init = redirect_all_std)
{
    my_isneg(-1);
    my_isneg(1);
    cr_assert_stdout_eq_str("NP");
}

// Test for my_put_nbr function
Test(libc, my_put_nbr, .init = redirect_all_std)
{
    int nb = -42;
    char *expected_output = "-42";

    my_put_nbr(nb);

    cr_assert_stdout_eq_str(expected_output);
}

// Test for my_putchar function
Test(libc, my_putchar, .init = redirect_all_std)
{
    char *expected_output = "a";

    my_putchar('a');

    cr_assert_stdout_eq_str(expected_output);
}

// Test for my_first_pos function
Test(libc, my_first_pos)
{
    char *input_string = "abcdefghijklmnopqrstuvwxyz";

    int result = my_first_pos(input_string, 'd');
    cr_assert_eq(result, 3, "Expected return value to be 3");

    int result2 = my_first_pos(input_string, '-');
    cr_assert_eq(result2, -1, "Expected return value to be -1");
}

// Test for my_last_pos function
Test(libc, my_last_pos)
{
    char *input_string = "abcdefghijklmnopqrstuvwxyz";

    int result = my_last_pos(input_string, 'd');
    cr_assert_eq(result, 3, "Expected return value to be 3");

    int result2 = my_last_pos(input_string, '-');
    cr_assert_eq(result2, -1, "Expected return value to be -1");
}

// Test for my_putstr function
Test(libc, my_putstr, .init = redirect_all_std)
{
    char *input_string = "abcdefghijklmnopqrstuvwxyz";

    int result = my_putstr(input_string);

    cr_assert_stdout_eq_str(input_string);
    cr_assert_eq(result, 0, "Expected return value to be 0");
}

// Test for my_putstr_frompos function
Test(libc, my_putstr_frompos, .init = redirect_all_std)
{
    char *input_string = "abcdefghijklmnopqrstuvwxyz";
    char *expected_output = "defghijklmnopqrstuvwxyz";

    int result = my_putstr_frompos(input_string, 3);

    cr_assert_stdout_eq_str(expected_output);
    cr_assert_eq(result, 0, "Expected return value to be 0");
}

// Test for my_putstr_topos function
Test(libc, my_putstr_topos, .init = redirect_all_std)
{
    char *input_string = "abcdefghijklmnopqrstuvwxyz";
    char *expected_output = "abcd";

    int result = my_putstr_topos(input_string, 3);

    cr_assert_stdout_eq_str(expected_output);
    cr_assert_eq(result, 0, "Expected return value to be 0");
}

// Test for my_str_isalpha function
Test(libc, my_str_isalpha)
{
    int return_value = my_str_isalpha("a");
    cr_assert_eq(return_value, 0, "Expected return value to be 0");
    return_value = my_str_isalpha("test24");
    cr_assert_eq(return_value, 84, "Expected return value to be 84");

}

// Test for my_str_isnum function
Test(libc, my_str_isnum)
{
    int return_value = my_str_isnum("0");
    cr_assert_eq(return_value, 1, "Expected return value to be 1");
}

// Test for my_strcat function
Test(libc, my_strcat)
{
    char *str1 = "ab";
    char *str2 = "cd";

    str1 = my_strcat(str1, str2);
    cr_assert_str_eq("abcd", str1, "Expected strings to be equal");
}

// Test for my_strcmp function
Test(libc, my_strcmp, .init = redirect_all_std)
{
    char *a = "abcd";
    char *b = "abc";

    int result = my_strcmp(a, a);
    cr_assert_eq(result, 0, "Expected return value to be 0");

    result = my_strcmp(a, b);
    cr_assert_eq(result, 100, "Expected return value to be 100");
}

// Test for my_strcpy function
Test(libc, my_strcpy, .init = redirect_all_std)
{
    char *input_string = "abcdefghijklmnopqrstuvwxyz";
    char *destination_string = malloc(my_strlen(input_string) * sizeof(char));

    destination_string = my_strcpy(destination_string, input_string);

    cr_assert_str_eq(input_string, destination_string, "Expected strings to be equal");
    free(destination_string);
}

// Test for my_strdup function
Test(libc, my_strdup, .init = redirect_all_std)
{
    char *input_string = "abcdefghijklmnopqrstuvwxyz";
    char *destination_string = malloc(my_strlen(input_string) * sizeof(char));

    destination_string = my_strdup(input_string);

    cr_assert_str_eq(input_string, destination_string, "Expected strings to be equal");
    free(destination_string);
}

// Test for my_strlen function
Test(libc, my_strlen)
{
    int return_value = my_strlen("abcd");
    cr_assert_eq(return_value, 4);

}

// Test for my_swap function
Test(libc, my_swap)
{
    int var1 = 1;
    int var2 = 2;
    my_swap(&var1, &var2);
    cr_assert_eq(var1, 2);
    cr_assert_eq(var2, 1);
}