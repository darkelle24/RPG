/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_inventory_4
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void init_item(scene_t *scene)
{
    int i = 2;
    text_t *text;

    while (i != 11) {
        text = text_find(scene->list_text, 800 + i);
        free(text->str);
        text->str = NULL;
        sfText_setString(text->text, "");
        text->disp = 0;
        i++;
    }
    sfText_setString(text_find(scene->list_text, 601)->text, "Status :");
    text_find(scene->list_text, 701)->disp = 0;
}

void button_hvex_item(button_t *button, IGNORE void *item_void)
{
    scene_t *scene = (scene_t *) button->to_send_click2;

    sfRectangleShape_setFillColor(button->rect, create_color
    (255, 255, 255, 100));
    sfRectangleShape_setOutlineColor(button->rect
    , create_color(255, 255, 255, 200));
    init_item(scene);
    button->pass = 1;
}

void add_effect(item_t *item, player_t *player, int type)
{
    if (type == 0) {
        player->stat->hp += item->stat->hp;
        player->stat->hp_max += item->stat->hp_max;
        player->stat->mana += item->stat->mana;
        player->stat->mana_max += item->stat->mana_max;
        player->stat->ad += item->stat->ad;
        player->stat->ap += item->stat->ap;
        player->stat->speed += item->stat->speed;
        player->stat->armor += item->stat->armor;
        player->stat->magic_resi += item->stat->magic_resi;
    } else {
        player->stat->hp -= item->stat->hp;
        player->stat->hp_max -= item->stat->hp_max;
        player->stat->mana -= item->stat->mana;
        player->stat->mana_max -= item->stat->mana_max;
        player->stat->ad -= item->stat->ad;
        player->stat->ap -= item->stat->ap;
        player->stat->speed -= item->stat->speed;
        player->stat->armor -= item->stat->armor;
        player->stat->magic_resi -= item->stat->magic_resi;
    }
}

void desa_all_button(rpg_t *rpg, scene_t *scene)
{
    int i = 1;
    text_t *text;
    text_list_t *list = scene->list_text;

    while (i != 16) {
        list = scene->list_text;
        button_invi_and_desac(button_find(scene->list_but, 200 + i));
        button_find(scene->list_but, 200 + i)->keyboard = 0;
        game_object_find(scene->list_ob, 200 + i)->display = 0;
        text = text_find(scene->list_text, 200 + i);
        while (list->text != text)
            list = list->next;
        text->disp = 0;
        list->next->text->disp = 0;
        list->next->next->text->disp = 0;
        list->next->next->next->text->disp = 0;
        list->next->next->next->next->text->disp = 0;
        list->next->next->next->next->next->text->disp = 0;
        i++;
    }
    init_item_inventory(rpg, scene);
}

void destroy_item(rpg_t *rpg, item_t *item, scene_t *scene)
{
    inventory_t *list = rpg->player->inventory;
    inventory_t *save;

    while (list->next != NULL && list->next->item != item)
        list = list->next;
    if (list->next != NULL) {
        save = list->next;
        list->next = list->next->next;
    } else {
        save = rpg->player->inventory;
        rpg->player->inventory = save->next;
    }
    free(save->item->stat);
    free(save->item->type);
    free(save->item->name);
    free(save->item);
    free(save);
    desa_all_button(rpg, scene);
}