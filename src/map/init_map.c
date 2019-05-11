/*
** EPITECH PROJECT, 2019
** init_map
** File description:
** initiliase maps
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void map_init_quest(rpg_t *rpg, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 30001);

    free(text->str);
    text->str = str_append("(", inttochar(rpg->mob_kill), 0, 1);
    text->str = str_append(text->str, "/", 1, 0);
    text->str = str_append(text->str, "20)", 1, 0);
    sfText_setString(text->text, text->str);
    if (rpg->mob_kill >= 20)
        sfText_setColor(text->text, create_color(100, 100, 255, 255));
}

void map_init_all_value_2(rpg_t *rpg, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 301);
    progress_bar_t *prog = (progress_bar_t *)
    (other_find(scene->other, 300)->other);

    free(text->str);
    text->str = str_append(inttochar(rpg->player->stat->hp), "\\", 1, 0);
    text->str = str_append(text->str, inttochar(rpg->player->stat->hp_max)
    , 1, 1);
    sfText_setString(text->text, text->str);
    set_text_mid(text->text
    , sfRectangleShape_getGlobalBounds(prog->rect_ori));
    prog = (progress_bar_t *) (other_find(scene->other, 400)->other);
    text = text_find(scene->list_text, 401);
    free(text->str);
    text->str = str_append(inttochar(rpg->player->stat->mana), "\\", 1, 0);
    text->str = str_append(text->str, inttochar(rpg->player->stat->mana_max)
    , 1, 1);
    sfText_setString(text->text, text->str);
    set_text_mid(text->text
    , sfRectangleShape_getGlobalBounds(prog->rect_ori));
    map_init_quest(rpg, scene);
}

void map_init_all_value(rpg_t *rpg, scene_t *scene)
{
    other_t *other = other_find(scene->other, 300);
    text_t *text = text_find(scene->list_text, 601);

    progress_bar_change_value((progress_bar_t *) (other->other)
    , ((float)rpg->player->stat->hp / (float)rpg->player->stat->hp_max) * 100);
    other = other_find(scene->other, 400);
    progress_bar_change_value((progress_bar_t *) (other->other)
    , ((float)rpg->player->stat->mana
    / (float)rpg->player->stat->mana_max) * 100);
    other = other_find(scene->other, 600);
    progress_bar_change_value((progress_bar_t *) (other->other)
    , ((float) rpg->player->xp
    / ((float) rpg->player->lvl * 10 + 100)) * 100);
    free(text->str);
    text->str = inttochar(rpg->player->lvl);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 602);
    text->str = inttochar(rpg->player->lvl + 1);
    sfText_setString(text->text, text->str);
    map_init_all_value_2(rpg, scene);
}

void map_scene_init(rpg_t *rpg, scene_t *scene, map_t *map, int *back)
{
    text_t *text = text_find(scene->list_text, 1001);

    sfText_setString(text->text, rpg->player->name);
    button_find(scene->list_but, 22000)->to_send_click = (void *) scene;
    button_find(scene->list_but, 22000)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 23000)->to_send_click = (void *) scene;
    button_find(scene->list_but, 23000)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 24000)->to_send_click = (void *) scene;
    button_find(scene->list_but, 99001)->to_send_click = (void *) scene;
    button_find(scene->list_but, 99002)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 99002)->to_send_click2 = (void *) map;
    button_find(scene->list_but, 99003)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 99004)->to_send_click = (void *) back;
    button_find(scene->list_but, 99005)->to_send_click = (void *) rpg;
    map_init_all_value(rpg, scene);
}