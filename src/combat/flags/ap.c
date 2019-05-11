/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ap
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"

int ap(fight_t *fight, char *str, int target)
{
    float coeff = get_floatnbr(str);
    int nbr = 0;

    if (target == 1)
        nbr = (fight->player->stat->ap + fight->stat_temp_player->ap) * coeff;
    else if (target == 2)
        nbr = (fight->ennemy->act->ap + fight->stat_temp_ennemy->ap) * coeff;
    return (nbr);
}