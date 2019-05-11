/*
** EPITECH PROJECT, 2019
** create.c
** File description:
** create.c
*/

#include <stdlib.h>

char *create_array(char *nb, int i)
{
    nb = malloc(sizeof(char) * i + 1);
    nb[i] = '\0';
    return (nb);
}