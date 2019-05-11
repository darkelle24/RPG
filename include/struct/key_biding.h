/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** key_biding
*/

#ifndef KEY_BIDING_H_
    #define KEY_BIDING_H_

    #include <SFML/Graphics.h>

    typedef struct key_biding_s
    {
        int key_move_up;
        int key_move_down;
        int key_move_left;
        int key_move_right;
        int key_inventory;
        int key_stat;
        int key_quest;
        int key_pause;
    }       key_biding_t;

#endif /* !KEY_BIDING_H_ */