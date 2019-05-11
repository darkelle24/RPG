/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** combats
*/

#ifndef COMBATS_H_
    #define COMBATS_H_

    #include "struct/player.h"

    typedef struct combat_enemy_s
    {
        ennemy_t *ennemy;
        int lvl;
        stat_t *act;
    }       combat_enemy_t;

    typedef struct fight_s
    {
        player_t *player;
        stat_t *stat_temp_player;
        combat_enemy_t *ennemy;
        stat_t *stat_temp_ennemy;
        int compt[8];
        char *reward;
        int turn;
        int speed_total;
        texture_list_t *list;
    }       fight_t;

#endif /* !COMBATS_H_ */
