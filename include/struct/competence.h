/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** competence
*/

#ifndef COMPETENCE_H_
    #define COMPETENCE_H_

    typedef struct competence_s
    {
        char *name;
        int id;
        int id_text;
        char *degatap;
        char *degatad;
        char *heal;
        char *other_effect;
        int id_sound;
        int speed;
        int consumption;
        int cooldown;
        struct competence_s *next;
    }       competence_t;

#endif /* !COMPETENCE_H_ */