/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_create_player
*/

#include "proto/proto.h"
#include "other/macro.h"

void button_fc_cl_create_player_choose_class(button_t *but
, IGNORE void *rpg_void)
{
    scene_t *scene = (scene_t *) but->to_send_click2;

    if (but->id == 2100)
        hacker_init(scene);
    if (but->id == 2101)
        corsair_init(scene);
    if (but->id == 2102)
        cyborgs_init(scene);
}

void button_fc_cl_create_player_save(button_t *but, void *rpg_void)
{
    rpg_t *rpg = (rpg_t *) rpg_void;
    scene_t *scene = (scene_t *) but->to_send_click2;
    int *back = (int *) but->to_send_click3;
    text_t *text = text_find(scene->list_text, 10001);
    const char *name = sfText_getString(text->text);

    inti_player(rpg);
    if (name[1] == 'a')
        hacker_save(scene, rpg);
    if (name[1] == 'o')
        corsair_save(scene, rpg);
    if (name[1] == 'y')
        cyborgs_save(scene, rpg);
    rpg->mob_kill = 0;
    *back = 1;
}

void button_fc_hv_create_player_choose_class(button_t *but
, IGNORE void *rpg_void)
{
    sfRectangleShape_setOutlineColor(but->rect, create_color(130, 130
    , 130, 255));
    but->pass = 5;
}

void button_fc_hvex_create_player_choose_class(button_t *but
, IGNORE void *rpg_void)
{
    sfRectangleShape_setOutlineColor(but->rect, create_color(255, 255
    , 255, 255));
    but->pass = 1;
}

void button_fc_pr_create_player_choose_class(button_t *but
, IGNORE void *rpg_void)
{
    sfRectangleShape_setOutlineColor(but->rect, create_color(50, 50
    , 50, 50));
    but->pass = 6;
}