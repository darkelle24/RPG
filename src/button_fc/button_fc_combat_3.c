/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_combat_3
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"
#include "other/macro.h"

void change_stat(fight_t *fight)
{
    fight->turn++;
    fight->stat_temp_player->speed += fight->stat_temp_player->speed / 6
    + fight->player->stat->speed / 8;
    fight->stat_temp_ennemy->speed += fight->stat_temp_ennemy->speed / 4
    + fight->ennemy->act->speed / 6;
    fight->ennemy->act->mana += fight->ennemy->act->mana_max / 25;
    fight->player->stat->mana += fight->player->stat->mana_max / 25;
    if (fight->ennemy->act->mana > fight->ennemy->act->mana_max
    + fight->stat_temp_ennemy->mana_max)
        fight->ennemy->act->mana = fight->ennemy->act->mana_max
        + fight->stat_temp_ennemy->mana_max;
    if (fight->player->stat->mana > fight->player->stat->mana_max
    + fight->stat_temp_player->mana_max)
        fight->player->stat->mana = fight->player->stat->mana_max
        + fight->stat_temp_player->mana_max;
}

void actualise_compt(fight_t *fight, scene_t *scene)
{
    if (fight->player->base != NULL)
        set_compt_active(fight, scene, fight->player->base, 0);
    if (fight->player->comp_1 != NULL)
        set_compt_active(fight, scene, fight->player->comp_1, 1);
    if (fight->player->comp_2 != NULL)
        set_compt_active(fight, scene, fight->player->comp_2, 2);
    if (fight->player->comp_3 != NULL)
        set_compt_active(fight, scene, fight->player->comp_3, 3);
}

void button_cl_combat_but_turn(button_t *but, void *fight_void)
{
    fight_t *fight = (void *) fight_void;
    scene_t *scene = (void *) but->to_send_click2;
    int i = 0;

    ennemy_turn(fight, scene);
    change_stat(fight);
    refresh_other_info(fight, scene);
    while (i != 8) {
        if (fight->compt[i] != 0)
            fight->compt[i]--;
        i++;
    }
    actualise_compt(fight, scene);
    init_ath_player(fight, scene);
    init_ath_ennemy(fight, scene);
}

void button_cl_combat_but_flee(button_t *but, void *fight_void)
{
    fight_t *fight = (fight_t *) fight_void;
    scene_t *scene = (scene_t *) but->to_send_click3;
    int *back = (int *) but->to_send_click2;
    int pour = ((float)fight->stat_temp_player->speed
    / (float)fight->speed_total) * 100;

    if (rand() % 101 > 100 - pour + 10)
        *back = 2;
    else {
        fight->stat_temp_player->speed = fight->stat_temp_player->speed / 2;
        button_cl_combat_but_turn(button_find(scene->list_but, 1107)
        , (void *) fight);
    }
}