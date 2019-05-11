/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** lib_button_2
*/

#include <stddef.h>
#include <stdlib.h>
#include "struct/button.h"
#include "proto/proto.h"

void button_list_is_clicked(button_list_t *button_list
, sfRenderWindow *window)
{
    sfVector2f click_position = sfRenderWindow_mapPixelToCoords(window
    , sfMouse_getPositionRenderWindow(window)
    , sfRenderWindow_getDefaultView(window));

    while (button_list != NULL && button_list->button != NULL) {
        if (button_list->button->pass != 4 && button_list->button->pass != 2) {
            button_is_clicked(button_list->button
            , click_position);
        }
        button_list = button_list->next;
    }
}

int button_list_remove(button_list_t *list, button_t *button, int nbr)
{
    if (button != NULL) {
        return (button_list_remove_with_button(list, button));
    } else {
        return (button_list_remove_with_number(list, nbr));
    }
}

void button_free(button_t *button)
{
    sfRectangleShape_destroy(button->rect);
    if (button->texture != NULL)
        sfTexture_destroy(button->texture);
    free(button);
}

void button_list_free(button_list_t *list)
{
    button_list_t *save;

    while (list != NULL && list->button != NULL) {
        button_free(list->button);
        save = list;
        list = list->next;
        free(save);
    }
}

void button_set_outline(button_t *button, float thickness, sfColor color)
{
    sfRectangleShape_setOutlineColor(button->rect, color);
    sfRectangleShape_setOutlineThickness(button->rect, thickness);
}