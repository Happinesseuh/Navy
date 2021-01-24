/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** descripton
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2) {
        s1 += 1;
        s2 += 1;
    }
    if (*s1 == *s2)
        return (0);
    else
        return (*s1 - *s2);
}
