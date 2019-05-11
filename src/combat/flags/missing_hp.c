/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** missing_hp
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"

int missing_hp(fight_t *fight, char *str, int target)
{
    float coeff = get_floatnbr(str);
    int nbr = 0;

    if (target == 1)
        nbr = (fight->ennemy->act->hp_max - fight->ennemy->act->hp) * coeff;
    else if (target == 2)
        nbr = (fight->player->stat->hp_max - fight->player->stat->hp) * coeff;
    return (nbr);
}