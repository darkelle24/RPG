/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_entity_2
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "struct/map.h"
#include "proto/proto.h"
#include "proto/lib.h"

entity_t *create_entity(char *str)
{
    sfVector2f pos_obj = pos_object_recup_str(str, "Pos_obj=");
    sfVector2f pos_rect = pos_object_recup_str(str, "Pos_rect=");
    sfVector2f size = pos_object_recup_str(str, "Size_rect=");
    sfIntRect rect = rect_recup(str);
    int id = find_nbr(str, "ID=");
    char *path = recup_str_spe(str, "Path_obj=\"", '\"');
    char *effect = recup_str_spe(str, "Effect=\"", '\"');
    game_object *obj = create_object(path, pos_obj, rect, id);
    entity_t *new = malloc(sizeof(entity_t));

    new->obj = obj;
    new->rect_contact = create_frect(pos_rect.y, pos_rect.x, size.x, size.y);
    new->str = effect;
    new->id = id;
    new->active = find_nbr(str, "Active=");
    link_fc(str, new);
    free(path);
    return (new);
}