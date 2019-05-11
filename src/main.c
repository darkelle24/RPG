/*
** EPITECH PROJECT, 2019
** main
** File description:
** main function for my_rpg program
*/

#include <stdio.h>
#include "proto/proto.h"

int main(int ac, char **av)
{
    int checker = 0;

    (void)av;
    if (ac > 2)
        return (84);
    checker = play_rpg(av[1]);
    if (checker == 1)
        return (84);
    else
        return (0);
}