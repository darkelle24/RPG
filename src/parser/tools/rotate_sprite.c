/*
** EPITECH PROJECT, 2019
** rotate_sprite
** File description:
** rotate_sprite
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include <stdio.h>
#include <math.h>

double calcula_angle(sfSprite *to_rotate, sfVector2f target_pos)
{
    sfVector2f rotate_pos = sfSprite_getPosition(to_rotate);
    float deltay = rotate_pos.y - target_pos.y;
    float deltax = rotate_pos.x - target_pos.x;

    return (atan2(-deltay, -deltax) * (180 / acos(-1)));
}

void sprite_rotate(sfSprite *to_rotate, sfVector2f pos, float angle_of_start)
{
    float angle = sfSprite_getRotation(to_rotate);
    double calcul_angle = calcula_angle(to_rotate, pos) - angle_of_start;

    if (calcul_angle < 0)
        calcul_angle = 360 + calcul_angle;
    if (angle != calcul_angle) {
        sfSprite_setRotation(to_rotate, calcul_angle);
    }
}