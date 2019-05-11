/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_map
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void button_cl_map_inventory(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    rpg_t *rpg = (rpg_t *) but->to_send_click2;

    inventory(rpg);
    map_init_all_value(rpg, scene);
}

void button_cl_map_stat(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    rpg_t *rpg = (rpg_t *) but->to_send_click2;

    stat_display(rpg);
    map_init_all_value(rpg, scene);
}

void button_cl_map_pause(IGNORE button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    int i = 1;
    button_t *butt;

    text_find(scene->list_text, 99020)->disp = 1;
    other_find(scene->other, 99000)->disp = 1;
    while (i != 6) {
        butt = button_find(scene->list_but, 99000 + i);
        button_activate(butt, create_color(130, 130, 130, 255));
        sfRectangleShape_setOutlineColor(butt->rect, sfWhite);
        button_find(scene->list_but, 99000 + i)->keyboard = 1;
        text_find(scene->list_text, 99010 + i)->disp = 1;
        i++;
    }
}

void button_cl_map_resume(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    int i = 1;

    text_find(scene->list_text, 99020)->disp = 0;
    other_find(scene->other, 99000)->disp = 0;
    while (i != 6) {
        button_invi_and_desac(button_find(scene->list_but, 99000 + i));
        button_find(scene->list_but, 99000 + i)->keyboard = 0;
        text_find(scene->list_text, 99010 + i)->disp = 0;
        i++;
    }
    but->pass = 4;
}

void button_cl_map_option(IGNORE button_t *but, void *rpg_void)
{
    rpg_t *rpg = (rpg_t *) rpg_void;

    option(rpg);
}