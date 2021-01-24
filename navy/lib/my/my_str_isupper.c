/*
** EPITECH PROJECT, 2020
** isupper
** File description:
** description
*/

int my_str_isupper(char const *str)
{
    if (str == "")
        return (1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 65 || str[i] > 90)
            return (0);
    }
    return (1);
}
