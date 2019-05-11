/*
** EPITECH PROJECT, 2019
** ennemy_combat
** File description:
** functions for manage ennemies in combat
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"
#include "struct/music_sound.h"
#include "other/macro.h"

ennemy_t *find_ennemy(ennemy_t *list, int id)
{
    while (list != NULL && list->id != id)
        list = list->next;
    return (list);
}

stat_t *init_stat_ennemy(ennemy_t *ennemy, int lvl)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->hp_max = ennemy->stat_lvl_1->hp_max
    + (ennemy->stat_per_lvl->hp_max * ennemy->stat_lvl_1->hp_max * (lvl - 1));
    stat->hp = stat->hp_max;
    stat->ad = ennemy->stat_lvl_1->ad + (ennemy->stat_per_lvl->ad
    * ennemy->stat_lvl_1->ad * (lvl - 1));
    stat->ap = ennemy->stat_lvl_1->ap + (ennemy->stat_per_lvl->ap
    * ennemy->stat_lvl_1->ap * (lvl - 1));
    stat->armor = ennemy->stat_lvl_1->armor + (ennemy->stat_per_lvl->armor
    * ennemy->stat_lvl_1->armor * (lvl - 1));
    stat->mana_max = ennemy->stat_lvl_1->mana_max
    + (ennemy->stat_per_lvl->mana_max *
    ennemy->stat_lvl_1->mana_max * (lvl - 1));
    stat->mana = stat->mana_max;
    stat->magic_resi = ennemy->stat_lvl_1->magic_resi
    + (ennemy->stat_per_lvl->magic_resi
    * ennemy->stat_lvl_1->magic_resi * (lvl - 1));
    stat->speed = ennemy->stat_lvl_1->speed + (ennemy->stat_per_lvl->speed
    * ennemy->stat_lvl_1->speed * (lvl - 1));
    return (stat);
}