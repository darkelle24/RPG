/*
** EPITECH PROJECT, 2019
** init_combat
** File description:
** functions for initialise combat
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

void combat_init(rpg_t *rpg, scene_t *scene, int *back, fight_t *fight)
{
    button_find(scene->list_but, 901)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 1105)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 1105)->to_send_click2 = (void *) scene;
    button_find(scene->list_but, 1105)->to_send_click3 = (void *) fight;
    button_find(scene->list_but, 1106)->to_send_click = (void *) fight;
    button_find(scene->list_but, 1106)->to_send_click2 = (void *) back;
    button_find(scene->list_but, 1106)->to_send_click3 = (void *) scene;
    button_find(scene->list_but, 1107)->to_send_click2 = (void *) scene;
    button_find(scene->list_but, 1107)->to_send_click = (void *) fight;
    init_ath_info(fight, scene);
    init_ath_player(fight, scene);
    init_ath_ennemy(fight, scene);
    refresh_other_info(fight, scene);
    init_compt(fight, scene, fight->player->base, 0);
    init_compt(fight, scene, fight->player->comp_1, 1);
    init_compt(fight, scene, fight->player->comp_2, 2);
    init_compt(fight, scene, fight->player->comp_3, 3);
    set_sound(scene, rpg);
}

stat_t *init_stat_combat(int speed)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->ad = 0;
    stat->ap = 0;
    stat->armor = 0;
    stat->hp = 0;
    stat->hp_max = 0;
    stat->magic_resi = 0;
    stat->mana = 0;
    stat->mana_max = 0;
    stat->speed = speed;
    return (stat);
}