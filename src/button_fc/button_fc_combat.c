/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_goto
*/

#include "proto/proto.h"
#include "other/macro.h"

void goto_inventory(button_t *but, void *rpg_void)
{
    inventory((rpg_t *) rpg_void);
    init_ath_player((fight_t *)but->to_send_click3
    , (scene_t *)but->to_send_click2);
}

void button_hv_combat_but_aux(button_t *but, IGNORE void *useless)
{
    sfRectangleShape_setFillColor(but->rect, create_color(100, 100, 100, 150));
    sfRectangleShape_setOutlineColor(but->rect
    , create_color(175, 175, 175, 200));
    but->pass = 5;
}

void button_hvex_combat_but_aux(button_t *but, IGNORE void *useless)
{
    sfRectangleShape_setFillColor(but->rect, create_color(150, 150, 150, 150));
    sfRectangleShape_setOutlineColor(but->rect
    , create_color(255, 255, 255, 200));
    but->pass = 1;
}

void button_pr_combat_but_aux(button_t *but, IGNORE void *useless)
{
    sfRectangleShape_setFillColor(but->rect, create_color(0, 0, 0, 150));
    sfRectangleShape_setOutlineColor(but->rect
    , create_color(255, 255, 255, 200));
    but->pass = 6;
}