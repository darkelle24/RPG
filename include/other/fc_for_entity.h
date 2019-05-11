/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** fc_for_entity
*/

#ifndef FC_FOR_ENTITY_H_
    #define FC_FOR_ENTITY_H_

    #include "proto/proto.h"

    const char *fc_entity_name[] = {
        "change_map",
        "duel",
        "chat",
        "door_of_boss",
        "final_boss_to_win",
        NULL
    };

    void (* const fonction_entity[])(rpg_t *, map_t *map, char *) = {
        &change_map,
        &combats_analyse_str_call,
        &dialogue_init,
        &door_of_boss,
        &boss,
        NULL
    };

#endif /* !FC_FOR_ENTITY_H_ */