/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** door_of_the_boss
*/

#include "proto/proto.h"

void door_of_boss(rpg_t *rpg, map_t *map, char *str)
{
    if (rpg->mob_kill >= 20)
        change_map(rpg, map, str);
    else
        dialogue_init(rpg, map, "assets/dialogue/door_of_boss");
}