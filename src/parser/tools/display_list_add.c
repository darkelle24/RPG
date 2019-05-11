/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** display_list_add
*/

#include <stdlib.h>
#include "struct/scene.h"
#include "struct/button.h"

void init_display_list(display_order *list, int prio, void *star, char type)
{
    list->object = NULL;
    list->button = NULL;
    list->text = NULL;
    list->other = NULL;
    if (type == 'T')
        list->text = (text_t *) star;
    if (type == 'B')
        list->button = (button_t *) star;
    if (type == 'G')
        list->object = (game_object *) star;
    if (type == 'O')
        list->other = (other_t *) star;
    list->priority = prio;
}

void display_list_add_object(display_order **list, game_object *object
, int prio)
{
    display_order *save;
    display_order *backup = *list;

    if ((*list)->priority == -1) {
        init_display_list((*list), prio, (void *) object, 'G');
    } else if ((*list)->priority <= prio) {
        save = malloc(sizeof(display_order));
        save->next = *list;
        init_display_list(save, prio, (void *) object, 'G');
        *list = save;
    } else {
        while ((*list)->next != NULL && (*list)->next->priority >= prio)
            *list = (*list)->next;
        save = (*list)->next;
        (*list)->next = malloc(sizeof(display_order));
        (*list)->next->next = save;
        init_display_list((*list)->next, prio, (void *) object, 'G');
        *list = backup;
    }
}

void display_list_add_button(display_order **list, button_t *button, int prio)
{
    display_order *save;
    display_order *backup = *list;

    if ((*list)->priority == -1) {
        init_display_list((*list), prio, (void *) button, 'B');
    } else if ((*list)->priority <= prio) {
        save = malloc(sizeof(display_order));
        save->next = *list;
        init_display_list(save, prio, (void *) button, 'B');
        *list = save;
    } else {
        while ((*list)->next != NULL && (*list)->next->priority >= prio)
            *list = (*list)->next;
        save = (*list)->next;
        (*list)->next = malloc(sizeof(display_order));
        (*list)->next->next = save;
        init_display_list((*list)->next, prio, (void *) button, 'B');
        *list = backup;
    }
}

void display_list_add_text(display_order **list, text_t *text, int prio)
{
    display_order *save;
    display_order *backup = *list;

    if ((*list)->priority == -1) {
        init_display_list((*list), prio, (void *) text, 'T');
    } else if ((*list)->priority <= prio) {
        save = malloc(sizeof(display_order));
        save->next = *list;
        init_display_list(save, prio, (void *) text, 'T');
        *list = save;
    } else {
        while ((*list)->next != NULL && (*list)->next->priority >= prio)
            *list = (*list)->next;
        save = (*list)->next;
        (*list)->next = malloc(sizeof(display_order));
        (*list)->next->next = save;
        init_display_list((*list)->next, prio, (void *) text, 'T');
        *list = backup;
    }
}

void display_list_add_other(display_order **list, other_t *other, int prio)
{
    display_order *save;
    display_order *backup = *list;

    if ((*list)->priority == -1) {
        init_display_list((*list), prio, (void *) other, 'O');
    } else if ((*list)->priority <= prio) {
        save = malloc(sizeof(display_order));
        save->next = *list;
        init_display_list(save, prio, (void *) other, 'O');
        *list = save;
    } else {
        while ((*list)->next != NULL && (*list)->next->priority >= prio)
            *list = (*list)->next;
        save = (*list)->next;
        (*list)->next = malloc(sizeof(display_order));
        (*list)->next->next = save;
        init_display_list((*list)->next, prio, (void *) other, 'O');
        *list = backup;
    }
}