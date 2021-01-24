/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "include/my.h"
#include "include/navy.h"

extern struct global_variable_s glob;

void attack(char **map)
{
    send_position();
    received_hit();
    pause();
    sucess_touch(map);
}

void defense(char **map)
{
    my_putstr("\nwaiting for enemy's attack...\n");
    received_signal_positions();
    while (glob.received <= 1);
    glob.received = 0;
    hit_or_missed(map);
    touch_boat(map);
}

int player_one(int ac, char **av, char **map, char **map_enemy)
{
    connection_player1();
    map = read_file_and_set_map(av[1]);
    while (glob.hit2 <= 14 && glob.hit1 <= 14) {
        display_map(map);
        my_putstr("\n");
        display_map_enemy(map_enemy);
        my_putchar('\n');
        attack(map_enemy);
        defense(map);
    }
    if (glob.hit1 == 14) {
        my_putstr("\nI won");
        return (0);
    }
    else {
        my_putstr("\nEnemy won");
        return (1);
    }
}

int player_two(int ac, char **av, char **map, char **map_enemy)
{
    connection_player2(my_getnbr(av[1]));
    map = read_file_and_set_map(av[2]);
    my_putchar('\n');
    while (glob.hit2 <= 14 && glob.hit1 <= 14) {
        display_map(map);
        my_putstr("\n");
        display_map_enemy(map_enemy);
        defense(map);
        attack(map_enemy);
    }
    if (glob.hit2 == 14) {
        my_putstr("\nI won");
        return (0);
    }
    else {
        my_putstr("\nEnemy won");
        return (1);
    }
}

int main(int ac, char **av)
{
    char **map;
    char **map_enemy = set_map_enemy();

    glob.hit1 = 0;
    glob.hit2 = 0;
    if (error_check(ac, av) == 1)
        return 84;
    if (ac == 2) {
        player_one(ac, av, map, map_enemy);
    }
    if (ac == 3) {
        player_two(ac, av, map, map_enemy);
    }
    return (0);
}