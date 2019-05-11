/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** final_boss
*/

#include "proto/proto.h"

void boss(rpg_t *rpg, map_t *map, char *str)
{
    int save = rpg->mob_kill;

    combats_analyse_str_call(rpg, map, str);
    if (save != rpg->mob_kill) {
        credit(rpg);
        map->go_to_menu = sfTrue;
    }
}