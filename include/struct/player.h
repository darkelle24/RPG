/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

#include <SFML/Graphics.h>
#include "struct/stat.h"
#include "struct/inventory.h"
#include "struct/competence.h"
#include "proto/proto.h"

    typedef struct player_s
    {
        char *name;
        game_object obj;
        int lvl;
        int xp;
        int point;
        stat_t *stat;
        inventory_t *inventory;
        competence_t *base;
        competence_t *comp_1;
        competence_t *comp_2;
        competence_t *comp_3;
    }       player_t;

#endif /* !PLAYER_H_ */