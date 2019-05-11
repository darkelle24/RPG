/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_entity
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "struct/map.h"
#include "proto/proto.h"
#include "proto/lib.h"
#include "other/fc_for_entity.h"

void add_entity(entity_t **list, entity_t *add)
{
    entity_t *save = *list;

    while (*list && (*list)->next != NULL)
        *list = (*list)->next;
    add->next = NULL;
    if (*list == NULL)
        *list = add;
    else {
        (*list)->next = add;
        *list = save;
    }
}

void link_fc(char *str, entity_t *new)
{
    int pos = strfind(str, "Contact=");
    char *find;
    int i = 0;

    if (pos != -1) {
        find = recup_str(str, pos - 1, ' ');
        while (fc_entity_name[i] != NULL
        && strfind(fc_entity_name[i], find) == -1) {
            i++;
        }
        free(find);
        if (fc_entity_name[i] == NULL)
            new->fc = NULL;
        new->fc = fonction_entity[i];
    }
}

void map_entity(FILE *fp, map_t *map)
{
    char *buff = NULL;
    size_t size = 0;
    entity_t *entity;

    while (getline(&buff, &size, fp) != -1 && buff != NULL && (buff[0] == 'E'
    || buff[0] == '#')) {
        if (buff[0] != '#') {
            entity = create_entity(buff);
            add_entity(&map->entity, entity);
        }
        free(buff);
        buff = NULL;
        size = 0;
    }
}

void entity_trigger(map_t *map, rpg_t *rpg)
{
    entity_t *save = map->entity;
    sfFloatRect frect = sfSprite_getGlobalBounds(map->perso->sprite);
    sfVector2f pos = sfView_getCenter(map->view);

    frect.left = pos.x;
    frect.top = pos.y;
    while (save != NULL) {
        if (save->fc != NULL
        && save->active != 0 && sfFloatRect_intersects(&save->rect_contact
        , &frect, NULL) == sfTrue) {
            save->fc(rpg, map, save->str);
            map_init_all_value(rpg, map->scene);
            return ;
        }
        save = save->next;
    }
}

void free_entity(map_t *map)
{
    entity_t *save;

    while (map->entity != NULL) {
        save = map->entity;
        sfTexture_destroy(save->obj->texture);
        sfSprite_destroy(save->obj->sprite);
        free(save->obj);
        free(save->str);
        map->entity = map->entity->next;
        free(save);
    }
}