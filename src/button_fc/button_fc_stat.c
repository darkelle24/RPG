/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_stat
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

int *detect_stat(int id, stat_t *stat)
{
    if (id == 1)
        return (&stat->hp_max);
    if (id == 2)
        return (&stat->mana_max);
    if (id == 3)
        return (&stat->ap);
    if (id == 4)
        return (&stat->ad);
    if (id == 5)
        return (&stat->armor);
    if (id == 6)
        return (&stat->magic_resi);
    if (id == 7)
        return (&stat->speed);
    return (NULL);
}

void but_fc_cl_stat(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    rpg_t *rpg = (rpg_t *) but->to_send_click2;
    int *value = detect_stat(but->id / 1000 - 5, rpg->player->stat);

    if (rpg->player->point > 0) {
        *value = *value + 1;
        rpg->player->point--;
        set_one_stat(scene, *value, but->id - 1);
        set_one_stat(scene, rpg->player->point, 5000);
        if (rpg->player->point == 0)
            desactivated_but(scene);
    }
}

void but_fc_pr_stat(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    rpg_t *rpg = (rpg_t *) but->to_send_click2;

    if (rpg->player->point > 0) {
        sfRectangleShape_setOutlineColor(but->rect, create_color(70, 70, 70
        , 255));
        sfText_setColor(text_find(scene->list_text, but->id + 1)->text
        , create_color(70, 70, 70, 255));
        but->pass = 6;
    }
}

void but_fc_hv_stat(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    rpg_t *rpg = (rpg_t *) but->to_send_click2;

    if (rpg->player->point > 0) {
        sfRectangleShape_setOutlineColor(but->rect, create_color(170, 170, 170
        , 255));
        sfText_setColor(text_find(scene->list_text, but->id + 1)->text
        , create_color(170, 170, 170, 255));
        but->pass = 5;
    }
}

void but_fc_hvex_stat(button_t *but, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    rpg_t *rpg = (rpg_t *) but->to_send_click2;

    if (rpg->player->point > 0) {
        sfRectangleShape_setOutlineColor(but->rect, create_color(255, 255, 255
        , 255));
        sfText_setColor(text_find(scene->list_text, but->id + 1)->text
        , create_color(255, 255, 255, 255));
        but->pass = 1;
    }
}