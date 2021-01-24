/*
** EPITECH PROJECT, 2020
** all prototypes
** File description:
** in the lib
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>

void my_putchar(char c);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
char *my_strcpy(char *dest, char const *src);
unsigned int my_put_un_nbr(unsigned int i);
char *my_strdup (char const *src);

#endif
