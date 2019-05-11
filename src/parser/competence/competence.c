/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** competence
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include "proto/proto.h"

void add_competence(competence_t **list, competence_t *new)
{
    competence_t *save = *list;

    while (*list && (*list)->next != NULL)
        *list = (*list)->next;
    new->next = NULL;
    if (*list == NULL)
        *list = new;
    else {
        (*list)->next = new;
        *list = save;
    }
}

char *recup_str_spe(char *str, char *to_find, char end_char)
{
    int pos = strfind(str, to_find);

    if (pos != -1)
        return (recup_str(str, pos - 1, end_char));
    else
        return (NULL);
}

void analyse_str_2(competence_t *new, char *str)
{
    new->degatap = recup_str_spe(str, "DegatAP=\"", '\"');
    new->degatad = recup_str_spe(str, "DegatAD=\"", '\"');
    new->heal = recup_str_spe(str, "Heal=\"", '\"');
    new->other_effect = recup_str_spe(str, "Other_effect=\"", '\"');
}

competence_t *analyse_competence(char *str)
{
    int pos = strfind(str, "Name=\"");
    competence_t *new = malloc(sizeof(competence_t));
    int consumption = find_nbr(str, "Consumtpion=");
    int speed = find_nbr(str, "Speed=");

    if (pos != -1)
        new->name = recup_str(str, pos - 1, '\"');
    else {
        free(new);
        return (NULL);
    }
    new->speed = speed;
    new->id = find_nbr(str, "ID=");
    new->id_sound = find_nbr(str, "ID_sound=");
    new->consumption = consumption;
    new->id_text = find_nbr(str, "ID_text=");
    new->cooldown = find_nbr(str, "Cooldown=");
    analyse_str_2(new, str);
    return (new);
}