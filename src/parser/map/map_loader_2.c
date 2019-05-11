/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_loader_2
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "struct/map.h"
#include "proto/proto.h"
#include "proto/lib.h"

void display_map(sfRenderWindow *window, map_t *map)
{
    entity_t *save = map->entity;

    sfRenderWindow_setView(window, map->view);
    sfRenderWindow_drawSprite(window, map->obj->sprite, NULL);
    while (save != NULL) {
        if (save->active != 0)
            sfRenderWindow_drawSprite(window, save->obj->sprite, NULL);
        save = save->next;
    }
    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
    sfRenderWindow_drawSprite(window, map->perso->sprite, NULL);
    sfRenderWindow_setView(window, map->view);
    sfRenderWindow_drawSprite(window, map->sup->sprite, NULL);
    sfRenderWindow_setView(window, sfRenderWindow_getDefaultView(window));
}

map_t *map_init(game_object *obj, game_object *perso, rpg_t *rpg
, scene_t *scene)
{
    map_t *map = malloc(sizeof(map_t));

    map->map = NULL;
    perso->last_anim = sfClock_getElapsedTime(rpg->game);
    map->last_anim = sfClock_getElapsedTime(rpg->game);
    map->layer_sup = NULL;
    map->sup = game_object_copy(obj, 0);
    map->block = NULL;
    map->entity = NULL;
    map->obj = obj;
    map->diag = NULL;
    map->scene = scene;
    map->talk = NULL;
    sfSprite_setOrigin(perso->sprite, create_vect(0, 0));
    map->perso = perso;
    map->view = sfView_copy(sfRenderWindow_getDefaultView(rpg->window));
    map->go_to_menu = sfFalse;
    return (map);
}

void layer_sup_set(map_t *map, sfRenderTexture *render)
{
    if (map->layer_sup != NULL)
        sfRenderTexture_destroy(map->layer_sup);
    sfSprite_setOrigin(map->sup->sprite, create_vect(0, 0));
    sfSprite_setPosition(map->sup->sprite, create_vect(0, 0));
    map->layer_sup = render;
    sfSprite_setTexture(map->sup->sprite, sfRenderTexture_getTexture(render)
    , sfTrue);
}

void map_set_to_game_object(char *path, texture_list_t *list
, map_t *map, sfVector2f pos)
{
    FILE *fp = fopen(path, "r");
    sfRenderTexture **render;

    if (fp == NULL)
        return ;
    render = map_create(list, fp, map, path);
    if (map->map != NULL)
        sfRenderTexture_destroy(map->map);
    sfSprite_setOrigin(map->obj->sprite, create_vect(0, 0));
    sfSprite_setPosition(map->obj->sprite, create_vect(0, 0));
    map->map = render[0];
    sfSprite_setTexture(map->obj->sprite, sfRenderTexture_getTexture(render[0])
    , sfTrue);
    layer_sup_set(map, render[1]);
    sfView_setCenter(map->view, pos);
    if (map->block != NULL)
        free_block(map);
    map_block(fp, map);
    if (map->entity != NULL)
        free_entity(map);
    map_entity(fp, map);
}

void map_render_texture_2(sfRenderTexture *render, sfTexture *texture
, int count, int a)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setPosition(sprite, create_vect(count * 64, a * 64));
    sfRenderTexture_drawSprite(render, sprite, NULL);
    sfRenderTexture_display(render);
    sfSprite_destroy(sprite);
}