/*
** EPITECH PROJECT, 2019
** button_fc_inventory_trash
** File description:
** functions for manage button trash in inventory
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void button_cl_inventory_trash(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    sfColor color = sfRectangleShape_getOutlineColor(but->rect);
    button_list_t *list = scene->list_but;

    while (list != NULL && list->button->id != 201)
        list = list->next;
    if (color.b == 0) {
        while (list != NULL && list->button->id != 215) {
            list->button->callback_click_release = &button_cl_item;
            list = list->next;
        }
        list->button->callback_click_release = &button_cl_item;
        sfRectangleShape_setOutlineColor(but->rect, sfWhite);
    } else if (color.b != 0) {
        while (list != NULL && list->button->id != 215) {
            list->button->callback_click_release = &destroy_item_fc;
            list = list->next;
        }
        list->button->callback_click_release = &destroy_item_fc;
        sfRectangleShape_setOutlineColor(but->rect, sfRed);
    }
}

void button_ho_inventory_trash(button_t *but, IGNORE void *scene_void)
{
    sfColor color = sfRectangleShape_getOutlineColor(but->rect);

    color.r = 150;
    if (color.b != 0)
        color.b = 150;
    if (color.g != 0)
        color.g = 150;
    sfRectangleShape_setOutlineColor(but->rect, color);
    but->pass = 5;
}

void button_pr_inventory_trash(button_t *but, IGNORE void *scene_void)
{
    sfColor color = sfRectangleShape_getOutlineColor(but->rect);

    color.r = 50;
    if (color.b != 0)
        color.b = 50;
    if (color.g != 0)
        color.g = 50;
    sfRectangleShape_setOutlineColor(but->rect, color);
    but->pass = 6;
}

void button_hoex_inventory_trash(button_t *but, IGNORE void *scene_void)
{
    sfColor color = sfRectangleShape_getOutlineColor(but->rect);

    color.r = 255;
    if (color.b != 0)
        color.b = 255;
    if (color.g != 0)
        color.g = 255;
    sfRectangleShape_setOutlineColor(but->rect, color);
    but->pass = 1;
}