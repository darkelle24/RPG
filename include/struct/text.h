/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** text
*/

#ifndef TEXT_H_
    #define TEXT_H_

    #include <SFML/Graphics.h>

    typedef struct text_s text_t;

    struct text_s
    {
        sfText *text;
        int id;
        char *str;
        int disp;
    };

    typedef struct text_list_s
    {
        text_t *text;
        struct text_list_s *next;
    }       text_list_t;


#endif /* !TEXT_H_ */
