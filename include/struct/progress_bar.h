/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** progress_bar
*/

#ifndef PROGRESS_BAR_H_
    #define PROGRESS_BAR_H_

    #include <SFML/Graphics.h>

    typedef struct progress_bar_s
    {
        sfRectangleShape *rect;
        float pourc;
        sfRectangleShape **mini_bar;
        sfRectangleShape *rect_ori;
    }     progress_bar_t;


#endif /* !PROGRESS_BAR_H_ */
