/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** text_list
*/

#include <SFML/System/Vector2.h>
#include <stdio.h>
#include <stdlib.h>
#include "struct/text.h"

text_t *text_find(text_list_t *list, int id)
{
    while (list != NULL && list->text->id != id) {
        list = list->next;
    }
    if (list == NULL)
        return (NULL);
    return (list->text);
}

void text_init(text_t *text, sfVector2f position, int disp, int id)
{
    text->text = sfText_create();
    text->id = id;
    text->disp = disp;
    sfText_setPosition(text->text, position);
}

text_list_t *create_text_list(void)
{
    text_list_t *list = malloc(sizeof(text_list_t));

    if (list == NULL)
        return (NULL);
    list->text = NULL;
    list->next = NULL;
    return (list);
}

int text_list_add(text_list_t *list, text_t *text)
{
    while (list->next != NULL)
        list = list->next;
    if (list->text == NULL)
        list->text = text;
    else {
        list->next = malloc(sizeof(text_list_t));
        if (list->next == NULL)
            return (-1);
        list->next->text = text;
        list->next->next = NULL;
    }
    return (0);
}

void display_list_text(sfRenderWindow *window, text_list_t *list)
{
    if (list->text != NULL) {
        while (list != NULL) {
            if (list->text->disp != 0)
                sfRenderWindow_drawText(window, list->text->text, NULL);
            list = list->next;
        }
    }
}