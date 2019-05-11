/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** lib_button_5
*/

#include <SFML/Graphics.h>
#include <math.h>
#include "struct/scene.h"
#include "proto/proto.h"

float calcul_lenght(sfVector2f pos_target, sfVector2f pos_circle)
{
    float x = pow(pos_target.x - pos_circle.x, 2);
    float y = pow(pos_target.y - pos_circle.y, 2);

    return (x + y);
}

button_t *test_check_up(button_list_t *list, button_t *button
, sfVector2f position_actual)
{
    float test_f = 0;
    float most_value = 689000000;
    sfVector2f test;
    button_t *higther = NULL;

    while (list != NULL && list->button != NULL) {
        if (list->button->keyboard == sfTrue
        && ((button && list->button != button) || (button == NULL))
        && (test = sfRectangleShape_getPosition(list->button->rect)).y
        < position_actual.y && (test_f = calcul_lenght(position_actual
        , create_vect(test.x, test.y)))
        < most_value) {
            most_value = test_f;
            higther = list->button;
        }
        list = list->next;
    }
    return (higther);
}

button_t *check_up(button_list_t *list, button_t *button
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
    higther = test_check_up(list, button, position_actual);
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

button_t *test_check_down(button_list_t *list, button_t *button
, sfVector2f position_actual)
{
    float test_f = 0;
    float most_value = 68900000;
    sfVector2f test;
    button_t *higther = NULL;

    while (list != NULL && list->button != NULL) {
        if (list->button->keyboard == sfTrue
        && ((button && list->button != button) || (button == NULL))
        && (test = sfRectangleShape_getPosition(list->button->rect)).y
        > position_actual.y && (test_f = calcul_lenght(position_actual
        , create_vect(test.x, test.y)))
        < most_value) {
            most_value = test_f;
            higther = list->button;
        }
        list = list->next;
    }
    return (higther);
}

button_t *check_down(button_list_t *list, button_t *button
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
    higther = test_check_down(list, button, position_actual);
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