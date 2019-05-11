/*
** EPITECH PROJECT, 2019
** destroy_object.c
** File description:
** destroy_object.c
*/

#include <SFML/Graphics/Texture.h>
#include <SFML/Graphics/Sprite.h>
#include <stdlib.h>
#include "struct/game_object.h"

void destroy_object(game_object *obj, int nb, sfTexture **texture)
{
    int count = 0;

    if (nb > 1) {
        while (nb > count) {
            sfTexture_destroy(texture[count]);
            count++;
        }
    }
    sfSprite_destroy(obj->sprite);
    free(obj);
}