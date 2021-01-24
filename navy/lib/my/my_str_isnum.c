/*
** EPITECH PROJECT, 2020
** isnum
** File description:
** description
*/
#include <stdio.h>

int my_str_isnum(char const *str)
{
    if (str[0] == '\0') {
        return (1);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (1);
    }
    return (0);
}