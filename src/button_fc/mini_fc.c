/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** mini_fc
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdio.h>
#include "other/macro.h"
#include "proto/lib.h"
#include "proto/proto.h"
#include "struct/button.h"
#include "struct/color.h"
#include "struct/game_object.h"
#include "struct/music_sound.h"
#include "struct/scene.h"
#include "struct/text.h"
#include "struct/volume_bar.h"

void fc_hover(button_t *but, IGNORE void *lol)
{
    sfRectangleShape_setOutlineThickness(but->rect, 6);
    sfRectangleShape_setOutlineColor(but->rect, sfWhite);
    but->pass = 5;
}

void fc_hover_exit(button_t *but, IGNORE void *lol)
{
    sfRectangleShape_setOutlineThickness(but->rect, 6);
    sfRectangleShape_setOutlineColor(but->rect
    , create_color(180, 180, 180, 255));
    but->pass = 1;
}

void fc_click_press(button_t *but, IGNORE void *lol)
{
    sfRectangleShape_setOutlineColor(but->rect
    , create_color(100, 0, 100, 255));
    but->pass = 6;
}

void print(button_t *boutton, IGNORE void *lol)
{
    my_put_nbr(boutton->id);
    sfRectangleShape_setOutlineThickness(boutton->rect, 6);
    sfRectangleShape_setOutlineColor(boutton->rect
    , create_color(180, 180, 180, 255));
    boutton->pass = 1;
}