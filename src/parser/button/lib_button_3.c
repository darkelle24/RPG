/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** lib_button_3
*/

#include <unistd.h>
#include <stdio.h>
#include "struct/scene.h"
#include "struct/button.h"

void button_is_hover_test_exit(button_t *button, sfVector2f mouse_pos)
{
    sfFloatRect button_vect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_vect, mouse_pos.x
    , mouse_pos.y) == sfFalse) {
        if (button->callback_hover_exit != NULL)
            button->callback_hover_exit(button, button->to_send_click);
    }
}

void button_is_hover_test(scene_t *scene
, button_t *button, sfVector2f mouse_pos)
{
    sfFloatRect button_vect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_vect, mouse_pos.x
    , mouse_pos.y) == sfTrue) {
        button->callback_hover(button, button->to_send_click);
        if (scene->keyboard != NULL) {
            scene->keyboard->callback_hover_exit
            (scene->keyboard
            , scene->keyboard->to_send_click);
            scene->keyboard = NULL;
        }
    }
}

void button_list_is_hover_2(sfVector2f mouse_position, scene_t *scene
, button_list_t *button_list)
{
    while (button_list != NULL && button_list->button) {
        if (button_list->button->pass != 4 && button_list->button->pass != 2
        && button_list->button->callback_hover != NULL) {
            if ((button_list->button->pass != 6
            && button_list->button->pass != 5
            && scene->keyboard == NULL) || scene->keyboard != NULL){
                button_is_hover_test(scene, button_list->button
                , mouse_position);
            }
        }
        button_list = button_list->next;
    }
}

void button_list_is_hover(scene_t *scene, button_list_t *button_list
, sfRenderWindow *window)
{
    sfVector2f mouse_position = sfRenderWindow_mapPixelToCoords(window
    , sfMouse_getPositionRenderWindow(window)
    , sfRenderWindow_getDefaultView(window));
    button_list_t *save = button_list;

    while (button_list != NULL && button_list->button) {
        if (button_list->button->pass != 4 && button_list->button->pass != 2
        && button_list->button->callback_hover != NULL) {
            if ((button_list->button->pass == 5
            || button_list->button->pass == 6) && scene->keyboard == NULL)
                button_is_hover_test_exit(button_list->button, mouse_position);
        }
        button_list = button_list->next;
    }
    button_list_is_hover_2(mouse_position, scene, save);
}