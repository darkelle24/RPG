/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** strtool_2
*/

#include <stdlib.h>
#include "proto/lib.h"

int my_strcountchar(char *str, char to_count)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == to_count)
            count++;
        i++;
    }
    return (count);
}

char *intochar_2(char *nb, int i, int nblist)
{
    int a = 0;

    nb[i] = '\0';
    i--;
    if (nblist < 0) {
        a = 1;
        nblist = nblist * -1;
    }
    while (i >= a) {
        nb[i] = nblist % 10 + 48;
        nblist = nblist / 10;
        i--;
    }
    return (nb);
}

char *inttochar(int nblist)
{
    int i = 0;
    int temp = nblist;
    char *nb;

    if (nblist == 0) {
        nb = malloc(sizeof(char) * 2);
        nb[0] = '0';
        nb[1] = '\0';
        return (nb);
    }
    while (temp != 0) {
        temp = temp / 10;
        i++;
    }
    if (nblist < 0) {
        nb = malloc(sizeof(char) * (i + 2));
        i++;
        nb[0] = '-';
    } else
        nb = malloc(sizeof(char) * (i + 1));
    return (intochar_2(nb, i, nblist));
}

char *str_append(char *add, char *to_add, int free_first, int free_second)
{
    int lengh = my_strlen(add) + my_strlen(to_add);
    char *return_str = malloc(sizeof(char) * (lengh + 1));
    int i = 0;
    int a = 0;

    return_str[lengh] = '\0';
    while (add[i] != '\0') {
        return_str[i] = add[i];
        i++;
    }
    while (to_add[a] != '\0') {
        return_str[a + i] = to_add[a];
        a++;
    }
    if (free_first == 1)
        free(add);
    if (free_second == 1)
        free(to_add);
    return (return_str);
}

char *my_strdup(char const *str)
{
    char *strduped = malloc(sizeof(char) * (my_strlen(str) + 1));
    size_t i = 0;

    if (!str || strduped == NULL) {
        free(strduped);
        return (NULL);
    }
    while (str && str[i] != '\0') {
        strduped[i] = str[i];
        ++i;
    }
    strduped[i] = '\0';
    return (strduped);
}