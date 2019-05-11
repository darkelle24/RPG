/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** circle_lib
*/

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/CircleShape.h>
#include "proto/lib.h"
#include "proto/proto.h"

sfCircleShape *create_circle(sfVector2f pos, float rad, float th, sfColor col)
{
    sfCircleShape *circle = sfCircleShape_create();

    sfCircleShape_setOrigin(circle, create_vect(rad, rad));
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, rad);
    sfCircleShape_setOutlineThickness(circle, th);
    sfCircleShape_setOutlineColor(circle, col);
    sfCircleShape_setFillColor(circle, create_color(0, 0, 0, 0));
    return (circle);
}

void rectangle_free(void *rectangle_void)
{
    rectangle_t *rect = (rectangle_t *) rectangle_void;

    if (rect->text != NULL)
        sfTexture_destroy(rect->text);
    sfRectangleShape_destroy(rect->rect);
}

void rectangle_display(other_t *other, sfRenderWindow *window)
{
    sfRenderWindow_drawRectangleShape(window
    , ((rectangle_t *)other->other)->rect, NULL);
}

sfRectangleShape *create_rectangle(sfVector2f pos
, sfVector2f size, sfColor col)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, pos);
    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setFillColor(rect, col);
    return (rect);
}