/*
** EPITECH PROJECT, 2019
** ennemy_ia_comp
** File description:
** functions for manage competences of ennemy IA
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"

int test_is_okay_compt(fight_t *fight, competence_t *compt
, int nbr)
{
    if (compt == NULL)
        return (0);
    if (fight->compt[4 + nbr] != 0)
        return (0);
    if (compt->consumption > fight->ennemy->act->mana)
        return (0);
    if (compt->speed > fight->stat_temp_ennemy->speed)
        return (0);
    return (1);
}

int ennemy_choose_compt_2(int valid_compt[4], int choose_value)
{
    int i = 0;
    int nbr_value = 0;

    while (i != 4) {
        if (valid_compt[i] == 1)
            nbr_value++;
        if (nbr_value == choose_value)
            return (i);
        i++;
    }
    return (-1);
}

int ennemy_choose_compt(int valid_compt[4])
{
    int i = 0;
    int choose_value = 0;
    int nbr_value = 0;

    while (i != 4) {
        if (valid_compt[i] == 1)
            nbr_value++;
        i++;
    }
    if (nbr_value != 0) {
        choose_value = (rand() % nbr_value) + 1;
        return (ennemy_choose_compt_2(valid_compt, choose_value));
    } else
        return (-1);
}

competence_t *link_compt(fight_t *fight, int compt_choose)
{
    if (compt_choose == 0)
        return (fight->ennemy->ennemy->compt_1);
    if (compt_choose == 1)
        return (fight->ennemy->ennemy->compt_2);
    if (compt_choose == 2)
        return (fight->ennemy->ennemy->compt_3);
    return (fight->ennemy->ennemy->compt_4);
}