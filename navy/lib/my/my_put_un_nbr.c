/*
** EPITECH PROJECT, 2020
** my_put_un_nbr
** File description:
** displays an unsigned number
*/
#include "my.h"

unsigned int my_put_un_nbr(unsigned int i)
{
    if (i >= 10)
        (my_put_un_nbr(i/10));
    my_putchar((i%10) + 48);
}
