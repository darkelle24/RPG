/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** lib_button_4
*/

#include <SFML/Graphics.h>
#include "struct/scene.h"
#include "proto/proto.h"

button_t *test_check_right(button_list_t *list, button_t *button
, sfVector2f position_actual)
{
    float test_f = 0;
    float most_value = 689000000;
    sfVector2f test;
    button_t *higther = NULL;

    while (list != NULL && list->button != NULL) {
        if (list->button->keyboard == sfTrue
        && ((button && list->button != button) || (button == NULL))
        && (test = sfRectangleShape_getPosition(list->button->rect)).x
        > position_actual.x && (test_f = calcul_lenght(position_actual
        , create_vect(test.x, test.y)))
        < most_value) {
            most_value = test_f;
            higther = list->button;
        }
        list = list->next;
    }
    return (higther);
}

button_t *check_right(button_list_t *list, button_t *button
, sfRenderWindow *window)
{
    sfVector2f position_actual;
    button_t *higther = NULL;

    if (button == NULL) {
        position_actual = sfRenderWindow_mapPixelToCoords(window
        , sfMouse_getPositionRenderWindow(window)
        , sfRenderWindow_getDefaultView(window));
    } else
        position_actual = sfRectangleShape_getPosition(button->rect);
    higther = test_check_right(list, button, position_actual);
    if (higther == NULL)
        return (button);
    else {
        if (button != NULL && button->callback_hover_exit != NULL)
            button->callback_hover_exit(button, button->to_send_click);
        if (higther->callback_hover != NULL)
            higther->callback_hover(higther, higther->to_send_click);
        return (higther);
    }
}

button_t *test_check_left(button_list_t *list, button_t *button
, sfVector2f position_actual)
{
    float test_f = 0;
    float most_value = 68900000;
    sfVector2f test;
    button_t *higther = NULL;

    while (list != NULL && list->button != NULL) {
        if (list->button->keyboard == sfTrue
        && ((button && list->button != button) || (button == NULL))
        && (test = sfRectangleShape_getPosition(list->button->rect)).x
        < position_actual.x && (test_f = calcul_lenght(position_actual
        , create_vect(test.x, test.y)))
        < most_value) {
            most_value = test_f;
            higther = list->button;
        }
        list = list->next;
    }
    return (higther);
}

button_t *check_left(button_list_t *list, button_t *button
, sfRenderWindow *window)
{
    sfVector2f position_actual;
    button_t *higther = NULL;

    if (button == NULL) {
        position_actual = sfRenderWindow_mapPixelToCoords(window
        , sfMouse_getPositionRenderWindow(window)
        , sfRenderWindow_getDefaultView(window));
    } else
        position_actual = sfRectangleShape_getPosition(button->rect);
    higther = test_check_left(list, button, position_actual);
    if (higther == NULL)
        return (button);
    else {
        if (button != NULL && button->callback_hover_exit != NULL)
            button->callback_hover_exit(button, button->to_send_click);
        if (higther->callback_hover != NULL)
            higther->callback_hover(higther, higther->to_send_click);
        return (higther);
    }
}

void button_move_with_button(sfEvent event, scene_t *scene
, sfRenderWindow *window)
{
    if (event.key.code == sfKeyUp) {
        scene->keyboard = check_up(scene->list_but
        , scene->keyboard, window);
    } else if (event.key.code == sfKeyDown) {
        scene->keyboard = check_down(scene->list_but
        , scene->keyboard, window);
    } else {
        if (event.key.code == sfKeyRight) {
            scene->keyboard = check_right(scene->list_but
            , scene->keyboard, window);
        } else if (event.key.code == sfKeyLeft) {
            scene->keyboard = check_left(scene->list_but
            , scene->keyboard, window);
        }
    }
}