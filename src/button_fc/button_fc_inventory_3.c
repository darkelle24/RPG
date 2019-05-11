/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_inventory_3
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void place_text_stat(scene_t *scene, text_t *to_change, int to_display)
{
    char *str = NULL;
    text_t *find = text_find(scene->list_text, to_change->id - 100);
    sfFloatRect rect = sfText_getGlobalBounds(find->text);

    sfText_setPosition(to_change->text
    , create_vect(rect.left + rect.width, rect.top - 9));
    if (to_display > 0) {
        sfText_setFillColor(to_change->text, create_color(0, 0, 250, 255));
        sfText_setStyle(to_change->text, sfTextBold);
        str = " (+";
    } else {
        sfText_setFillColor(to_change->text, create_color(250, 0, 0, 255));
        sfText_setStyle(to_change->text, sfTextBold);
        str = " (";
    }
    str = str_append(str, inttochar(to_display), 0, 1);
    to_change->str = str_append(str, ")", 1, 0);
    sfText_setString(to_change->text, to_change->str);
    to_change->disp = 1;
}

void diff_item_2(scene_t *scene, item_t *item)
{
    text_t *text;

    text = text_find(scene->list_text, 808);
    if (item->stat->armor != 0)
        place_text_stat(scene, text, item->stat->armor);
    text = text_find(scene->list_text, 809);
    if (item->stat->magic_resi != 0)
        place_text_stat(scene, text, item->stat->magic_resi);
    text = text_find(scene->list_text, 810);
    if (item->stat->speed != 0)
        place_text_stat(scene, text, item->stat->speed);
    sfText_setString(text_find(scene->list_text, 601)->text, "Item :");
    text = text_find(scene->list_text, 701);
    sfText_setString(text->text, item->name);
    text->disp = 1;
}

void diff_item(scene_t *scene, item_t *item)
{
    text_t *text;

    text = text_find(scene->list_text, 802);
    if (item->stat->hp != 0)
        place_text_stat(scene, text, item->stat->hp);
    text = text_find(scene->list_text, 803);
    if (item->stat->hp_max != 0)
        place_text_stat(scene, text, item->stat->hp_max);
    text = text_find(scene->list_text, 804);
    if (item->stat->ad != 0)
        place_text_stat(scene, text, item->stat->ad);
    text = text_find(scene->list_text, 805);
    if (item->stat->mana != 0)
        place_text_stat(scene, text, item->stat->mana);
    text = text_find(scene->list_text, 806);
    if (item->stat->mana_max != 0)
        place_text_stat(scene, text, item->stat->mana_max);
    text = text_find(scene->list_text, 807);
    if (item->stat->ap != 0)
        place_text_stat(scene, text, item->stat->ap);
    diff_item_2(scene, item);
}

void button_hv_item(button_t *button, void *item_void)
{
    scene_t *scene = (scene_t *) button->to_send_click2;
    item_t *item = (item_t *) item_void;

    sfRectangleShape_setFillColor(button->rect
    , create_color(255, 255, 255, 150));
    sfRectangleShape_setOutlineColor(button->rect
    , create_color(255, 255, 255, 250));
    diff_item(scene, item);
    button->pass = 5;
}