/*
** EPITECH PROJECT, 2019
** qd
** File description:
** qd
*/

#ifndef INCLUDE_H_
    #define INCLUDE_H_
    #include "struct/button.h"
    #include "struct/music_sound.h"
    #include "struct/text.h"
    #include "struct/texture_load.h"

    typedef struct other_s
    {
        void *other;
        int id;
        int disp;
        char type;
        struct other_s *next;
    }     other_t;

    typedef struct display_order_t
    {
        game_object *object;
        button_t *button;
        text_t *text;
        other_t *other;
        int priority;
        struct display_order_t *next;
    }       display_order;

    typedef struct scene_s
    {
        game_list *list_ob;
        texture_list_t *texture_list;
        button_list_t *list_but;
        multi_music *list_music;
        multi_sound *list_sound;
        text_list_t *list_text;
        other_t *other;
        sfFont *font;
        button_t *keyboard;
        display_order *order;
        sfVector2f vector;
    }       scene_t;



#endif /* !INCLUDE_H_ */
