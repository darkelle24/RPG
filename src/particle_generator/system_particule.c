/*
** EPITECH PROJECT, 2019
** system_particule
** File description:
** functions for manage system of particules
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "struct/particule.h"
#include "proto/proto.h"

void system_particule_3(sfRectangleShape *rect, particule_rect_t *rectangle)
{
    sfColor color;

    color = sfRectangleShape_getFillColor(rect);
    if (color.a - 10 > 0) {
        color.a -= 10;
        color.r -= 8;
    } else {
        color.a = 255;
        color.r = 255;
        rectangle->power = create_vect(-10, (rand() % 6) - 3);
        sfRectangleShape_setPosition(rect, create_vect(840, 560));
    }
    sfRectangleShape_setFillColor(rect, color);
}

void system_particule(particule_t *part)
{
    int i = 0;
    sfRectangleShape *rect;

    while (part->rect_list[i] != NULL && part->rect_list[i]->start) {
        rect = part->rect_list[i]->rect;
        sfRectangleShape_move(rect, part->rect_list[i]->power);
        part->rect_list[i]->power.x -= part->graviter;
        system_particule_3(rect, part->rect_list[i]);
        i++;
    }
    if (part->rect_list[i] != NULL)
        part->rect_list[i]->start = sfTrue;
}

void gestion_grav(particule_rect_t *rect, float grav)
{
    if (rect->power.x > 0)
        rect->power.x -= grav;
    else
        rect->power.x += grav;
    if (rect->power.y > 0)
        rect->power.y -= grav;
    else
        rect->power.y += grav;
}

void system_particule_2(particule_t *part)
{
    int i = 0;
    sfColor color;
    sfRectangleShape *rect;
    int active = 0;

    while (part->rect_list_2[i] != NULL && part->rect_list_2[i]->start) {
        rect = part->rect_list_2[i]->rect;
        sfRectangleShape_move(rect, part->rect_list_2[i]->power);
        gestion_grav(part->rect_list_2[i], part->graviter);
        color = sfRectangleShape_getFillColor(rect);
        if (color.a - 10 > 0) {
            color.a -= 10;
            color.b -= 6;
            active += 1;
        } else
            part->rect_list_2[i]->start = sfFalse;
        sfRectangleShape_setFillColor(rect, color);
        i++;
    }
    if (active == 0)
        part->start = sfFalse;
}