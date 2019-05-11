/*
** EPITECH PROJECT, 2019
** menu_parallax
** File description:
** functions for move sprite of the parallax menu
*/

#include "struct/game_struct.h"
#include "proto/proto.h"

void display_floor(scene_t *scene_cine)
{
    sfVector2f pos_floor;
    sfVector2f scnd_pos_floor;
    game_object *floor_one = game_object_find(scene_cine->list_ob, 1);
    game_object *floor_two = game_object_find(scene_cine->list_ob, 2);

    sfSprite_move(floor_one->sprite, create_vect(-10, 0));
    sfSprite_move(floor_two->sprite, create_vect(-10, 0));
    pos_floor = sfSprite_getPosition(floor_one->sprite);
    scnd_pos_floor = sfSprite_getPosition(floor_two->sprite);
    if (pos_floor.x <= -960)
        sfSprite_setPosition(floor_one->sprite, create_vect(2880, 990));
    if (scnd_pos_floor.x <= -960)
        sfSprite_setPosition(floor_two->sprite, create_vect(2880, 990));
}

void display_city(scene_t *scene_cine)
{
    sfVector2f pos_city;
    sfVector2f scnd_pos_city;
    game_object *city_one = game_object_find(scene_cine->list_ob, 3);
    game_object *city_two = game_object_find(scene_cine->list_ob, 4);

    sfSprite_move(city_one->sprite, create_vect(-5, 0));
    sfSprite_move(city_two->sprite, create_vect(-5, 0));
    pos_city = sfSprite_getPosition(city_one->sprite);
    scnd_pos_city = sfSprite_getPosition(city_two->sprite);
    if (pos_city.x <= -960)
        sfSprite_setPosition(city_one->sprite, create_vect(2880, 920));
    if (scnd_pos_city.x <= -960)
        sfSprite_setPosition(city_two->sprite, create_vect(2880, 920));
}

void display_second_city(scene_t *scene_cine)
{
    sfVector2f pos_city;
    sfVector2f scnd_pos_city;
    game_object *city_one = game_object_find(scene_cine->list_ob, 5);
    game_object *city_two = game_object_find(scene_cine->list_ob, 6);

    sfSprite_move(city_one->sprite, create_vect(-3, 0));
    sfSprite_move(city_two->sprite, create_vect(-3, 0));
    pos_city = sfSprite_getPosition(city_one->sprite);
    scnd_pos_city = sfSprite_getPosition(city_two->sprite);
    if (pos_city.x <= -960)
        sfSprite_setPosition(city_one->sprite, create_vect(2880, 1070));
    if (scnd_pos_city.x <= -960)
        sfSprite_setPosition(city_two->sprite, create_vect(2880, 1070));
}

void display_parallax(scene_t *scene_cine, rpg_t *rpg)
{
    sfTime mtime = sfClock_getElapsedTime(rpg->game);
    game_object *city_one = game_object_find(scene_cine->list_ob, 5);

    mtime.microseconds = mtime.microseconds - city_one->last_anim.microseconds;
    if (mtime.microseconds >= 15000) {
        while (mtime.microseconds >= 15000) {
            display_floor(scene_cine);
            display_city(scene_cine);
            display_second_city(scene_cine);
            mtime.microseconds -= 15000;
        }
        city_one->last_anim = sfClock_getElapsedTime(rpg->game);
    }
}