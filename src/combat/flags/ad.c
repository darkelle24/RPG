/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ad
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"

int ad(fight_t *fight, char *str, int target)
{
    float coeff = get_floatnbr(str);
    int nbr = 0;

    if (target == 1)
        nbr = (fight->player->stat->ad + fight->stat_temp_player->ad) * coeff;
    else if (target == 2)
        nbr = (fight->ennemy->act->ad + fight->stat_temp_ennemy->ad) * coeff;
    return (nbr);
}