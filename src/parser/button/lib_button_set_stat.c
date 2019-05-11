/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** lib_button_set_status
*/

#include "struct/button.h"

void button_desactivate(button_t *button, sfColor color)
{
    button->pass = 2;
    sfRectangleShape_setFillColor(button->rect, color);
}

void button_activate(button_t *button, sfColor color)
{
    button->pass = 1;
    sfRectangleShape_setFillColor(button->rect, color);
}

void button_invisible(button_t *button)
{
    sfColor invi;

    invi.a = 0;
    invi.b = 0;
    invi.r = 0;
    invi.g = 0;
    sfRectangleShape_setFillColor(button->rect, invi);
    button->pass = 3;
}

void button_invi_and_desac(button_t *button)
{
    sfColor invi;

    invi.a = 0;
    invi.b = 0;
    invi.r = 0;
    invi.g = 0;
    sfRectangleShape_setFillColor(button->rect, invi);
    button->pass = 4;
}

void button_set_status(button_t *button, int pass, sfColor color)
{
    if (pass == 1)
        button_activate(button, color);
    else if (pass == 2)
        button_desactivate(button, color);
    else {
        if (pass == 3)
            button_invisible(button);
        else if (pass == 4)
            button_invi_and_desac(button);
    }
}