/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_inventory_1
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

void init_stat_2(rpg_t *rpg, scene_t *scene)
{
    text_t *text;

    text = text_find(scene->list_text, 707);
    text->str = inttochar(rpg->player->stat->ap);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 708);
    text->str = inttochar(rpg->player->stat->armor);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 709);
    text->str = inttochar(rpg->player->stat->magic_resi);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 710);
    text->str = inttochar(rpg->player->stat->speed);
    sfText_setString(text->text, text->str);
}

void init_stat(rpg_t *rpg, scene_t *scene)
{
    text_t *text;

    text = text_find(scene->list_text, 702);
    text->str = inttochar(rpg->player->stat->hp);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 703);
    text->str = inttochar(rpg->player->stat->hp_max);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 704);
    text->str = inttochar(rpg->player->stat->ad);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 705);
    text->str = inttochar(rpg->player->stat->mana);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 706);
    text->str = inttochar(rpg->player->stat->mana_max);
    sfText_setString(text->text, text->str);
    init_stat_2(rpg, scene);
}

void init_inventory_2(rpg_t *rpg, scene_t *scene)
{
    other_t *other;
    text_t *text;

    other = other_find(scene->other, 400);
    progress_bar_change_value((progress_bar_t *) other->other
    , ((float)rpg->player->stat->mana
    / (float)rpg->player->stat->mana_max) * 100);
    text = text_find(scene->list_text, 6);
    text->str = inttochar(rpg->player->lvl);
    sfText_setString(text->text, text->str);
    other = other_find(scene->other, 500);
    progress_bar_change_value((progress_bar_t *) other->other
    , ((float) rpg->player->xp
    / ((float) rpg->player->lvl * 10 + 100)) * 100);
}

void init_inventory(rpg_t *rpg, scene_t *scene, int *back)
{
    other_t *other;
    text_t *text = text_find(scene->list_text, 1000000);

    init_item_inventory(rpg, scene);
    other = other_find(scene->other, 300);
    progress_bar_change_value((progress_bar_t *) other->other
    , ((float)rpg->player->stat->hp / (float)rpg->player->stat->hp_max) * 100);
    init_inventory_2(rpg, scene);
    button_find(scene->list_but, 900)->to_send_click = (void *) back;
    button_find(scene->list_but, 901)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 9999)->to_send_click = (void *) scene;
    sfText_setString(text->text, rpg->player->name);
    init_stat(rpg, scene);
}