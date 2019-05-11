/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** change_map
*/

#include <stdlib.h>
#include "proto/proto.h"
#include "proto/parser.h"
#include "other/macro.h"

void change_map(rpg_t *rpg, map_t *map, char *str)
{
    sfVector2f pos = pos_object_recup_str(str, "Pos=");
    char *path = recup_str_spe(str, "Path=\'", '\'');

    map_set_to_game_object(path, rpg->assets->tab_text[1], map, pos);
    free(path);
}