/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** button_list_1
*/

#include <SFML/Graphics/RenderWindow.h>
#include <stdlib.h>
#include <stddef.h>
#include "struct/button.h"

button_list_t *create_button_list(void)
{
    button_list_t *list = malloc(sizeof(button_list_t));

    if (list == NULL)
        return (NULL);
    list->button = NULL;
    list->next = NULL;
    return (list);
}

int button_list_add(button_list_t *list, button_t *button)
{
    while (list->next != NULL)
        list = list->next;
    if (list->button == NULL)
        list->button = button;
    else {
        list->next = malloc(sizeof(button_list_t));
        if (list->next == NULL)
            return (-1);
        list->next->button = button;
        list->next->next = NULL;
    }
    return (0);
}

void button_list_draw(sfRenderWindow *window, button_list_t *list)
{
    while (list != NULL) {
        if (list->button->pass != 3 && list->button->pass != 4)
            sfRenderWindow_drawRectangleShape(window, list->button->rect, NULL);
        list = list->next;
    }
}

int button_list_remove_with_button(button_list_t *list, button_t *button)
{
    button_list_t *save;

    while (list != NULL && list->next->button != button)
        list = list->next;
    if (list != NULL) {
        save = list->next;
        list->next = list->next->next;
        free(save);
        return (1);
    } else
        return (-1);
}

int button_list_remove_with_number(button_list_t *list, int number)
{
    button_list_t *save;
    int i = 0;

    while (list != NULL && i != number - 1) {
        i++;
        list = list->next;
    }
    if (list != NULL) {
        save = list->next;
        list->next = list->next->next;
        free(save);
        return (1);
    } else
        return (-1);
}