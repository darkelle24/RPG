/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** strtool_3
*/

int is_nbr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9')
            return (-1);
        i++;
    }
    return (0);
}