/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** init_inventory_2
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

void set_part(item_t *item, scene_t *scene)
{
    int value = -1;

    if ((value = strfind(item->type, "Head")) != -1) {
        sfSprite_setTexture(game_object_find(scene->list_ob, 2001)->sprite
        , find_texture(scene->texture_list, item->id_texture), sfTrue);
    }
    if (value == -1 && (value = strfind(item->type, "Weapon")) != -1) {
        sfSprite_setTexture(game_object_find(scene->list_ob, 2004)->sprite
        , find_texture(scene->texture_list, item->id_texture), sfTrue);
    }
    if (value == -1 && (value = strfind(item->type, "Chestplate")) != -1) {
        sfSprite_setTexture(game_object_find(scene->list_ob, 2002)->sprite
        , find_texture(scene->texture_list, item->id_texture), sfTrue);
    }
    if (value == -1 && (value = strfind(item->type, "Boots")) != -1) {
        sfSprite_setTexture(game_object_find(scene->list_ob, 2003)->sprite
        , find_texture(scene->texture_list, item->id_texture), sfTrue);
    }
}