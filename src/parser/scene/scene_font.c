/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** scene_font
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "proto/proto.h"

void scene_font(scene_t *scene, char *phrase)
{
    char *path = path_recup(phrase);
    sfFont *font = sfFont_createFromFile(path);

    scene->font = font;
    free(path);
}