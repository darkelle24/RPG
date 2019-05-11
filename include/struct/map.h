/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

#include <SFML/Graphics.h>
#include "struct/scene.h"
#include "struct/game_struct.h"
#include "struct/game_object.h"

    typedef struct entity_s entity_t;

    typedef struct block_invi_s
    {
        sfFloatRect rect;
        struct block_invi_s *next;
    }       block_invi_t;

    typedef struct map_s
    {
        char *path;
        sfRenderTexture *map;
        sfRenderTexture *layer_sup;
        game_object *obj;
        game_object *sup;
        game_object *perso;
        block_invi_t *block;
        entity_t *entity;
        sfView *view;
        scene_t *scene;
        sfTime last_anim;
        FILE *diag;
        entity_t *talk;
        sfBool go_to_menu;
    }     map_t;

    struct entity_s
    {
        sfFloatRect rect_contact;
        game_object *obj;
        char *str;
        int id;
        int active;
        void (*fc)(rpg_t *, map_t *map, char *);
        struct entity_s *next;
    };

#endif /* !MAP_H_ */
