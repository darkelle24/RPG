/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** lib_button_6
*/

#include <unistd.h>
#include <stdio.h>
#include "struct/scene.h"
#include "struct/button.h"

void button_is_press_test(button_t *button, sfVector2f mouse_pos)
{
    sfFloatRect button_vect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_vect, mouse_pos.x
    , mouse_pos.y) == sfTrue) {
        button->callback_click_press(button, button->to_send_click);
    }
}

void button_list_is_pressed(button_list_t *button_list
, sfRenderWindow *window)
{
    sfVector2f mouse_position = sfRenderWindow_mapPixelToCoords(window
    , sfMouse_getPositionRenderWindow(window)
    , sfRenderWindow_getDefaultView(window));

    while (button_list != NULL && button_list->button) {
        if (button_list->button->pass != 4 && button_list->button->pass != 2
        && button_list->button->callback_click_press != NULL) {
            button_is_press_test(button_list->button
            , mouse_position);
        }
        button_list = button_list->next;
    }
}