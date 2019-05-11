/*
** EPITECH PROJECT, 2019
** button_stat
** File description:
** functions for manaage buttons in stat scene
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

void activated_but(scene_t *scene)
{
    int i = 0;
    button_t *but;

    while (i != 7) {
        text_find(scene->list_text, 6003 + (i * 1000))->disp = 1;
        but = button_find(scene->list_but, 6002 + (i * 1000));
        but->keyboard = 1;
        but->pass = 1;
        i++;
    }
}
