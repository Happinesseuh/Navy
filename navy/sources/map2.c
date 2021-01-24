/*
** EPITECH PROJECT, 2020
** map2.c
** File description:
** map2
*/

#include "../include/my.h"
#include "../include/navy.h"

extern struct global_variable_s glob;

void display_map_enemy(char **map)
{
    int count = 0;

    map_header_enemy();
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        my_putstr("|");
        for (int j = 0; j < 17; j++) {
            my_putchar(map[count][j]);
            if (i != 8)
                my_putstr(" ");
        }
        count++;
        my_putchar('\n');
    }
}

void display_map(char **map)
{
    int count = 0;

    map_header();
    for (int i = 0; i < 8; i++) {
        my_put_nbr(i + 1);
        my_putstr("|");
        for (int j = 0; j < 17; j++) {
            my_putchar(map[count][j]);
            if (i != 8)
                my_putstr(" ");
        }
        count++;
        my_putchar('\n');
    }
}

char **read_file_and_set_map(char *path)
{
    char **map = malloc(sizeof(char *) * 17);
    char *buffer = malloc(sizeof(char) * 33);
    int fd = open(path, O_RDONLY);
    int len = read(fd, buffer, 32);

    map[8] = NULL;
    map_error_check(fd, buffer, len);
    buffer[len] = '\0';
    for (int i = 0; i < 8; i++) {
        map[i] = my_strdup("........");
    }
    map = fill_map_positions(map, buffer);
    return (map);
}

void hit_or_missed(char **map)
{
    int nb2 = glob.x;
    int nb1 = glob.y;

    my_putchar(glob.x + 'A');
    my_putchar(glob.y + '1');
    my_putstr(": ");
    if (map[nb1][nb2] == '2' || map[nb1][nb2] == '3'
        || map[nb1][nb2] == '4' || map[nb1][nb2] == '5') {
        kill(glob.pid2, SIGUSR1);
        my_putstr("hit\n");
        glob.hit2++;
    } else {
        my_putstr("missed\n");
        kill(glob.pid2, SIGUSR2);
    }
}

void touch_boat(char **map)
{
    int nb2 = glob.x;
    int nb1 = glob.y;

    if (map[nb1][nb2] == '2' || map[nb1][nb2] == '3'
        || map[nb1][nb2] == '4' || map[nb1][nb2] == '5') {
        map[nb1][nb2] = 'x';
    } else {
        map[nb1][nb2] = 'o';
    }
}