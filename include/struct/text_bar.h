/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** text_bar
*/

#ifndef TEXT_BAR_H_
    #define TEXT_BAR_H_

#include <SFML/Graphics.h>
#include "struct/geo_form.h"

    typedef struct text_bar_s
    {
        char *str;
        int lenght_max;
        int pos_in_str;
        int ecart;
        sfBool focus;
        sfText *text;
        sfFloatRect rect;
        sfRectangleShape *barre;
        rectangle_t *rect_text;
    }       text_bar_t;

#endif /* !TEXT_BAR_H_ */