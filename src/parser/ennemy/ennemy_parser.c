/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** ennemy_parser
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include "proto/proto.h"
#include "proto/lib.h"

stat_t *get_stat(char **ennemy)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->hp = find_nbr(ennemy[0], "HP=");
    stat->mana = find_nbr(ennemy[1], "MANA=");
    stat->hp_max = find_nbr(ennemy[2], "HP_MAX=");
    stat->mana_max = find_nbr(ennemy[3], "MANA_MAX=");
    stat->ad = find_nbr(ennemy[4], "AD=");
    stat->ap = find_nbr(ennemy[5], "AP=");
    stat->speed = find_nbr(ennemy[6], "SPEED=");
    stat->armor = find_nbr(ennemy[7], "ARMOR=");
    stat->magic_resi = find_nbr(ennemy[8], "MAGI_RESI=");
    return (stat);
}

void create_ennemy_2(ennemy_t *new, char **ennemy)
{
    int i = 0;

    new->id = find_nbr(ennemy[0], "ID=");
    new->id_text = find_nbr(ennemy[1], "ID_text=");
    new->compt_1 = analyse_competence(ennemy[2]);
    new->compt_2 = analyse_competence(ennemy[3]);
    new->compt_3 = analyse_competence(ennemy[4]);
    new->compt_4 = analyse_competence(ennemy[5]);
    new->stat_lvl_1 = get_stat(&ennemy[7]);
    new->stat_per_lvl = get_fstat(&ennemy[17]);
    while (ennemy[i] != NULL) {
        free(ennemy[i]);
        i++;
    }
    free(ennemy);
}

void add_ennemy(ennemy_t **list, ennemy_t *new)
{
    ennemy_t *save = *list;

    while (*list != NULL && (*list)->next != NULL)
        *list = (*list)->next;
    new->next = NULL;
    if (*list == NULL)
        *list = new;
    else {
        (*list)->next = new;
        *list = save;
    }
}

void create_ennemy(rpg_t *rpg, char *path, char *name)
{
    FILE *fp = fopen(path, "r");
    char *buff = NULL;
    size_t size = 0;
    int i = 0;
    ennemy_t *new = malloc(sizeof(ennemy_t));
    char **ennemy = malloc(sizeof(char *) * 27);

    new->name = name;
    new->name[my_strlen(new->name) - 3] = '\0';
    ennemy[26] = NULL;
    while (i != 26) {
        getline(&buff, &size, fp);
        ennemy[i] = buff;
        buff = NULL;
        i++;
    }
    create_ennemy_2(new, ennemy);
    add_ennemy(&rpg->ennemi_list, new);
    fclose(fp);
}

void analyse_folder_ennemy(char *path_folder, rpg_t *rpg)
{
    struct dirent *info;
    DIR *dir = opendir(path_folder);

    rpg->ennemi_list = NULL;
    while ((info = readdir(dir)) != NULL) {
        if (info->d_name[0] != '.')
            create_ennemy(rpg, str_append(path_folder, info->d_name, 0, 0)
            , info->d_name);
    }
}