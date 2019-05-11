/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** scene_other_2
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "proto/proto.h"

other_t *other_find(other_t *list, int id)
{
    while (list != NULL && list->id != id) {
        list = list->next;
    }
    if (list == NULL)
        return (NULL);
    return (list);
}

void text_bar_add_rect_2(text_bar_t *text, char *phrase, scene_t *scene)
{
    char *path = path_recup(phrase);
    sfIntRect rect_text = rect_recup(phrase);
    sfTexture *texture = find_texture(scene->texture_list
    , find_nbr(phrase, "ID_text="));

    sfRectangleShape_setTextureRect(text->rect_text->rect, rect_text);
    if (path != NULL) {
        text->rect_text->text = sfTexture_createFromFile(path, NULL);
        sfRectangleShape_setTexture(text->rect_text->rect
        , text->rect_text->text, sfFalse);
        free(path);
    } else
        text->rect_text->text = NULL;
    if (texture != NULL) {
        sfRectangleShape_setTexture(text->rect_text->rect
        , texture, sfFalse);
    }
}

void text_bar_add_rect(text_bar_t *text, char *phrase, sfVector2f pos
, scene_t *scene)
{
    sfColor color = color_recup(phrase, "Color_Rec=");
    sfColor color_out = color_recup(phrase, "Color_RecOut=");
    int outlinethick = find_nbr(phrase, "Size_RecOut=");
    int ecart = find_nbr(phrase, "Offset_Rec=");
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, create_vect(text->rect.left
    - ecart, pos.y - ((text->rect.top - pos.y) / 2)));
    sfRectangleShape_setSize(rect, create_vect(text->rect.width + ecart
    + ecart, text->rect.height + (text->rect.top - pos.y) * 3.3));
    sfRectangleShape_setFillColor(rect, color);
    text->rect_text = malloc(sizeof(rectangle_t));
    text->rect_text->rect = rect;
    text_bar_add_rect_2(text, phrase, scene);
    sfRectangleShape_setOutlineColor(text->rect_text->rect, color_out);
    sfRectangleShape_setOutlineThickness(text->rect_text->rect, outlinethick);
}

void text_bar_2(text_bar_t *text, char *phrase, sfVector2f pos, scene_t *scene)
{
    int rect_disp = find_nbr(phrase, "Bool_rect=");
    int size_bar = find_nbr(phrase, "Size_Cursor=");
    sfColor color_cur = color_recup(phrase, "Color_Cursor=");

    text_bar_create_barre(text, size_bar, color_cur);
    if (rect_disp > 0)
        text_bar_add_rect(text, phrase, pos, scene);
    else
        text->rect_text = NULL;
}

void scene_text_bar(scene_t *scene, char *phrase)
{
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfColor color = color_recup(phrase, "Color=");
    int id = find_nbr(phrase, "ID=");
    int disp = find_nbr(phrase, "Disp=");
    int lenght_max = find_nbr(phrase, "Lenght_max=");
    int size = find_nbr(phrase, "Sizechar=");
    int prio = find_nbr(phrase, "Prio=");
    int ecart = find_nbr(phrase, "Offset=");
    text_bar_t *text_bar = create_text_bar(lenght_max
    , position, size, scene->font);
    other_t *other = other_list_add(&scene->other, (void *) text_bar, 't', id);

    sfText_setColor(text_bar->text, color);
    other->disp = disp;
    text_bar->ecart = ecart;
    text_bar_2(text_bar, phrase, position, scene);
    display_list_add_other(&scene->order, other, prio);
}