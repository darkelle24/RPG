/*
** EPITECH PROJECT, 2019
** combat_tools
** File description:
** functions tools for manage combat
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

void set_sound(scene_t *scene, rpg_t *rpg)
{
    multi_sound *save = scene->list_sound;

    while (save != NULL && save->sound != NULL) {
        sfSound_setVolume(save->sound, rpg->option->sound_volume);
        save = save->next;
    }
}

void set_text_mid(sfText *text, sfFloatRect rect)
{
    sfFloatRect rect_text = sfText_getGlobalBounds(text);
    sfVector2f pos = sfText_getPosition(text);

    sfText_setPosition(text, create_vect(rect.left + (rect.width / 2
    - rect_text.width / 2), pos.y));
}

void refresh_other_info(fight_t *fight, scene_t *scene)
{
    text_t *text = text_find(scene->list_text, 40000);

    free(text->str);
    text->str = inttochar(fight->turn);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 90001);
    free(text->str);
    fight->speed_total = fight->stat_temp_player->speed
    + fight->stat_temp_ennemy->speed;
    set_speed(fight, scene);
    text->str = inttochar(fight->speed_total);
    sfText_setString(text->text, text->str);
    set_text_mid(text->text, sfRectangleShape_getGlobalBounds(
    ((progress_bar_t *) other_find(scene->other, 91000)->other)->rect_ori));
}

static stat_t *init_stat(int speed)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->ad = 0;
    stat->ap = 0;
    stat->armor = 0;
    stat->hp = 0;
    stat->hp_max = 0;
    stat->magic_resi = 0;
    stat->mana = 0;
    stat->mana_max = 0;
    stat->speed = speed;
    return (stat);
}

int combats_analyse_str(rpg_t *rpg, IGNORE map_t *map, char *str)
{
    fight_t *fight = malloc(sizeof(fight_t));
    int i = 0;

    fight->ennemy = malloc(sizeof(combat_enemy_t));
    fight->ennemy->lvl = find_nbr(str, "Lvl=");
    fight->ennemy->ennemy = find_ennemy(rpg->ennemi_list, find_nbr(str, "ID="));
    fight->ennemy->act = init_stat_ennemy(fight->ennemy->ennemy
    , fight->ennemy->lvl);
    fight->player = rpg->player;
    fight->reward = recup_str_spe(str, "Reward=(", ')');
    fight->turn = 0;
    fight->list = rpg->assets->tab_text[2];
    fight->stat_temp_player = init_stat(fight->player->stat->speed);
    fight->stat_temp_ennemy = init_stat(fight->ennemy->act->speed);
    fight->speed_total = fight->stat_temp_ennemy->speed
    + fight->stat_temp_player->speed;
    while (i != 8) {
        fight->compt[i] = 0;
        i++;
    }
    return (combats(rpg, fight));
}