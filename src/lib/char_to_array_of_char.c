/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** char_to_array_of_char
*/

#include <malloc.h>

static char **seperate_2(char *str, int count)
{
    char **tab = malloc(sizeof(char *) * (count + 1));
    int i = 1;
    int a = 0;

    tab[count] = NULL;
    tab[0] = &str[0];
    while (i != count) {
        if (str[a] == '\0') {
            tab[i] = &str[a + 1];
            i++;
            a++;
        }
        a++;
    }
    return (tab);
}

char **seperate(char *str, char del)
{
    int i = 0;
    int count = 1;

    while (str[i] != '\0') {
        if (str[i] == del) {
            count++;
            str[i] = '\0';
        }
        i++;
    }
    return (seperate_2(str, count));
}