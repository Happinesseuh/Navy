    /*
** EPITECH PROJECT, 2020
** B-PSU-101-PAR-1-1-navy-ines.maaroufi
** File description:
** error
*/
#include "my.h"
#include "navy.h"

int line_mesure(char *str)
{
    int i = 0;
    for (; str[i] != '\n'; i++);
    return (i);
}

int line_count(char *str)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
    }
    return (j);
}

int all_lines_check(char *str, int len)
{
    for (int i = len; str[i+1] != '\0'; i += len + 1)
        if (str[i] != str[len])
            return (84);
    return (0);
}

int overflow_check(char *str)
{
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != '\n' && str[i] < '0' || str[i] > 'H') {
            return (84);
        }
        else if (str[i] != ':' && str[i] >'8' && str[i] < 'A') {
            return (84);
        }
    }
    return (0);
}

int map_error_check(int fd, char *buffer, int len)
{
    int line_len = line_mesure(buffer);
    int check = all_lines_check(buffer, line_len);
    int count = line_count(buffer);
    int over_check = overflow_check(buffer);

    if (fd == -1 || len != 32 || line_len != 7 ||
        check != 0 || count != 4 || over_check != 0)
        return (84);
    return (0);
}