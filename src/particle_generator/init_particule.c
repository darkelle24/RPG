/*
** EPITECH PROJECT, 2019
** init_particule
** File description:
** functions for initialise particules
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "struct/particule.h"
#include "proto/proto.h"

particule_rect_t **init_particle_rect(void)
{
    int i = 1;
    particule_rect_t **new = malloc(sizeof(particule_rect_t *) * 201);

    new[200] = NULL;
    while (i != 201) {
        new[i - 1] = malloc(sizeof(particule_rect_t));
        new[i - 1]->rect = create_rectangle(create_vect(840, 560)
        , create_vect(20, 20), sfRed);
        new[i - 1]->power = create_vect(-10, (rand() % 6) - 3);
        new[i - 1]->start = sfFalse;
        i++;
    }
    return (new);
}

particule_rect_t **init_particle_rect_2(void)
{
    int i = 1;
    particule_rect_t **new = malloc(sizeof(particule_rect_t *) * 301);

    new[300] = NULL;
    while (i != 301) {
        new[i - 1] = malloc(sizeof(particule_rect_t));
        new[i - 1]->rect = create_rectangle(create_vect(840, 560)
        , create_vect(6, 6), sfBlue);
        new[i - 1]->power = create_vect((rand() % 20) - 10, 20);
        new[i - 1]->start = sfFalse;
        i++;
    }
    return (new);
}

particule_t *init_particule(rpg_t *rpg)
{
    particule_t *new = malloc(sizeof(particule_t));

    new->graviter = 0.60;
    new->rect_list = init_particle_rect();
    new->rect_list_2 = init_particle_rect_2();
    new->start = sfFalse;
    new->timer = sfClock_getElapsedTime(rpg->game);
    return (new);
}