/*
** EPITECH PROJECT, 2023
** organized
** File description:
** add
*/

#include "../include/organized.h"

bool add_node(void *data, char *new_type, char *new_name, int id)
{
    list_t *new_node = malloc(sizeof(list_t));

    if (!new_node)
        return (false);
    new_node->type = new_type;
    new_node->name = new_name;
    new_node->id = id;
    new_node->next = *(list_t **)data;
    *(list_t **)data = new_node;
    my_printf("%s n°%i - \"%s\" added.\n", new_type, id, new_name);
    return (true);
}

bool my_hardware(char *type)
{
    if (my_strcmp(type, "ACTUATOR") == 0)
        return (true);
    if (my_strcmp(type, "DEVICE") == 0)
        return (true);
    if (my_strcmp(type, "PROCESSOR") == 0)
        return (true);
    if (my_strcmp(type, "SENSOR") == 0)
        return (true);
    if (my_strcmp(type, "WIRE") == 0)
        return (true);
    return (false);
}

bool adder(void *data, char *new_type, char *new_name)
{
    static int id = 0;

    if (my_hardware(new_type) == false) {
        write(2, "error: invalid arg\n", 19);
        return (false);
    }
    if (add_node(data, new_type, new_name, id) == false)
        return (false);
    id++;
    return (true);
}

int add(void *data, char **args)
{
    if (!args[0])
        return (84);
    for (int i = 0; args[i] != NULL; i += 2) {
        if (!args[i + 1] || adder(data, my_strdup(args[i]),
            my_strdup(args[i + 1])) == false)
            return (84);
    }
    return (0);
}
