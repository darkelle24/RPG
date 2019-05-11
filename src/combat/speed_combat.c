/*
** EPITECH PROJECT, 2019
** speed_combat
** File description:
** functions for manage the speed attack in combat
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"
#include "struct/music_sound.h"
#include "other/macro.h"

void set_speed_player(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 1212);

    free(text->str);
    text->str = inttochar(fight->stat_temp_player->speed);
    sfText_setString(text->text, text->str);
}

void set_speed_ennemy(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 1312);

    free(text->str);
    text->str = inttochar(fight->stat_temp_ennemy->speed);
    sfText_setString(text->text, text->str);
}

void set_speed_2(scene_t *scene, float pourc_player)
{
    text_t *text = text_find(scene->list_text, 1213);
    progress_bar_t *prog = ((progress_bar_t *) other_find(scene->other
    , 91000)->other);

    free(text->str);
    text->str = str_append(inttochar((int) pourc_player), " %", 1, 0);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 1313);
    free(text->str);
    text->str = str_append(inttochar(100 - (int) pourc_player), " %"
    , 1, 0);
    sfText_setString(text->text, text->str);
    progress_bar_change_value(prog, pourc_player);
}

void set_speed(fight_t *fight, scene_t *scene)
{
    float pourc_player = ((float)fight->stat_temp_player->speed
    / (float)fight->speed_total) * 100;

    if (pourc_player <= 50)
        fight->stat_temp_ennemy->speed += (50 - pourc_player) / 100
        * fight->speed_total;
    else
        fight->stat_temp_player->speed += (pourc_player - 50) / 100
        * fight->speed_total;
    set_speed_player(fight, scene);
    set_speed_ennemy(fight, scene);
    set_speed_2(scene, pourc_player);
}