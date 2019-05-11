/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** get_floatnbr
*/

#include <stdio.h>
#include "proto/lib.h"

float get_floatnbr(char *str)
{
    float nbr = (float) getnbr(str);
    int i = 0;
    float next = 0;
    int count = 0;

    while (str[i] != '.' && str[i] != '\0')
        i++;
    if (str[i] != '\0') {
        next = (float) getnbr(&str[i + 1]);
        if (nbr < 0)
            next *= -1;
        while (str[count + 1 + i] >= '0' && str[count + 1 + i] <= '9') {
            next /= 10;
            count++;
        }
        nbr += next;
    }
    return (nbr);
}