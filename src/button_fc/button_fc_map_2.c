/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_map_2
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

static void save_item(inventory_t *save, FILE *fp)
{
    stat_t *stat;

    while (save != NULL) {
        stat = save->item->stat;
        my_fprintf(fp, "I Name='%s' Type='%s' Equipped=%d ID=%d Nbr=%d "
        , save->item->name, save->item->type, (int) save->item->equiped
        , save->item->id_texture, save->item->nbr);
        my_fprintf(fp, "HP_act=%d HP_max=%d Mana_act=%d Mana_max=%d AD=%d AP=%d"
        , stat->hp, stat->hp_max, stat->mana, stat->mana_max, stat->ad
        , stat->ap);
        my_fprintf(fp, " Armor=%d Magic_Resi=%d Speed=%d \n", stat->armor
        , stat->magic_resi, stat->speed);
        save = save->next;
    }
}

void save_compt_part(competence_t *compt, FILE *fp)
{
    my_fprintf(fp, "Name=\"%s\" Consumtpion=%d Speed=%d "
    , compt->name, compt->consumption, compt->speed);
    my_fprintf(fp, "ID=%d ID_sound=%d ID_text=%d Cooldown=%d "
    , compt->id, compt->id_sound, compt->id_text, compt->cooldown);
    if (compt->degatap != NULL)
        my_fprintf(fp, " DegatAP=\"%s\"", compt->degatap);
    if (compt->degatad != NULL)
        my_fprintf(fp, " DegatAD=\"%s\"", compt->degatad);
    if (compt->heal != NULL)
        my_fprintf(fp, " Heal=\"%s\"", compt->heal);
}

void save_compt(player_t *player, FILE *fp)
{
    my_fprintf(fp, "C ");
    if (player->base != NULL)
        save_compt_part(player->base, fp);
    my_fprintf(fp, "\n");
    my_fprintf(fp, "C ");
    if (player->comp_1 != NULL)
        save_compt_part(player->comp_1, fp);
    my_fprintf(fp, "\n");
    my_fprintf(fp, "C ");
    if (player->comp_2 != NULL)
        save_compt_part(player->comp_2, fp);
    my_fprintf(fp, "\n");
    my_fprintf(fp, "C ");
    if (player->comp_3 != NULL)
        save_compt_part(player->comp_3, fp);
    my_fprintf(fp, "\n");
}

void button_cl_map_save(button_t *but, void *rpg_void)
{
    rpg_t *rpg = (rpg_t *) rpg_void;
    map_t *map = (map_t *) but->to_send_click2;
    FILE *fp = fopen(".save", "w+");
    stat_t *stat = rpg->player->stat;
    inventory_t *save = rpg->player->inventory;

    my_fprintf(fp, "%s\n%d\n%d\n%d\n", rpg->player->name, rpg->player->lvl
    , rpg->player->xp, rpg->player->point);
    my_fprintf(fp, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n", stat->hp, stat->mana
    , stat->hp_max, stat->mana_max, stat->ad, stat->ap, stat->speed
    , stat->armor, stat->magic_resi);
    my_fprintf(fp, "%s\n%d\n%d\n%d\n", map->path
    , (int) sfView_getCenter(map->view).x
    , (int) sfView_getCenter(map->view).y, rpg->mob_kill);
    save_compt(rpg->player, fp);
    save_item(save, fp);
    fclose(fp);
}