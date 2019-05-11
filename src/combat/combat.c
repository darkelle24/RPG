/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combat
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

void combat_shortcut_2(rpg_t *rpg, scene_t *scene, fight_t *fight)
{
    if (rpg->event.key.code == sfKeyR && fight->player->comp_3 != NULL)
        button_cl_combat_but_compt(button_find(scene->list_but, 6300)
        , (void *) fight);
    if (rpg->event.key.code == sfKeyI)
        goto_inventory(button_find(scene->list_but, 1105), (void *) rpg);
    if (rpg->event.key.code == sfKeyN)
        button_cl_combat_but_turn(button_find(scene->list_but, 1107)
        , (void *) fight);
    if (rpg->event.key.code == sfKeyF)
        button_cl_combat_but_flee(button_find(scene->list_but, 1106)
        , (void *) fight);
}

void combat_shortcut(rpg_t *rpg, scene_t *scene, fight_t *fight)
{
    if (rpg->event.type == sfEvtKeyReleased) {
        if (rpg->event.key.code == sfKeyA && fight->player->base != NULL)
            button_cl_combat_but_compt(button_find(scene->list_but, 6000)
            , (void *) fight);
        if (rpg->event.key.code == sfKeyZ && fight->player->comp_1 != NULL)
            button_cl_combat_but_compt(button_find(scene->list_but, 6100)
            , (void *) fight);
        if (rpg->event.key.code == sfKeyE && fight->player->comp_2 != NULL)
            button_cl_combat_but_compt(button_find(scene->list_but, 6200)
            , (void *) fight);
        combat_shortcut_2(rpg, scene, fight);
    }
}

void free_combat(fight_t *fight, scene_t *scene)
{
    free_scene(scene);
    free(fight->stat_temp_ennemy);
    free(fight->stat_temp_player);
    free(fight->reward);
    free(fight->ennemy->act);
    free(fight->ennemy);
    free(fight);
}

void check_death(fight_t *fight, rpg_t *rpg, int *back)
{
    if (fight->player->stat->hp <= 0) {
        *back = 1;
    } else if (fight->ennemy->act->hp <= 0) {
        reward_menu(rpg, fight);
        *back = 3;
    }
}

int combats(rpg_t *rpg, fight_t *fight)
{
    scene_t *scene = load_scene("src/parser/scene_files/combat.dji"
    , rpg->assets->tab_text[3]);
    int back = 0;

    if (scene == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window))
        combat_init(rpg, scene, &back, fight);
    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_for_button(rpg->event, scene, rpg->window);
            combat_shortcut(rpg, scene, fight);
            event_on_window(rpg);
        }
        sfRenderWindow_clear(rpg->window, sfBlack);
        display_list_display(rpg->window, scene->order);
        sfRenderWindow_display(rpg->window);
        check_death(fight, rpg, &back);
    }
    free_combat(fight, scene);
    return (back);
}