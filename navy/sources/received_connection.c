/*
** EPITECH PROJECT, 2020
** attack.c
** File description:
** handle attack
*/

#include "../include/my.h"
#include "../include/navy.h"

extern struct global_variable_s glob;

char *entry_attack(void)
{
    char *buffer;
    size_t buffsize = 32;
    size_t entry;

    buffer = (char *)malloc(buffsize * sizeof(char));
    my_putstr("attack : ");
    entry = getline(&buffer, &buffsize, stdin);
    glob.x = buffer[0] - 'A';
    glob.y = buffer[1] - '1';
    return (buffer);
}

void signal_handler_positions(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1 && glob.received == 0)
        glob.x++;
    else if (signo == SIGUSR1 && glob.received == 1)
        glob.y++;
    if (signo == SIGUSR2)
        glob.received++;
}

void signal_handler_positions2(int signo, siginfo_t *info, void *context)
{
    if (signo == SIGUSR1) {
        glob.hit1++;
        glob.success = 1;
    }
    if (signo == SIGUSR2)
        glob.success = 0;
}

void received_hit(void)
{
    struct sigaction sigact;

    sigact.sa_sigaction = &signal_handler_positions2;
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigact, NULL);
    sigaction(SIGUSR2, &sigact, NULL);
}

void received_signal_positions(void)
{
    struct sigaction sigact;

    sigact.sa_sigaction = &signal_handler_positions;
    sigact.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sigact, NULL);
    sigaction(SIGUSR2, &sigact, NULL);
    glob.x = 0;
    glob.y = 0;
}
