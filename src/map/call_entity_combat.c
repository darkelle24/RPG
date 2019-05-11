/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** call_entity_combat
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"
#include "struct/combats.h"
#include "other/macro.h"

void combats_analyse_str_call(rpg_t *rpg, map_t *map, char *str)
{
    int back = combats_analyse_str(rpg, map, str);
    entity_t *save = map->entity;

    if (back == 2 || back == 3) {
        while (save != NULL && save->str != str)
            save = save->next;
        if (save != NULL)
            save->active = 0;
        if (back == 3)
            rpg->mob_kill++;
    } else if (back == 1) {
        rpg->player->stat->hp = rpg->player->stat->hp_max;
        rpg->player->stat->mana = rpg->player->stat->mana_max;
        map_set_to_game_object(my_strdup("assets/map/openspace")
        , rpg->assets->tab_text[1], map, create_vect(200,200));
    }
    rpg->player->stat->mana = rpg->player->stat->mana_max;
}