/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** particule
*/

#ifndef PARTICULE_H_
    #define PARTICULE_H_

    #include <SFML/Graphics.h>
    #include "struct/game_object.h"
    #include "struct/scene.h"

    typedef struct particule_rect_s
    {
        sfRectangleShape *rect;
        sfVector2f power;
        sfBool start;
    }       particule_rect_t;

    typedef struct particule_s
    {
        sfTime timer;
        float graviter;
        sfBool start;
        particule_rect_t **rect_list;
        particule_rect_t **rect_list_2;
    }       particule_t;

#endif /* !PARTICULE_H_ */
