/*
** EPITECH PROJECT, 2019
** button_fc
** File description:
** button_fc_for_menu
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void button_cl_menu_new_game(IGNORE button_t *but, void *rpg_void)
{
    rpg_t *rpg = (rpg_t *) rpg_void;

    cinematic(rpg);
    if (sfRenderWindow_isOpen(rpg->window))
        create_perso(rpg);
    if (sfRenderWindow_isOpen(rpg->window))
        map_game(rpg, my_strdup("assets/map/openspace")
        , create_vect(200, 200));
    if (rpg->player != NULL)
        free_player(rpg);
}

void button_cl_menu_option(IGNORE button_t *but, void *rpg_void)
{
    option((rpg_t *)rpg_void);
}

void button_cl_menu_continue(IGNORE button_t *but, void *rpg_void)
{
    rpg_t *rpg = (rpg_t *) rpg_void;

    load_player(rpg);
    if (rpg->player != NULL)
        free_player(rpg);
}

void button_pr_menu_option(button_t *but, IGNORE void *rpg_void)
{
    sfRectangleShape_setOutlineColor(but->rect, create_color(0, 0, 50, 255));
    but->pass = 6;
}

void button_hv_menu_option(button_t *but, IGNORE void *rpg_void)
{
    sfRectangleShape_setOutlineColor(but->rect, create_color(0, 0, 140, 255));
    but->pass = 5;
}