/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_inventory_5
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void change_effect(rpg_t *rpg, scene_t *scene)
{
    other_t *other;

    if (rpg->player->stat->hp > rpg->player->stat->hp_max)
        rpg->player->stat->hp = rpg->player->stat->hp_max;
    if (rpg->player->stat->mana > rpg->player->stat->mana_max)
        rpg->player->stat->mana = rpg->player->stat->mana_max;
    other = other_find(scene->other, 300);
    progress_bar_change_value((progress_bar_t *) other->other
    , ((float)rpg->player->stat->hp / (float)rpg->player->stat->hp_max) * 100);
    other = other_find(scene->other, 400);
    progress_bar_change_value((progress_bar_t *) other->other
    , ((float)rpg->player->stat->mana
    / (float)rpg->player->stat->mana_max) * 100);
}

void desequipped(item_t *item, scene_t *scene, rpg_t *rpg)
{
    int i = 1;
    inventory_t *list = rpg->player->inventory;
    int value = -1;

    while (list->item != item) {
        i++;
        list = list->next;
    }
    text_find(scene->list_text, 1200 + i)->disp = 0;
    if ((value = strfind(item->type, "Head")) != -1)
        game_object_find(scene->list_ob, 2001)->display = 0;
    if (value == -1 && (value = strfind(item->type, "Weapon")) != -1)
        game_object_find(scene->list_ob, 2004)->display = 0;
    if (value == -1 && (value = strfind(item->type, "Chestplate")) != -1)
        game_object_find(scene->list_ob, 2002)->display = 0;
    if (value == -1 && (value = strfind(item->type, "Boots")) != -1)
        game_object_find(scene->list_ob, 2003)->display = 0;
    add_effect(item, rpg->player, 1);
    item->equiped = sfFalse;
    init_spe_stat(rpg, scene);
    change_effect(rpg, scene);
}

void test_desequipped(item_t *item, scene_t *scene, rpg_t *rpg)
{
    inventory_t *list = rpg->player->inventory;
    item_t *save = NULL;

    while (list != NULL && save == NULL) {
        if (list->item->equiped == sfTrue
        && strfind(list->item->type, item->type) != -1)
            save = list->item;
        list = list->next;
    }
    if (save != NULL)
        desequipped(save, scene, rpg);
}

void button_cl_item(button_t *button, void *item_void)
{
    item_t *item = (item_t *) item_void;
    scene_t *scene = (scene_t *) button->to_send_click2;
    rpg_t *rpg = (rpg_t *) button->to_send_click3;

    if (strfind(item->type, "Usage") != -1) {
        item->nbr -= 1;
        add_effect(item, rpg->player, 0);
        change_effect(rpg, scene);
        init_spe_stat(rpg, scene);
        if (item->nbr == 0) {
            destroy_item(rpg, item, scene);
            button->callback_hover = NULL;
        } else
            change_nbr(item, scene, rpg->player->inventory);
    } else {
        if (item->equiped == sfTrue)
            desequipped(item, scene, rpg);
        else
            equipped(item, scene, rpg);
    }
}