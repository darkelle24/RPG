/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ennemy_parser_2
*/

#include <unistd.h>
#include <stdlib.h>
#include "proto/proto.h"
#include "proto/lib.h"

float find_fnbr(char *str, char *to_find)
{
    int pos = strfind(str, to_find);
    float nbr = 0;
    char *temp;

    if (pos != -1) {
        temp = recup_str(str, pos - 1, ' ');
        nbr = get_floatnbr(temp);
        free (temp);
    }
    return (nbr);
}

fstat_t *get_fstat(char **ennemy)
{
    fstat_t *stat = malloc(sizeof(fstat_t));

    stat->hp = find_fnbr(ennemy[0], "HP=");
    stat->mana = find_fnbr(ennemy[1], "MANA=");
    stat->hp_max = find_fnbr(ennemy[2], "HP_MAX=");
    stat->mana_max = find_fnbr(ennemy[3], "MANA_MAX=");
    stat->ad = find_fnbr(ennemy[4], "AD=");
    stat->ap = find_fnbr(ennemy[5], "AP=");
    stat->speed = find_fnbr(ennemy[6], "SPEED=");
    stat->armor = find_fnbr(ennemy[7], "ARMOR=");
    stat->magic_resi = find_fnbr(ennemy[8], "MAGI_RESI=");
    return (stat);
}