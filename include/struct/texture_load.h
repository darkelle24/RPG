/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** texture_load
*/

#ifndef TEXTURE_LOAD_H_
    #define TEXTURE_LOAD_H_

    #include <SFML/Graphics.h>

    typedef struct texture_list_s
    {
        int id;
        sfTexture *texture;
        struct texture_list_s *next;
    }     texture_list_t;


#endif /* !TEXTURE_LOAD_H_ */
