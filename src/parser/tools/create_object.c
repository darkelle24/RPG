/*
** EPITECH PROJECT, 2019
** create_object.c
** File description:
** create_object.c
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct/game_object.h"
#include "proto/lib.h"

game_object *create_object(const char *path, sfVector2f pos,
sfIntRect rect, int type)
{
    game_object *object = malloc(sizeof(game_object));
    sfTexture *texture;

    object->sprite = sfSprite_create();
    if (path != NULL) {
        texture = sfTexture_createFromFile(path, NULL);
        if (!texture)
            return NULL;
        sfSprite_setTexture(object->sprite, texture, sfTrue);
        object->texture = texture;
    } else
        object->texture = NULL;
    sfSprite_setTextureRect(object->sprite, rect);
    sfSprite_setOrigin(object->sprite
    , create_vect((rect.width - rect.left) / 2, (rect.height - rect.top) / 2));
    sfSprite_setPosition(object->sprite, pos);
    object->id = type;
    return (object);
}

game_object *game_object_copy(game_object *to_copy, int display)
{
    game_object *object = malloc(sizeof(game_object));

    object->sprite = sfSprite_copy(to_copy->sprite);
    object->id = to_copy->id;
    object->display = display;
    return (object);
}

game_list *create_game_list(void)
{
    game_list *list = malloc(sizeof(game_list));

    if (list == NULL)
        return (NULL);
    list->object = NULL;
    list->next = NULL;
    return (list);
}

game_object *game_object_find(game_list *list_ob, int id)
{
    while (list_ob != NULL && list_ob->object != NULL
    && list_ob->object->id != id) {
        list_ob = list_ob->next;
    }
    if (list_ob == NULL)
        return (NULL);
    return (list_ob->object);
}

int game_list_add(game_list *list, game_object *object)
{
    while (list->next != NULL)
        list = list->next;
    if (list->object == NULL)
        list->object = object;
    else {
        list->next = malloc(sizeof(game_list));
        if (list->next == NULL)
            return (-1);
        list->next->object = object;
        list->next->next = NULL;
    }
    return (0);
}