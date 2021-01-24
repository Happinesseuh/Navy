/*
** EPITECH PROJECT, 2020
** my get nbr
** File description:
** returns a number given as a string
*/

int minus(int c, int final)
{
    if (c % 2 == 1) {
        final = final *(-1);
    }
    return (final);
}

int my_getnbr(char const *str)
{
    long long final = 0;
    int n = 0;
    int i = 0;
    int minus_counter = 0;

    for (i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-') {
            minus_counter++;
        }
    }
    for (i; str[i] >= '0' && str[i] <= '9'; i++) {
        n = str[i] - 48;
        final = n + (final * 10);
    }
    if (final > 2147483647 || final < (-2147483647 - 1))
        return (0);
    minus(minus_counter, final);
    return (final);
}
