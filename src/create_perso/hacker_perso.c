/*
** EPITECH PROJECT, 2019
** hacker_perso
** File description:
** functions for initialise and save hacker
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"

void hacker_save(scene_t *scene, rpg_t *rpg)
{
    text_bar_t *text_bar = (text_bar_t *) (other_find(scene->other
    , 350)->other);

    rpg->player->stat = malloc(sizeof(stat_t));
    rpg->player->stat->hp = 100;
    rpg->player->stat->hp_max = 100;
    rpg->player->stat->mana = 130;
    rpg->player->stat->mana_max = 130;
    rpg->player->stat->ap = 20;
    rpg->player->stat->ad = 12;
    rpg->player->stat->armor = 10;
    rpg->player->stat->magic_resi = 20;
    rpg->player->stat->speed = 4;
    free(rpg->player->name);
    if (text_bar->str[0] != '\0')
        rpg->player->name = my_strdup(text_bar->str);
    else
        rpg->player->name = my_strdup("Player");
    recup_compt(rpg, "assets/competencie/hacker");
}

void hacker_init(scene_t *scene)
{
    sfText_setString(text_find(scene->list_text, 10001)->text, "Hacker");
    set_text(scene, 6001, inttochar(100));
    set_text(scene, 6002, inttochar(130));
    set_text(scene, 6003, inttochar(20));
    set_text(scene, 6004, inttochar(12));
    set_text(scene, 6005, inttochar(10));
    set_text(scene, 6006, inttochar(20));
    set_text(scene, 6007, inttochar(4));
    sfText_setString(text_find(scene->list_text, 11300)->text
    , "Mainly effects competencies. Heal or Buff.");
    text_find(scene->list_text, 11300)->disp = 1;
    sfText_setString(text_find(scene->list_text, 11301)->text
    , "Can fight with his fists to kill. His Neon Skill is \"Neon Instinct\".");
    text_find(scene->list_text, 11301)->disp = 1;
    text_find(scene->list_text, 11302)->disp = 0;
}