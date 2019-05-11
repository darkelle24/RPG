/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** load_player
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

static int get_nbr_fp(FILE *fp)
{
    char *buff = NULL;
    size_t size = 0;
    int nbr = 0;

    getline(&buff, &size, fp);
    nbr = getnbr(buff);
    free(buff);
    return (nbr);
}

static void get_stat(player_t *player, FILE *fp)
{
    stat_t *stat = malloc(sizeof(stat_t));

    player->lvl = get_nbr_fp(fp);
    player->xp = get_nbr_fp(fp);
    player->point = get_nbr_fp(fp);
    stat->hp = get_nbr_fp(fp);
    stat->mana = get_nbr_fp(fp);
    stat->hp_max = get_nbr_fp(fp);
    stat->mana_max = get_nbr_fp(fp);
    stat->ad = get_nbr_fp(fp);
    stat->ap = get_nbr_fp(fp);
    stat->speed = get_nbr_fp(fp);
    stat->armor = get_nbr_fp(fp);
    stat->magic_resi = get_nbr_fp(fp);
    player->stat = stat;
}

static void get_compt(player_t *player, FILE *fp)
{
    char *buff = NULL;
    size_t size = 0;

    getline(&buff, &size, fp);
    player->base = analyse_competence(buff);
    free(buff);
    buff = NULL;
    getline(&buff, &size, fp);
    player->comp_1 = analyse_competence(buff);
    free(buff);
    buff = NULL;
    getline(&buff, &size, fp);
    player->comp_2 = analyse_competence(buff);
    free(buff);
    buff = NULL;
    getline(&buff, &size, fp);
    player->comp_3 = analyse_competence(buff);
    free(buff);
}

static void get_item(player_t *player, FILE *fp)
{
    char *buff = NULL;
    size_t size = 0;

    player->inventory = NULL;
    while (getline(&buff, &size, fp) != -1) {
        add_item_to_inventory(player, buff);
        free(buff);
        buff = NULL;
    }
    free(buff);
}

void load_player(rpg_t *rpg)
{
    FILE *fp = fopen(".save", "r");
    size_t size = 0;
    char *path = NULL;
    int x = 0;
    int y = 0;

    rpg->player = malloc(sizeof(player_t));
    rpg->player->name = NULL;
    getline(&rpg->player->name, &size, fp);
    rpg->player->name[my_strlen(rpg->player->name)] = '\0';
    get_stat(rpg->player, fp);
    getline(&path, &size, fp);
    x = get_nbr_fp(fp);
    y = get_nbr_fp(fp);
    rpg->mob_kill = get_nbr_fp(fp);
    get_compt(rpg->player, fp);
    get_item(rpg->player, fp);
    fclose(fp);
    path[my_strlen(path)] = '\0';
    map_game(rpg, path, create_vect(x, y));
}