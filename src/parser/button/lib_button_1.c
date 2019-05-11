/*
** EPITECH PROJECT, 2019
** qd
** File description:
** qd
*/

#include <unistd.h>
#include <stdio.h>
#include "proto/lib.h"
#include "other/macro.h"
#include "struct/button.h"

void fc_button_null(button_t *button, IGNORE void *unused)
{
    write(1, "Button ID: ", 11);
    my_put_nbr(button->id);
    write(1, " is not linked\n", 15);
}

void button_init(button_t *button, sfVector2f position
, sfVector2f size, int id)
{
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, position);
    sfRectangleShape_setSize(button->rect, size);
    button->callback_click_release = &fc_button_null;
    button->callback_click_press = NULL;
    button->callback_hover = NULL;
    button->callback_hover_exit = NULL;
    button->to_send_click = NULL;
    button->pass = 1;
    button->id = id;
    button->on_button = NULL;
    button->to_send_click2 = NULL;
    button->to_send_click3 = NULL;
    button->texture = NULL;
    button->keyboard = sfFalse;
}

button_t *button_find(button_list_t *list, int id)
{
    while (list != NULL && list->button != NULL && list->button->id != id) {
        list = list->next;
    }
    if (list == NULL)
        return (NULL);
    return (list->button);
}

void button_set_callback_on_click(button_t *button
, void (*to_callback)(button_t *, void *), void *a_envoyer)
{
    button->callback_click_release = to_callback;
    button->to_send_click = a_envoyer;
}

int button_is_clicked(button_t *button, sfVector2f click_position)
{
    sfFloatRect button_vect = sfRectangleShape_getGlobalBounds(button->rect);

    if (sfFloatRect_contains(&button_vect, click_position.x
    , click_position.y) == sfTrue) {
        if (button->callback_click_release != NULL)
            button->callback_click_release(button, button->to_send_click);
        if (button->callback_hover != NULL)
            button->callback_hover(button, button->to_send_click);
        return (1);
    }
    return (0);
}