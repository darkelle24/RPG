/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_inventory_2
*/

#include "proto/proto.h"
#include "other/macro.h"

void button_hvex_quit(button_t *button, IGNORE void *rpg_void)
{
    sfRectangleShape_setFillColor(button->rect, create_color(200, 0, 0, 255));
    button->pass = 1;
}

void button_pr_return(button_t *button, IGNORE void *back_void)
{
    sfRectangleShape_setFillColor(button->rect, create_color(0, 0, 100, 255));
    button->pass = 6;
}

void button_pr_quit(button_t *button, IGNORE void *rpg_void)
{
    sfRectangleShape_setFillColor(button->rect, create_color(100, 0, 0, 255));
    button->pass = 6;
}

void button_pr_item(button_t *button, IGNORE void *unused)
{
    sfRectangleShape_setFillColor(button->rect
    , create_color(255, 255, 255, 200));
    sfRectangleShape_setOutlineColor(button->rect
    , create_color(255, 255, 255, 100));
    button->pass = 6;
}