/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player_movement
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"

sfBool test_block(map_t *map, game_object *obj
, sfVector2f pos_add)
{
    block_invi_t *list = map->block;
    sfFloatRect frect = sfSprite_getGlobalBounds(obj->sprite);
    sfVector2f pos = sfView_getCenter(map->view);

    pos.x += pos_add.x;
    pos.y += pos_add.y;
    frect.left = pos.x;
    frect.top = pos.y;
    while (list != NULL) {
        if (sfFloatRect_intersects(&list->rect, &frect, NULL) == sfTrue)
            return (sfFalse);
        list = list->next;
    }
    return (sfTrue);
}

void deplacement_3(map_t *map, game_object *obj, rpg_t *rpg, int deplace)
{
    sfIntRect rect;

    if (deplace == 1)
        entity_trigger(map, rpg);
    else {
        rect = sfSprite_getTextureRect(obj->sprite);
        rect.left = 0;
        sfSprite_setTextureRect(obj->sprite, rect);
        map->last_anim = sfClock_getElapsedTime(rpg->game);
    }
}

void deplacement_2(map_t *map, game_object *obj, rpg_t *rpg)
{
    int deplace = 0;

    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        move_down(map, obj, rpg);
        deplace = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        move_up(map, obj, rpg);
        deplace = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        move_left(map, obj, rpg);
        deplace = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        move_right(map, obj, rpg);
        deplace = 1;
    }
    deplacement_3(map, obj, rpg, deplace);
}

void deplacement(map_t *map, game_object *obj, rpg_t *rpg)
{
    sfTime mtime = sfClock_getElapsedTime(rpg->game);

    mtime.microseconds = mtime.microseconds - obj->last_anim.microseconds;
    if (mtime.microseconds >= 15000) {
        while (mtime.microseconds >= 15000) {
            deplacement_2(map, obj, rpg);
            mtime.microseconds -= 15000;
        }
        obj->last_anim = sfClock_getElapsedTime(rpg->game);
    }
}