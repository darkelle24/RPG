/*
** EPITECH PROJECT, 2019
** competences_combat
** File description:
** functions for manage competences in combat
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

int set_compt_active_2(fight_t *fight, scene_t *scene
, competence_t *compt, int nbr)
{
    int desa = 0;

    if (fight->player->stat->mana >= compt->consumption)
        sfText_setColor(text_find(scene->list_text, 6002 + nbr * 100)->text
        , create_color(255, 255, 255, 255));
    else {
        sfText_setColor(text_find(scene->list_text, 6002 + nbr * 100)->text
        , create_color(255, 0, 0, 255));
        desa = 1;
    }
    if (fight->stat_temp_player->speed >= compt->speed)
        sfText_setColor(text_find(scene->list_text, 6003 + nbr * 100)->text
        , create_color(255, 255, 255, 255));
    else {
        sfText_setColor(text_find(scene->list_text, 6003 + nbr * 100)->text
        , create_color(255, 0, 0, 255));
        desa = 1;
    }
    return (desa);
}

void set_compt_active(fight_t *fight, scene_t *scene
, competence_t *compt, int nbr)
{
    text_t *text = text_find(scene->list_text, 6001 + nbr * 100);
    int desa = set_compt_active_2(fight, scene, compt, nbr);
    sfRectangleShape *rect = button_find(scene->list_but, 6000 + nbr
    * 100)->rect;

    if (fight->compt[nbr] != 0) {
        free(text->str);
        text->str = inttochar(fight->compt[nbr]);
        sfText_setString(text->text, text->str);
        text->disp = 1;
        desa = 1;
    } else
        text->disp = 0;
    if (desa == 1)
        sfRectangleShape_setFillColor(rect, create_color(105, 105, 105, 150));
    else {
        if (sfRectangleShape_getTexture(rect) != NULL)
            sfRectangleShape_setFillColor(rect, sfWhite);
        else
            sfRectangleShape_setFillColor(rect, sfTransparent);
    }
}

void init_compt_2(fight_t *fight, scene_t * scene, competence_t *compt, int nbr)
{
    text_t *text = text_find(scene->list_text, 6002 + nbr * 100);
    button_t *rect = button_find(scene->list_but, 6000 + nbr * 100);

    text->str = inttochar(compt->consumption);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 6003 + nbr * 100);
    text->str = inttochar(compt->speed);
    sfText_setString(text->text, text->str);
    sfRectangleShape_setTexture(rect->rect, find_texture(fight->list
    , compt->id_text), sfTrue);
    rect->to_send_click = (void *) fight;
    rect->to_send_click2 = (void *) scene;
    rect->to_send_click3 = (void *) compt;
    set_compt_active(fight, scene, compt, nbr);
}

void init_compt(fight_t *fight, scene_t * scene, competence_t *compt, int nbr)
{
    if (compt != NULL) {
        init_compt_2(fight, scene, compt, nbr);
    } else {
        button_invi_and_desac(button_find(scene->list_but, 6000 + nbr * 100));
        button_find(scene->list_but, 6000 + nbr * 100)->keyboard = 0;
        text_find(scene->list_text, 6001 + nbr * 100)->disp = 0;
        text_find(scene->list_text, 6002 + nbr * 100)->disp = 0;
        text_find(scene->list_text, 6003 + nbr * 100)->disp = 0;
        text_find(scene->list_text, 41000 + nbr)->disp = 0;
    }
}