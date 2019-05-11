/*
** EPITECH PROJECT, 2019
** cinematic
** File description:
** functions for display the cinematic
*/

#include <time.h>
#include "struct/game_struct.h"
#include "proto/proto.h"

void display_cinematic_text(scene_t *scene_cinematic, rpg_t *rpg, int *back)
{
    game_object *text_one = game_object_find(scene_cinematic->list_ob, 5);
    game_object *cine_char = game_object_find(scene_cinematic->list_ob, 3);
    sfTime mtime = sfClock_getElapsedTime(rpg->game);

    sfSprite_setTextureRect(cine_char->sprite, create_rect(0, 0, 32, 48));
    if (mtime.microseconds - text_one->last_anim.microseconds < 45000000) {
        if (mtime.microseconds - text_one->last_anim.microseconds < 15000000)
            text_one->display = 1;
        else if (mtime.microseconds - text_one->last_anim.microseconds
        > 15000000 && mtime.microseconds -
        text_one->last_anim.microseconds < 23000000) {
            game_object_find(scene_cinematic->list_ob, 6)->display = 1;
            text_one->display = 0;
        } else {
            game_object_find(scene_cinematic->list_ob, 6)->display = 0;
            game_object_find(scene_cinematic->list_ob, 7)->display = 1;
            if (mtime.microseconds - text_one->last_anim.microseconds
            > 33000000)
                *back = 1;
        }
    }
}

void display_character_2(scene_t *scene_cinematic, rpg_t *rpg, int *back)
{
    game_object *cine_char = game_object_find(scene_cinematic->list_ob, 3);
    sfVector2f pos_char = sfSprite_getPosition(cine_char->sprite);
    sfIntRect rect_pos_char = sfSprite_getTextureRect(cine_char->sprite);

    if (pos_char.x != 790) {
        sfSprite_move(cine_char->sprite, create_vect(10, 0));
        rect_pos_char.left = rect_pos_char.left + 32;
        if (rect_pos_char.left >= 128)
            rect_pos_char.left = 0;
        sfSprite_setTextureRect(cine_char->sprite, rect_pos_char);
    }
    if (pos_char.x >= 760) {
        sfSprite_setPosition(cine_char->sprite, create_vect(760, 950));
        display_cinematic_text(scene_cinematic, rpg, back);
    }
}

void display_character(scene_t *scene_cinematic, rpg_t *rpg, int *back)
{
    game_object *cine_char = game_object_find(scene_cinematic->list_ob, 3);
    int time_one = sfClock_getElapsedTime(rpg->game).microseconds;

    if (time_one - cine_char->last_anim.microseconds >= 150000) {
        while (time_one - cine_char->last_anim.microseconds >= 150000) {
            display_character_2(scene_cinematic, rpg, back);
            time_one -= 150000;
        }
        cine_char->last_anim = sfClock_getElapsedTime(rpg->game);
    }
}

void init_cinematic(scene_t *scene_cinematic, rpg_t *rpg)
{
    game_object_find(scene_cinematic->list_ob, 3)->last_anim
    = sfClock_getElapsedTime(rpg->game);
    game_object_find(scene_cinematic->list_ob, 5)->last_anim
    = sfClock_getElapsedTime(rpg->game);
}

void cinematic(rpg_t *rpg)
{
    scene_t *scene_cinematic = load_scene(rpg->assets->tab_scene[4],
    rpg->assets->tab_text[3]);
    int back = 0;

    init_cinematic(scene_cinematic, rpg);
    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_for_button(rpg->event, scene_cinematic, rpg->window);
            event_on_window(rpg);
            if (rpg->event.type == sfEvtKeyReleased
            && rpg->event.key.code == sfKeySpace)
                back = 1;
        }
        if (back == 0) {
            display_character(scene_cinematic, rpg, &back);
            display_list_display(rpg->window, scene_cinematic->order);
            sfRenderWindow_display(rpg->window);
        }
    }
    free_scene(scene_cinematic);
}