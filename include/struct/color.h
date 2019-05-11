/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** color
*/

#ifndef COLOR_H_
    #define COLOR_H_

    #include <SFML/Graphics.h>

    typedef struct color_t
    {
        sfColor degrade;
        int sensr;
        int sensb;
        int sensg;
        int sensa;
    }     colordegrade;

    typedef struct colordegradsens_s
    {
        int sensr;
        int sensb;
        int sensg;
        int sensa;
    }       colordegradsens_t;

#endif /* !COLOR_H_ */
