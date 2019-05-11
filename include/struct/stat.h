/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** stat
*/

#ifndef STAT_H_
    #define STAT_H_

    typedef struct stat_s
    {
        int hp;
        int mana;
        int hp_max;
        int mana_max;
        int ad;
        int ap;
        int speed;
        int armor;
        int magic_resi;
    }       stat_t;

    typedef struct fstat_s
    {
        float hp;
        float mana;
        float hp_max;
        float mana_max;
        float ad;
        float ap;
        float speed;
        float armor;
        float magic_resi;
    }       fstat_t;

#endif /* !STAT_H_ */
