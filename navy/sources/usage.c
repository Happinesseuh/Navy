/*
** EPITECH PROJECT, 2020
** usage.c
** File description:
** usage for project navy
*/

#include "../include/my.h"
#include "navy.h"

void print_help(void)
{
    my_putstr("USAGE\n");
    my_putstr("\t./navy [first_player_pid] navy_positions\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("\tfirst_player_pid: only for the 2nd ");
    my_putstr("player. pid of the first player.\n");
    my_putstr("\tnavy_positions: file representing ");
    my_putstr("the positions of the ships.\n");
}
