/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_option
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void button_cl_save_opt(button_t *button, void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    rpg_t *rpg = (rpg_t *) button->to_send_click2;
    FILE *fp = fopen(".option", "w");
    char *value = ((text_bar_t *)(other_find(scene->other, 300)->other))->str;

    if (is_nbr(value) == 0)
        rpg->option->fps = getnbr(value);
    rpg->option->music_volume = ((volume_bar_t *)
    (other_find(scene->other, 201)->other))->volume;
    rpg->option->sound_volume = ((volume_bar_t *)
    (other_find(scene->other, 202)->other))->volume;
    my_fprintf(fp, "fps=%d music=%d sound=%d ", rpg->option->fps
    , rpg->option->music_volume, rpg->option->sound_volume);
    sfRenderWindow_setFramerateLimit(rpg->window, rpg->option->fps);
    fclose(fp);
    sfMusic_setVolume(rpg->music_neon, rpg->option->music_volume);
}

void button_hv_save_opt(button_t *button, IGNORE void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    text_t *text = text_find(scene->list_text, button->id);

    sfRectangleShape_setFillColor(button->rect
    , create_color(210, 210, 210, 255));
    sfText_setColor(text->text, create_color(0, 0, 0, 255));
    button->pass = 5;
}

void button_hvex_save_opt(button_t *button, IGNORE void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    text_t *text = text_find(scene->list_text, button->id);

    sfRectangleShape_setFillColor(button->rect
    , create_color(170, 170, 170, 255));
    sfRectangleShape_setOutlineColor(button->rect, sfWhite);
    sfText_setColor(text->text, create_color(0, 0, 0, 255));
    button->pass = 1;
}

void button_pr_save_opt(button_t *button, IGNORE void *scene_void)
{
    scene_t *scene = (scene_t *) scene_void;
    text_t *text = text_find(scene->list_text, button->id);

    sfText_setColor(text->text, create_color(170, 170, 170, 255));
    sfRectangleShape_setFillColor(button->rect
    , create_color(100, 100, 100, 255));
    sfRectangleShape_setOutlineColor(button->rect
    , create_color(150, 150, 150, 255));
    button->pass = 6;
}

void button_rl_key_opt(button_t *button, IGNORE void *scene_void)
{
    rpg_t *rpg = (rpg_t *) button->to_send_click2;

    key_biding(rpg);
}