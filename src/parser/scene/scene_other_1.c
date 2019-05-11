/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** scene_other_1
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "struct/progress_bar.h"
#include "proto/proto.h"

other_t *other_list_add(other_t **list, void *other, char type, int id)
{
    other_t *new = malloc(sizeof(other_t));
    other_t *save = *list;

    while (*list && (*list)->next != NULL)
        *list = (*list)->next;
    new->next = NULL;
    new->type = type;
    new->id = id;
    new->other = other;
    if (*list == NULL)
        *list = new;
    else {
        (*list)->next = new;
        *list = save;
    }
    return (new);
}

void scene_volume_bar(scene_t *scene, char *phrase)
{
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfVector2f size = pos_object_recup_str(phrase, "Size=");
    sfColor color_unact = color_recup(phrase, "Color_Unact=");
    sfColor color_act = color_recup(phrase, "Color_Act=");
    sfColor color_out = color_recup(phrase, "Color_Out=");
    int outlinethick = find_nbr(phrase, "Size_Out=");
    int volume = find_nbr(phrase, "Vol=");
    int prio = find_nbr(phrase, "Prio=");
    int disp = find_nbr(phrase, "Disp=");
    int id = find_nbr(phrase, "ID=");
    volume_bar_t *vol = volume_bar_init(position, size, volume);
    other_t *other = other_list_add(&scene->other, (void *) vol, 'V', id);

    other->disp = disp;
    vol->unactive = color_unact;
    sfRectangleShape_setOutlineColor(vol->rect_ori, color_out);
    sfRectangleShape_setOutlineThickness(vol->rect_ori, outlinethick);
    vol->active = color_act;
    sfRectangleShape_setFillColor(vol->rect, vol->unactive);
    display_list_add_other(&scene->order, other, prio);
}

void rect_2(char *phrase, scene_t *scene, rectangle_t *rect_strct
, sfRectangleShape *rect)
{
    char *path = path_recup(phrase);
    sfTexture *texture = find_texture(scene->texture_list
    , find_nbr(phrase, "ID_text="));

    rect_strct->rect = rect;
    if (path != NULL) {
        rect_strct->text = sfTexture_createFromFile(path, NULL);
        sfRectangleShape_setTexture(rect, rect_strct->text, sfFalse);
        free(path);
    } else
        rect_strct->text = NULL;
    if (texture != NULL)
        sfRectangleShape_setTexture(rect, texture, sfFalse);
}

void scene_rectangle(scene_t *scene, char *phrase)
{
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfVector2f size = pos_object_recup_str(phrase, "Size=");
    sfColor color = color_recup(phrase, "Color=");
    sfColor color_out = color_recup(phrase, "Color_Out=");
    int outlinethick = find_nbr(phrase, "Size_Out=");
    int prio = find_nbr(phrase, "Prio=");
    int disp = find_nbr(phrase, "Disp=");
    int id = find_nbr(phrase, "ID=");
    sfIntRect rect_text = rect_recup(phrase);
    sfRectangleShape *rect = create_rectangle(position, size, color);
    rectangle_t *rect_strct = malloc(sizeof(rectangle_t));
    other_t *other;

    rect_2(phrase, scene, rect_strct, rect);
    other = other_list_add(&scene->other, (void *) rect_strct, 'R', id);
    sfRectangleShape_setTextureRect(rect_strct->rect, rect_text);
    other->disp = disp;
    sfRectangleShape_setOutlineColor(rect_strct->rect, color_out);
    sfRectangleShape_setOutlineThickness(rect_strct->rect, outlinethick);
    display_list_add_other(&scene->order, other, prio);
}