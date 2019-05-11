/*
** EPITECH PROJECT, 2019
** corsair_perso
** File description:
** functions for initialise and save corsair
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"

void corsair_save(scene_t *scene, rpg_t *rpg)
{
    text_bar_t *text_bar = (text_bar_t *) (other_find(scene->other
    , 350)->other);

    rpg->player->stat = malloc(sizeof(stat_t));
    rpg->player->stat->hp = 110;
    rpg->player->stat->hp_max = 110;
    rpg->player->stat->mana = 115;
    rpg->player->stat->mana_max = 115;
    rpg->player->stat->ap = 10;
    rpg->player->stat->ad = 22;
    rpg->player->stat->armor = 9;
    rpg->player->stat->magic_resi = 13;
    rpg->player->stat->speed = 7;
    free(rpg->player->name);
    if (text_bar->str[0] != '\0')
        rpg->player->name = my_strdup(text_bar->str);
    else
        rpg->player->name = my_strdup("Player");
    recup_compt(rpg, "assets/competencie/corsair");
}

void corsair_init(scene_t *scene)
{
    sfText_setString(text_find(scene->list_text, 10001)->text, "Corsair");
    set_text(scene, 6001, inttochar(110));
    set_text(scene, 6002, inttochar(115));
    set_text(scene, 6003, inttochar(10));
    set_text(scene, 6004, inttochar(22));
    set_text(scene, 6005, inttochar(9));
    set_text(scene, 6006, inttochar(13));
    set_text(scene, 6007, inttochar(7));
    sfText_setString(text_find(scene->list_text, 11300)->text,
    "Mainly gun competencies. Can deal great damages");
    text_find(scene->list_text, 11300)->disp = 1;
    sfText_setString(text_find(scene->list_text, 11301)->text,
    "but have to wait longer than the other. "
    "His Neon Skill is the \"Neon Dash\".");
    text_find(scene->list_text, 11301)->disp = 1;
    text_find(scene->list_text, 11302)->disp = 0;
}