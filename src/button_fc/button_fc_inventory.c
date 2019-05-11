/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_inventory
*/

#include "proto/proto.h"
#include "other/macro.h"

void button_cl_return(button_t *button, void *back_void)
{
    int *back = (int *) back_void;
    *back = 1;
    button->pass = 1;
}

void button_cl_quit(button_t *button, void *rpg_void)
{
    sfRenderWindow_close(((rpg_t *) rpg_void)->window);
    button->pass = 1;
}

void button_hv_return(button_t *button, IGNORE void *back_void)
{
    sfRectangleShape_setFillColor(button->rect, create_color(0, 0, 255, 255));
    button->pass = 5;
}

void button_hv_quit(button_t *button, IGNORE void *rpg_void)
{
    sfRectangleShape_setFillColor(button->rect, create_color(255, 0, 0, 255));
    button->pass = 5;
}

void button_hvex_return(button_t *button, IGNORE void *back_void)
{
    sfRectangleShape_setFillColor(button->rect, create_color(0, 0, 200, 255));
    button->pass = 1;
}