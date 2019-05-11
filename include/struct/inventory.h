/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#ifndef INVENTORY_H_
    #define INVENTORY_H_

#include "proto/proto.h"
#include "struct/stat.h"

    typedef struct item_s
    {
        char *name;
        char *type;
        sfBool equiped;
        int id_texture;
        int nbr;
        stat_t *stat;
    }       item_t;

    typedef struct inventory_s
    {
        item_t *item;
        struct inventory_s *next;
    }       inventory_t;

#endif /* !INVENTORY_H_ */