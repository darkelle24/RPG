/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_menu_2
*/

#include "proto/proto.h"
#include "other/macro.h"

void button_hvex_menu_option(button_t *but, IGNORE void *rpg_void)
{
    sfRectangleShape_setOutlineColor(but->rect, create_color(0, 0, 255, 255));
    but->pass = 1;
}

void button_cl_menu_howtoplay(IGNORE button_t *but, void *scene_null)
{
    scene_t *scene = (scene_t *) scene_null;

    game_object_find(scene->list_ob, 30)->display = 1;
}