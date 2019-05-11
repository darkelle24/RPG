/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_combat_5
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"
#include "other/macro.h"

int calcul_damage_ap_player(fight_t *fight, competence_t *compt)
{
    int ap = 1;

    if (compt->degatap != NULL) {
        ap = calcul_flag(fight, compt->degatap, 1);
        ap -= (fight->ennemy->act->magic_resi
        + fight->stat_temp_ennemy->magic_resi);
        if (ap < 0)
            ap = 0;
        ap = ap * -1;
    }
    return (ap);
}

int calcul_damage_ad_player(fight_t *fight, competence_t *compt)
{
    int ad = 1;

    if (compt->degatad != NULL) {
        ad = calcul_flag(fight, compt->degatad, 1);
        ad -= (fight->ennemy->act->armor
        + fight->stat_temp_ennemy->armor);
        if (ad < 0)
            ad = 0;
        ad = ad * -1;
    }
    return (ad);
}

int calcul_heal_player(fight_t *fight, competence_t *compt)
{
    int heal = -1;

    if (compt->heal != NULL)
        heal = calcul_flag(fight, compt->heal, 1);
    return (heal);
}

void disp_damage(scene_t *scene, fight_t *fight, competence_t *compt)
{
    text_t *text = text_find(scene->list_text, 1308);
    int damageap = calcul_damage_ap_player(fight, compt);
    int damagead = calcul_damage_ad_player(fight, compt);

    if (damagead != 1) {
        free(text->str);
        text->str = inttochar(damagead);
        sfText_setString(text->text, text->str);
        sfText_setColor(text->text, create_color(237, 26, 173, 255));
        text->disp = 1;
    }
    if (damageap != 1) {
        if (damagead != 1)
            text = text_find(scene->list_text, 1307);
        free(text->str);
        text->str = inttochar(damageap);
        sfText_setString(text->text, text->str);
        sfText_setColor(text->text, create_color(0, 255, 174, 255));
        text->disp = 1;
    }
}

void button_hv_combat_but_compt(button_t *but, void *fight_void)
{
    fight_t *fight = (fight_t *) fight_void;
    scene_t *scene = (scene_t *) but->to_send_click2;
    competence_t *compt = (competence_t *) but->to_send_click3;
    int heal = calcul_heal_player(fight, compt);
    text_t *text = text_find(scene->list_text, 1208);

    disp_damage(scene, fight, compt);
    if (heal != -1) {
        free(text->str);
        if (heal > 0)
            text->str = str_append("+", inttochar(heal), 0, 1);
        else
            text->str = inttochar(heal);
        sfText_setString(text->text, text->str);
        sfText_setColor(text->text, create_color(7, 49, 237, 255));
        text->disp = 1;
    }
    sfRectangleShape_setOutlineColor(but->rect
    , create_color(145, 145, 145, 200));
    but->pass = 5;
}