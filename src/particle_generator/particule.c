/*
** EPITECH PROJECT, 2019
** particule
** File description:
** functions for draw particules, free it, and manage with a clock
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "struct/particule.h"
#include "proto/proto.h"

void draw_part(particule_t *part, rpg_t *rpg)
{
    int i = 0;

    while (part->rect_list[i] != NULL) {
        sfRenderWindow_drawRectangleShape(rpg->window
        , part->rect_list[i]->rect, NULL);
        i++;
    }
    i = 0;
    while (part->rect_list_2[i] != NULL && part->start == sfTrue) {
        if (part->rect_list_2[i]->start == sfTrue)
            sfRenderWindow_drawRectangleShape(rpg->window
            , part->rect_list_2[i]->rect, NULL);
        i++;
    }
}

void clock_systeme_particule(particule_t *part, rpg_t *rpg)
{
    sfTime mtime = sfClock_getElapsedTime(rpg->game);

    mtime.microseconds -= part->timer.microseconds;
    if (mtime.microseconds >= 15000) {
        while (mtime.microseconds >= 15000) {
            system_particule(part);
            if (part->rect_list_2[0]->start == sfTrue)
                system_particule_2(part);
            mtime.microseconds -= 15000;
        }
        part->timer = sfClock_getElapsedTime(rpg->game);
    }
    draw_part(part, rpg);
}

void start_explosion(particule_t *part, sfVector2f pos)
{
    int i = 0;
    float nbr;
    float nbr2;

    part->start = sfTrue;
    while (part->rect_list_2[i] != NULL) {
        nbr = (((float)rand() / (float)(RAND_MAX)) * 20) - 10;
        nbr2 = (((float)rand() / (float)(RAND_MAX)) * 20) - 10;
        sfRectangleShape_setPosition(part->rect_list_2[i]->rect, pos);
        sfRectangleShape_setFillColor(part->rect_list_2[i]->rect, sfBlue);
        part->rect_list_2[i]->power = create_vect(nbr, nbr2);
        part->rect_list_2[i]->start = sfTrue;
        i++;
    }
}

void free_part(particule_t *part)
{
    int i = 0;

    while (part->rect_list[i] != NULL) {
        sfRectangleShape_destroy(part->rect_list[i]->rect);
        free(part->rect_list[i]);
        i++;
    }
    i = 0;
    while (part->rect_list_2[i] != NULL) {
        sfRectangleShape_destroy(part->rect_list_2[i]->rect);
        free(part->rect_list_2[i]);
        i++;
    }
    free(part->rect_list_2);
    free(part->rect_list);
    free(part);
}