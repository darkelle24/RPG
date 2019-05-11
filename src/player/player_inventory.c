/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** player_inventory
*/

#include <unistd.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"

static stat_t *analyse_effect(char *effect)
{
    stat_t *stat = malloc(sizeof(stat_t));

    stat->hp = find_nbr(effect, "HP_act=");
    stat->hp_max = find_nbr(effect, "HP_max=");
    stat->mana = find_nbr(effect, "Mana_act=");
    stat->mana_max = find_nbr(effect, "Mana_max=");
    stat->ad = find_nbr(effect, "AD=");
    stat->ap = find_nbr(effect, "AP=");
    stat->armor = find_nbr(effect, "Armor=");
    stat->magic_resi = find_nbr(effect, "Magic_Resi=");
    stat->speed = find_nbr(effect, "Speed=");
    return (stat);
}

static void append_item(inventory_t **list, item_t *item)
{
    inventory_t *new = malloc(sizeof(inventory_t));
    inventory_t *save = *list;

    while (*list && (*list)->next != NULL)
        *list = (*list)->next;
    new->next = NULL;
    new->item = item;
    if (*list == NULL)
        *list = new;
    else {
        (*list)->next = new;
        *list = save;
    }
}

static void equipped_item(item_t *item, char *str)
{
    int equipped = find_nbr(str, "Equipped=");

    if (equipped > 0)
        item->equiped = sfTrue;
    else
        item->equiped = sfFalse;
}

void add_item_to_inventory(player_t *player, char *effect)
{
    stat_t *stat = analyse_effect(effect);
    item_t *item = malloc(sizeof(item_t));
    int pos = strfind(effect, "Name='");

    if (pos != -1)
        item->name = recup_str(effect, pos - 1, '\'');
    else
        item->name = NULL;
    pos = strfind(effect, "Type='");
    if (pos != -1)
        item->type = recup_str(effect, pos - 1, '\'');
    else
        item->type = my_strdup("Usage");
    item->stat = stat;
    item->id_texture = find_nbr(effect, "ID=");
    item->nbr = find_nbr(effect, "Nbr=");
    if (item->nbr == 0)
        item->nbr = 1;
    equipped_item(item, effect);
    append_item(&player->inventory, item);
}