/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_combat_2
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"
#include "other/macro.h"
#include "other/fc_for_compt.h"

int calcul_flag(fight_t *fight, char *effect, int target)
{
    char **tab = seperate(my_strdup(effect), ';');
    int nbr = 0;
    int i = 0;
    int a = 1;

    nbr += getnbr(tab[0]);
    while (tab[a] != NULL) {
        i = 0;
        while (i != -1 && flag_name[i] != NULL) {
            if (strfind(tab[a], flag_name[i]) != -1) {
                nbr += fonction_flag[i](fight, tab[a], target);
                i = -2;
            }
            i++;
        }
        a++;
    }
    free(tab[0]);
    free(tab);
    return (nbr);
}

void button_hvex_combat_but_compt(button_t *but, IGNORE void *fight_void)
{
    scene_t *scene = (scene_t *) but->to_send_click2;

    text_find(scene->list_text, 1308)->disp = 0;
    text_find(scene->list_text, 1307)->disp = 0;
    text_find(scene->list_text, 1208)->disp = 0;
    text_find(scene->list_text, 1207)->disp = 0;
    sfRectangleShape_setOutlineColor(but->rect
    , create_color(225, 225, 225, 255));
    but->pass = 1;
}

void button_pr_combat_but_compt(button_t *but, IGNORE void *useless)
{
    if (sfRectangleShape_getFillColor(but->rect).a != 150) {
        sfRectangleShape_setOutlineColor(but->rect
        , create_color(50, 50, 50, 200));
        but->pass = 6;
    }
}

int combat(fight_t *fight, competence_t *compt, button_t *but)
{
    int damageap = calcul_damage_ap_player(fight, compt);
    int damagead = calcul_damage_ad_player(fight, compt);
    int nbr = (but->id - 6000) / 100;

    fight->player->stat->hp += calcul_heal_player(fight, compt);
    if (fight->player->stat->hp > fight->player->stat->hp_max
    + fight->stat_temp_player->hp_max)
        fight->player->stat->hp = fight->player->stat->hp_max
        + fight->stat_temp_player->hp_max;
    if (damagead == 1)
        damagead = 0;
    if (damageap == 1)
        damageap = 0;
    fight->ennemy->act->hp += damagead + damageap;
    fight->compt[nbr] = compt->cooldown;
    return (nbr);
}

void button_cl_combat_but_compt(button_t *but, void *fight_void)
{
    fight_t *fight = (fight_t *) fight_void;
    scene_t *scene = (scene_t *) but->to_send_click2;
    competence_t *compt = (competence_t *) but->to_send_click3;
    sfSound *sound = sound_find(scene->list_sound, compt->id_sound);
    int nbr = 0;

    if (sfRectangleShape_getFillColor(but->rect).a != 150) {
        if (sound != NULL)
            sfSound_play(sound);
        nbr = combat(fight, compt, but);
        fight->player->stat->mana -= compt->consumption;
        fight->stat_temp_player->speed -= compt->speed;
        set_speed_player(fight, scene);
        set_speed_ennemy(fight, scene);
        init_ath_player(fight, scene);
        init_ath_ennemy(fight, scene);
        set_compt_active(fight, scene, compt, nbr);
    }
}