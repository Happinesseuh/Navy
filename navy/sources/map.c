/*
** EPITECH PROJECT, 2020
** map.c
** File description:
** handle map
*/

#include "../include/my.h"
#include "../include/navy.h"

extern struct global_variable_s glob;

char **fill_map_positions(char **map, char *buffer)
{
    int x1 = 0;
    int y1 = 0;
    int x2 = 0;
    int y2 = 0;

    for (int i = 0; i <= 26; i += 8) {
        y1 = (buffer[i + 2] - 65);
        x1 = (buffer[i + 3] - 49);
        map[x1][y1] = buffer[i];
        y2 = (buffer[i + 5] - 65);
        x2 = (buffer[i + 6] - 49);
        while (y1 <= y2 && x1 <= x2) {
            map[x1][y1] = buffer[i];
            if (buffer[i + 2] < buffer[i + 5])
                y1 += 1;
            else
                x1 += 1;
        }
    }
    return (map);
}

void map_header(void)
{
    my_putstr("\nmy positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
}

void map_header_enemy(void)
{
    my_putstr("\nenemy's positions:\n");
    my_putstr(" |A B C D E F G H\n");
    my_putstr("-+---------------\n");
}

char **set_map_enemy()
{
    char **map = malloc(sizeof(char *) * 17);
    map[8] = NULL;
    for (int i = 0; i < 8; i++) {
        map[i] = my_strdup("........");
    }
    return (map);
}

void sucess_touch(char **map)
{
    int nb2 = glob.x;
    int nb1 = glob.y;

    if (glob.success == 1) {
        my_putstr("hit\n");
        map[nb1][nb2] = 'x';
    } else {
        my_putstr("missed\n");
        map[nb1][nb2] = 'o';
    }
}