/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** navy
*/

#ifndef NAVY_H_
#define NAVY_H_

#include <signal.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

struct global_variable_s {
    int pid1;
    int pid2;
    int x;
    int y;
    int hit1;
    int hit2;
    int success;
    int received;
};

void print_help(void);
/* CONNECTION */
void signal_handler(int signo, siginfo_t *info, void *context);
int connection_player2(int signo);
int connection_player1(void);
void send_postion(void);
/* HANDLE ERROR */
int line_mesure(char *str);
int map_error_check(int fd, char *buffer, int len);
int error_check(int ac, char **av);
/* HANDLE MAP */
char **fill_map_positions(char **map, char *buffer);
void display_map(char **map);
void map_header(void);
void map_header_enemy(void);
char **read_file_and_set_map(char *path);
char **set_map_enemy();
void display_map_enemy(char **map);
void touch_boat(char **map);
void sucess_touch(char **map);
/* GAME */
char *entry_attack(void);
void send_position(void);
void received_signal_positions();
void hit_or_missed(char **map);
void received_hit();
void signal_handler_positions2(int signo, siginfo_t *info, void *context);

#endif /* !NAVY_H_ */
