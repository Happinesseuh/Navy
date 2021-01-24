/*
** EPITECH PROJECT, 2020
** connection.c
** File description:
** connect two terminal
*/

#include "../include/my.h"
#include "../include/navy.h"

struct global_variable_s glob;

void signal1_handler(int signo, siginfo_t *info, void * context)
{
    (void)signo;
    (void)context;
    my_putstr("enemy connected\n");
    glob.pid2 = info->si_pid;
    kill(info->si_pid, SIGUSR2);
}

void signal2_handler(int signo, siginfo_t *info, void * context)
{
    (void)signo;
    (void)context;
    glob.pid2 = info->si_pid;
    my_putstr("successfully connected\n");
}

int connection_player2(int signo)
{
    struct sigaction sigact2;
    int pid = getpid();
    glob.pid1 = pid;

    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    sigact2.sa_sigaction = signal2_handler;
    sigact2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sigact2, NULL);
    kill(signo, SIGUSR1);
    pause();
    return (0);
}

int connection_player1(void)
{
    int pid = getpid();
    struct sigaction sigact;
    glob.pid1 = pid;

    my_putstr("my_pid: ");
    my_put_nbr(pid);
    my_putchar('\n');
    my_putstr("waiting for enemy connection...\n\n");
    sigact.sa_sigaction = signal1_handler;
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigact, NULL);
    pause();
    return (0);
}