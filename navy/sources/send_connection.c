/*
** EPITECH PROJECT, 2020
** attack_connection.c
** File description:
** attack connection
*/

#include "../include/my.h"
#include "../include/navy.h"

extern struct global_variable_s glob;

void send_signal_positions(int nb1, int nb2)
{
    int i = 0;

    for (i = 0; i != nb1; i++) {
        kill(glob.pid2, SIGUSR1);
        usleep(100);
    }
    kill(glob.pid2, SIGUSR2);
    usleep(100);
    for (i = 0; i != nb2; i++) {
        kill(glob.pid2, SIGUSR1);
        usleep(100);
    }
    kill(glob.pid2, SIGUSR2);
}

void send_position(void)
{
    char *buffer = entry_attack();

    while (((my_strlen(buffer) - 1) < 2 || (my_strlen(buffer) - 1) > 2)
        || (buffer[0] < 'A' || buffer[0] > 'H')
        || (buffer[1] < '1' || buffer[1] > '8')) {
        my_putstr("wrong position\n");
        buffer = entry_attack();
    }
    write(1, buffer, 2);
    my_putstr(": ");
    send_signal_positions((buffer[0] - 65), buffer[1] - 49);
}