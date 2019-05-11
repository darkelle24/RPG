/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** text_bar_2
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "proto/proto.h"

void text_bar_free(void *text_void)
{
    text_bar_t *text = text_void;

    free(text->str);
    if (text->rect_text != NULL)
        rectangle_free((void *) text->rect_text);
    sfRectangleShape_destroy(text->barre);
    sfText_destroy(text->text);
}