/*
** EPITECH PROJECT, 2019
** button_fc_combat_4
** File description:
** functions for manage buttons effects on combat
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