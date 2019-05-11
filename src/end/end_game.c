/*
** EPITECH PROJECT, 2019
** end_game
** File description:
** functions for end the rpg game
*/

#include "struct/game_struct.h"
#include "proto/proto.h"

void free_compt(competence_t *compt)
{
    free(compt->name);
    free(compt->degatad);
    free(compt->degatap);
    free(compt->heal);
    free(compt->other_effect);
    free(compt);
}

void free_player(rpg_t *rpg)
{
    free(rpg->player->name);
    free(rpg->player->stat);
    free_compt(rpg->player->base);
    free_compt(rpg->player->comp_1);
    free_compt(rpg->player->comp_2);
    free_compt(rpg->player->comp_3);
    free(rpg->player);
    rpg->player = NULL;
}

void free_ennemy(rpg_t *rpg)
{
    ennemy_t *save;

    while (rpg->ennemi_list != NULL) {
        free(rpg->ennemi_list->name);
        free(rpg->ennemi_list->stat_lvl_1);
        free(rpg->ennemi_list->stat_per_lvl);
        free_compt(rpg->ennemi_list->compt_1);
        free_compt(rpg->ennemi_list->compt_1);
        free_compt(rpg->ennemi_list->compt_2);
        free_compt(rpg->ennemi_list->compt_3);
        save = rpg->ennemi_list;
        rpg->ennemi_list = rpg->ennemi_list->next;
        free(save);
    }
}

void end_game(rpg_t *rpg)
{
    int i = 0;

    free(rpg->option);
    while (i != 10) {
        if (rpg->assets->tab_text[i] != NULL)
            free_text_list(rpg->assets->tab_text[i]);
        i++;
    }
    free(rpg->assets);
    sfClock_destroy(rpg->game);
    sfRenderWindow_destroy(rpg->window);
    free(rpg);
}