/*
** EPITECH PROJECT, 2019
** init_combat
** File description:
** functions for initialise ath in combat
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

void inith_ath_player_ene(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 401);
    text_t *text_2 = text_find(scene->list_text, 1206);
    progress_bar_t *prog = ((progress_bar_t *) other_find
    (scene->other, 1201)->other);

    free(text->str);
    text->str = str_append(inttochar(fight->player->stat->mana), "\\", 1, 0);
    text->str = str_append(text->str, inttochar(fight->player->stat->mana_max)
    , 1, 1);
    sfText_setString(text->text, text->str);
    sfText_setString(text_2->text, text->str);
    set_text_mid(text_2->text
    , sfRectangleShape_getGlobalBounds(prog->rect_ori));
    progress_bar_change_value(prog, ((float)fight->player->stat->mana
    / (float)fight->player->stat->mana_max) * 100);
    prog = ((progress_bar_t *) other_find(scene->other, 400)->other);
    progress_bar_change_value(prog, ((float)fight->player->stat->mana
    / (float)fight->player->stat->mana_max) * 100);
}

void init_ath_player(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 301);
    text_t *text_2 = text_find(scene->list_text, 1205);
    progress_bar_t *prog = ((progress_bar_t *) other_find
    (scene->other, 1202)->other);

    free(text->str);
    text->str = str_append(inttochar(fight->player->stat->hp), "\\", 1, 0);
    text->str = str_append(text->str, inttochar(fight->player->stat->hp_max)
    , 1, 1);
    sfText_setString(text->text, text->str);
    sfText_setString(text_2->text, text->str);
    set_text_mid(text_2->text
    , sfRectangleShape_getGlobalBounds(prog->rect_ori));
    progress_bar_change_value(prog, ((float)fight->player->stat->hp
    / (float)fight->player->stat->hp_max) * 100);
    prog = ((progress_bar_t *) other_find(scene->other, 300)->other);
    progress_bar_change_value(prog, ((float)fight->player->stat->hp
    / (float)fight->player->stat->hp_max) * 100);
    inith_ath_player_ene(fight, scene);
}

void init_ath_ennemy_ene(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 1306);
    progress_bar_t *prog = ((progress_bar_t *) other_find
    (scene->other, 1301)->other);

    free(text->str);
    text->str = str_append(inttochar(fight->ennemy->act->mana), "\\", 1, 0);
    text->str = str_append(text->str, inttochar(fight->ennemy->act->mana_max)
    , 1, 1);
    sfText_setString(text->text, text->str);
    set_text_mid(text->text
    , sfRectangleShape_getGlobalBounds(prog->rect_ori));
    progress_bar_change_value(prog, ((float)fight->ennemy->act->mana
    / (float)fight->ennemy->act->mana_max) * 100);
}

void init_ath_ennemy(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 1305);
    progress_bar_t *prog = ((progress_bar_t *) other_find
    (scene->other, 1302)->other);

    free(text->str);
    text->str = str_append(inttochar(fight->ennemy->act->hp), "\\", 1, 0);
    text->str = str_append(text->str, inttochar(fight->ennemy->act->hp_max)
    , 1, 1);
    sfText_setString(text->text, text->str);
    set_text_mid(text->text
    , sfRectangleShape_getGlobalBounds(prog->rect_ori));
    progress_bar_change_value(prog, ((float)fight->ennemy->act->hp
    / (float)fight->ennemy->act->hp_max) * 100);
    init_ath_ennemy_ene(fight, scene);
}

void init_ath_info(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 1204);

    sfText_setString(text_find(scene->list_text, 201)->text
    , fight->player->name);
    sfText_setString(text_find(scene->list_text, 1200)->text
    , fight->player->name);
    text->str = inttochar(fight->player->lvl);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 1304);
    text->str = inttochar(fight->ennemy->lvl);
    sfText_setString(text->text, text->str);
    sfText_setString(text_find(scene->list_text, 1300)->text
    , fight->ennemy->ennemy->name);
}
