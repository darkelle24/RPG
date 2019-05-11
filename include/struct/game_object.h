/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** game_object
*/

#ifndef GAME_OBJECT_H_
    #define GAME_OBJECT_H_

    #include <SFML/Graphics.h>

    typedef struct game_object_t
    {
        int id;
        int display;
        sfTexture *texture;
        sfSprite *sprite;
        sfTime last_anim;
    }       game_object;

    typedef struct game_list_t
    {
        game_object *object;
        struct game_list_t *next;
    }       game_list;

#endif /* !GAME_OBJECT_H_ */