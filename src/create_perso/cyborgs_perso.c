/*
** EPITECH PROJECT, 2019
** cyborgs_perso
** File description:
** functions for initialise and save cyborgs
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"

void cyborgs_save(scene_t *scene, rpg_t *rpg)
{
    text_bar_t *text_bar = (text_bar_t *) (other_find(scene->other
    , 350)->other);

    rpg->player->stat = malloc(sizeof(stat_t));
    rpg->player->stat->hp = 120;
    rpg->player->stat->hp_max = 120;
    rpg->player->stat->mana = 90;
    rpg->player->stat->mana_max = 90;
    rpg->player->stat->ap = 12;
    rpg->player->stat->ad = 17;
    rpg->player->stat->armor = 25;
    rpg->player->stat->magic_resi = 10;
    rpg->player->stat->speed = 5;
    free(rpg->player->name);
    if (text_bar->str[0] != '\0')
        rpg->player->name = my_strdup(text_bar->str);
    else
        rpg->player->name = my_strdup("Player");
    recup_compt(rpg, "assets/competencie/cyborg");
}

void cyborgs_init(scene_t *scene)
{
    sfText_setString(text_find(scene->list_text, 10001)->text, "Cyborgs");
    set_text(scene, 6001, inttochar(120));
    set_text(scene, 6002, inttochar(90));
    set_text(scene, 6003, inttochar(12));
    set_text(scene, 6004, inttochar(17));
    set_text(scene, 6005, inttochar(25));
    set_text(scene, 6006, inttochar(10));
    set_text(scene, 6007, inttochar(5));
    sfText_setString(text_find(scene->list_text, 11300)->text,
    "Metal body that give him resistance and strenght");
    text_find(scene->list_text, 11300)->disp = 1;
    sfText_setString(text_find(scene->list_text, 11301)->text,
    "but it makes him louder so he's slower than others. Deal good damages,");
    text_find(scene->list_text, 11301)->disp = 1;
    sfText_setString(text_find(scene->list_text, 11302)->text,
    "but hacking vulnerable. His Neon Skill is \"Neon Blade\".");
    text_find(scene->list_text, 11302)->disp = 1;
}