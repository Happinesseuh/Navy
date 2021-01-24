/*
** EPITECH PROJECT, 2020
** error2.c
** File description:
** error
*/

#include "my.h"
#include "navy.h"

int error_check(int ac, char **av)
{
    if (ac == 2) {
        if (my_strcmp(av[1], "-h") == 0)
            print_help();
    } else if (ac == 3)
        if (my_str_isnum(av[1]) != 0)
            return (1);
}