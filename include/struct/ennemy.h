/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ennemy
*/

#ifndef ENNEMY_H_
    #define ENNEMY_H_

#include "struct/competence.h"
#include "struct/stat.h"

    typedef struct ennemy_s
    {
        char *name;
        int id;
        int id_text;
        competence_t *compt_1;
        competence_t *compt_2;
        competence_t *compt_3;
        competence_t *compt_4;
        stat_t *stat_lvl_1;
        fstat_t *stat_per_lvl;
        struct ennemy_s *next;
    }       ennemy_t;

#endif /* !ENNEMY_H_ */