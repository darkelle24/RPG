/*
** EPITECH PROJECT, 2019
** play_rpg
** File description:
** play rpg
*/

#include <time.h>
#include "struct/game_struct.h"
#include "proto/proto.h"

int play_rpg(char *str)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    if (rpg == NULL)
        return (1);
    srand(time(NULL));
    set_up_game(rpg, str);
    analyse_folder_ennemy("ennemy/", rpg);
    play_game(rpg);
    end_game(rpg);
    return (0);
}