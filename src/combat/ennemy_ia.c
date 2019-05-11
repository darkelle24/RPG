/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ennemy_ia
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"

static int calcul_damage_ap(fight_t *fight, competence_t *compt)
{
    int ap = 1;

    if (compt->degatap != NULL) {
        ap = calcul_flag(fight, compt->degatap, 2);
        ap -= (fight->player->stat->magic_resi
        + fight->stat_temp_player->magic_resi) * 2;
        if (ap < 0)
            ap = 0;
        ap = ap * -1;
    }
    return (ap);
}

static int calcul_damage_ad(fight_t *fight, competence_t *compt)
{
    int ad = 1;

    if (compt->degatad != NULL) {
        ad = calcul_flag(fight, compt->degatad, 2);
        ad -= (fight->player->stat->armor
        + fight->stat_temp_player->armor) * 2;
        if (ad < 0)
            ad = 0;
        ad = ad * -1;
    }
    return (ad);
}

static int calcul_heal(fight_t *fight, competence_t *compt)
{
    int heal = -1;

    if (compt->heal != NULL)
        heal = calcul_flag(fight, compt->heal, 2);
    return (heal);
}

int use_compt_ennemy(fight_t *fight, scene_t *scene, int compt_choose)
{
    competence_t *compt = link_compt(fight, compt_choose);
    sfSound *sound = sound_find(scene->list_sound, compt->id_sound);
    int damageap;
    int damagead;

    if (sound != NULL)
        sfSound_play(sound);
    damageap = calcul_damage_ap(fight, compt);
    damagead = calcul_damage_ad(fight, compt);
    fight->ennemy->act->hp += calcul_heal(fight, compt);
    if (fight->ennemy->act->hp > fight->ennemy->act->hp_max
    + fight->stat_temp_ennemy->hp_max)
        fight->ennemy->act->hp = fight->ennemy->act->hp_max
        + fight->stat_temp_ennemy->hp_max;
    fight->player->stat->hp += damagead + damageap;
    fight->compt[compt_choose + 4] = compt->cooldown;
    fight->ennemy->act->mana -= compt->consumption;
    fight->stat_temp_ennemy->speed -= compt->speed;
    init_ath_player(fight, scene);
    init_ath_ennemy(fight, scene);
    return (0);
}

void ennemy_turn(fight_t *fight, scene_t *scene)
{
    int valid_compt[4] = {0, 0 , 0, 0};
    int value_choose = 0;

    while (value_choose != -1) {
        valid_compt[0] = test_is_okay_compt(fight
        , fight->ennemy->ennemy->compt_1, 0);
        valid_compt[1] = test_is_okay_compt(fight
        , fight->ennemy->ennemy->compt_2, 1);
        valid_compt[2] = test_is_okay_compt(fight
        , fight->ennemy->ennemy->compt_3, 2);
        valid_compt[3] = test_is_okay_compt(fight
        , fight->ennemy->ennemy->compt_4, 3);
        value_choose = ennemy_choose_compt(valid_compt);
        if (value_choose != -1)
            use_compt_ennemy(fight, scene, value_choose);
    }
}