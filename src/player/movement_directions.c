/*
** EPITECH PROJECT, 2019
** movement directions
** File description:
** functions for display movement animation when player is walking
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"

void move_up(map_t *map, game_object *obj, rpg_t *rpg)
{
    sfIntRect rect = sfSprite_getTextureRect(obj->sprite);
    sfTime mtime = sfClock_getElapsedTime(rpg->game);

    if (test_block(map, obj, create_vect(0, -3)) == sfTrue)
        sfView_move(map->view, create_vect(0, -3));
    if (mtime.microseconds - map->last_anim.microseconds >= 70000) {
        if (rect.top != 144) {
            rect.top = 144;
            rect.left = 32;
        }
        rect.left += 32;
        if (rect.left > 96)
            rect.left = 32;
        sfSprite_setTextureRect(obj->sprite, rect);
        map->last_anim.microseconds += 70000;
    }
}

void move_left(map_t *map, game_object *obj, rpg_t *rpg)
{
    sfIntRect rect = sfSprite_getTextureRect(obj->sprite);
    sfTime mtime = sfClock_getElapsedTime(rpg->game);

    if (test_block(map, obj, create_vect(-3, 0)) == sfTrue)
        sfView_move(map->view, create_vect(-3, 0));
    if (mtime.microseconds - map->last_anim.microseconds >= 70000) {
        if (rect.top != 48) {
            rect.top = 48;
            rect.left = 32;
        }
        rect.left += 32;
        if (rect.left > 96)
            rect.left = 32;
        sfSprite_setTextureRect(obj->sprite, rect);
        map->last_anim.microseconds += 70000;
    }
}

void move_right(map_t *map, game_object *obj, rpg_t *rpg)
{
    sfIntRect rect = sfSprite_getTextureRect(obj->sprite);
    sfTime mtime = sfClock_getElapsedTime(rpg->game);

    if (test_block(map, obj, create_vect(3, 0)) == sfTrue)
        sfView_move(map->view, create_vect(3, 0));
    if (mtime.microseconds - map->last_anim.microseconds >= 70000) {
        if (rect.top != 96) {
            rect.top = 96;
            rect.left = 32;
        }
        rect.left += 32;
        if (rect.left > 96)
            rect.left = 32;
        sfSprite_setTextureRect(obj->sprite, rect);
        map->last_anim.microseconds += 70000;
    }
}

void move_down(map_t *map, game_object *obj, rpg_t *rpg)
{
    sfIntRect rect = sfSprite_getTextureRect(obj->sprite);
    sfTime mtime = sfClock_getElapsedTime(rpg->game);

    if (test_block(map, obj, create_vect(0, 3)) == sfTrue)
        sfView_move(map->view, create_vect(0, 3));
    if (mtime.microseconds - map->last_anim.microseconds >= 70000) {
        if (rect.top != 0) {
            rect.top = 0;
            rect.left = 32;
        }
        rect.left += 32;
        if (rect.left > 96)
            rect.left = 32;
        sfSprite_setTextureRect(obj->sprite, rect);
        map->last_anim.microseconds += 70000;
    }
}