/*
** EPITECH PROJECT, 2020
** my_strdup
** File description:
** Allocates memory and copies the string given as argument in it
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

char *my_strcpy(char *dest , char  const *src);

int my_strlen(char const *str);

char *my_strdup (char const *src)
{
    char *j = malloc(sizeof(src) * (my_strlen(src)));
    my_strcpy(j, src);
    return (j);
}

