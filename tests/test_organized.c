/*
** EPITECH PROJECT, 2023
** organized
** File description:
** test_organized
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/organized.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

// add
Test(organized, add_function, .init = redirect_all_std)
{
    list_t *list = NULL;

    char *add_args[] = {"ACTUATOR", "actuator",
        "DEVICE", "device",
        "PROCESSOR", "processor",
        "SENSOR", "sensor",
        "WIRE", "wire", NULL};

    int returned_value = add(&list, add_args);

    cr_assert_stdout_eq_str("ACTUATOR n°0 - \"actuator\" added.\n\
DEVICE n°1 - \"device\" added.\nPROCESSOR n°2 - \"processor\" added.\n\
SENSOR n°3 - \"sensor\" added.\nWIRE n°4 - \"wire\" added.\n");
    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    list = NULL;
    char *args[] = {"ACTUATOR", NULL};
    returned_value = add(&list, args);

    cr_assert_eq(returned_value, 84, "Error handling: check case of args 0 or 1 is NULL.");

    char *destructor[] = {"DESTRUCTOR", "usb", NULL};
    returned_value = add(&list, destructor);

    cr_assert_eq(returned_value, 84, "Error handling: check case of incorrect hardware.");

    char *empty[] = {NULL};
    returned_value = add(&list, empty);

    cr_assert_eq(returned_value, 84, "Error handling: empty args.");
}

// del
Test(organized, del_function, .init = redirect_all_std)
{
    list_t *list = NULL;
    char *add_args[] = {"ACTUATOR", "actuator",
        "DEVICE", "device",
        "PROCESSOR", "processor",
        "SENSOR", "sensor",
        "WIRE", "wire", NULL};

    int returned_value = add(&list, add_args);

    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    char *del_args[] = {"1", "3", NULL};
    returned_value = del(&list, del_args);

    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    char *not_num[] = {"a", "3", NULL};
    returned_value = del(&list, not_num);

    cr_assert_eq(returned_value, 84, "Error handling: check case of id not a number.");

    char *last_id[] = {"4", "2", NULL};
    returned_value = del(&list, last_id);

    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    char *empty[] = {NULL};
    returned_value = del(&list, empty);

    cr_assert_eq(returned_value, 84, "Error handling: empty args.");

    list = NULL;
    char *empty_list[] = {"4", "2", NULL};
    returned_value = del(&list, empty_list);

    cr_assert_eq(returned_value, 84, "Error handling: empty linked list.");
}

// disp
Test(organized, disp_function, .init = redirect_all_std)
{
    list_t *list = NULL;
    list = malloc(sizeof(list_t));
    list->id = 0;
    list->name = "usb";
    list->type = "WIRE";
    list->next = NULL;
    char *args[] = {NULL};

    int returned_value = disp(&list, args);

    cr_assert_stdout_eq_str("WIRE n°0 - \"usb\"\n", "Expected output to be ''WIRE n°0 - \"usb\"''.");
    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    char *nempty[] = {"test", NULL};
    returned_value = disp(&list, nempty);

    cr_assert_eq(returned_value, 84, "Error handling: nempty args.");

}

// sort
Test(organized, sort)
{
    list_t *list = NULL;
    char *sort_args[] = {"inv_arg", NULL};
    int returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");

    char *sort_argss[] = {"inv_arg", "inv_arg", NULL};
    returned_value = sort(&list, sort_argss);

    *sort_args = NULL;    
    returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");
}

Test(organized, sort_type, .init = redirect_all_std)
{
    list_t *list = NULL;

    char *add_args[] = {"ACTUATOR", "actuator",
        "DEVICE", "device", NULL};
    char *sort_args[] = {"TYPE", NULL};
    char **args = NULL;

    add(&list, add_args);

    int returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    list = NULL;
    returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");
}

Test(organized, sort_rtype, .init = redirect_all_std)
{
    list_t *list = NULL;

    char *add_args[] = {"ACTUATOR", "actuator",
        "DEVICE", "device", "ACTUATOR", "actuator", NULL};
    char *sort_args[] = {"TYPE", "-r", NULL};
    char **args = NULL;

    add(&list, add_args);

    int returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    list = NULL;
    returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");
}

Test(organized, sort_name, .init = redirect_all_std)
{
    list_t *list = NULL;

    char *add_args[] = {"DEVICE", "actuator",
        "DEVICE", "device", NULL};
    char *sort_args[] = {"NAME", NULL};
    char **args = NULL;
    char *check = "actuator";
    char *checkk = "device";

    add(&list, add_args);

    int returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    list = NULL;
    returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");
}

Test(organized, sort_nrame, .init = redirect_all_std)
{
    list_t *list = NULL;

    char *add_args[] = {"DEVICE", "actuator",
        "DEVICE", "device", "WIRE", "barbapapa", NULL};
    char *sort_args[] = {"NAME", "-r", NULL};
    char **args = NULL;
    char *check = "actuator";
    char *checkk = "device";

    add(&list, add_args);

    int returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    list = NULL;
    returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");
}

Test(organized, sort_id, .init = redirect_all_std)
{
    list_t *list = NULL;

    char *add_args[] = {"ACTUATOR", "actuator",
        "DEVICE", "device", NULL};
    char *sort_args[] = {"ID", NULL};
    char **args = NULL;

    add(&list, add_args);

    int returned_value = sort(&list, sort_args);

    cr_assert_eq(list->id, 0, "Expected id to be 0.");
    cr_assert_eq(list->next->id, 1, "Expected id to be 1.");
    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    list = NULL;
    returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");
}

Test(organized, sort_rid, .init = redirect_all_std)
{
    list_t *list = NULL;

    char *add_args[] = {"ACTUATOR", "actuator",
        "DEVICE", "device", NULL};
    char *sort_args[] = {"ID", "-r", NULL};
    char *prep[] = {"ID", NULL};
    char **args = NULL;

    add(&list, add_args);
    sort(&list, prep);

    int returned_value = sort(&list, sort_args);

    cr_assert_eq(list->id, 1, "Expected id to be 1.");
    cr_assert_eq(list->next->id, 0, "Expected id to be 0.");
    cr_assert_eq(returned_value, 0, "Expected returned value to be 0.");

    list = NULL;
    returned_value = sort(&list, sort_args);

    cr_assert_eq(returned_value, 84, "Expected returned value to be 84.");
}
