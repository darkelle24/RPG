/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_inventory_6
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void init_spe_stat_2(rpg_t *rpg, scene_t *scene, text_t *text)
{
    text = text_find(scene->list_text, 706);
    free(text->str);
    text->str = inttochar(rpg->player->stat->mana_max);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 707);
    free(text->str);
    text->str = inttochar(rpg->player->stat->ap);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 708);
    free(text->str);
    text->str = inttochar(rpg->player->stat->armor);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 709);
    free(text->str);
    text->str = inttochar(rpg->player->stat->magic_resi);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 710);
    free(text->str);
    text->str = inttochar(rpg->player->stat->speed);
    sfText_setString(text->text, text->str);
}

void init_spe_stat(rpg_t *rpg, scene_t *scene)
{
    text_t *text;

    text = text_find(scene->list_text, 702);
    free(text->str);
    text->str = inttochar(rpg->player->stat->hp);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 703);
    free(text->str);
    text->str = inttochar(rpg->player->stat->hp_max);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 704);
    free(text->str);
    text->str = inttochar(rpg->player->stat->ad);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 705);
    free(text->str);
    text->str = inttochar(rpg->player->stat->mana);
    sfText_setString(text->text, text->str);
    init_spe_stat_2(rpg, scene, text);
}

void change_nbr(item_t *item, scene_t *scene, inventory_t *list)
{
    int i = 1;
    text_t *text;

    while (list->item != item) {
        i++;
        list = list->next;
    }
    text = text_find(scene->list_text, 400 + i);
    free(text->str);
    text->str = inttochar(item->nbr);
    sfText_setString(text->text, text->str);
}

game_object *check_type(game_object *obj, item_t *item, scene_t *scene)
{
    int value = -1;

    if ((value = strfind(item->type, "Head")) != -1)
        obj = game_object_find(scene->list_ob, 2001);
    if (value == -1 && (value = strfind(item->type, "Weapon")) != -1)
        obj = game_object_find(scene->list_ob, 2004);
    if (value == -1 && (value = strfind(item->type, "Chestplate")) != -1)
        obj = game_object_find(scene->list_ob, 2002);
    if (value == -1 && (value = strfind(item->type, "Boots")) != -1)
        obj = game_object_find(scene->list_ob, 2003);
    return (obj);
}

void equipped(item_t *item, scene_t *scene, rpg_t *rpg)
{
    game_object *obj = NULL;
    int i = 1;
    inventory_t *list = rpg->player->inventory;

    test_desequipped(item, scene, rpg);
    obj = check_type(obj, item, scene);
    obj->display = 1;
    sfSprite_setTexture(obj->sprite
    , find_texture(scene->texture_list, item->id_texture), sfFalse);
    add_effect(item, rpg->player, 0);
    item->equiped = sfTrue;
    init_spe_stat(rpg, scene);
    change_effect(rpg, scene);
    while (list->item != item) {
        i++;
        list = list->next;
    }
    text_find(scene->list_text, 1200 + i)->disp = 1;
}