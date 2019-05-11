/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_reward
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void but_fc_hv_reward(button_t *but, IGNORE void *scene_void)
{
    sfRectangleShape_setFillColor(but->rect, create_color(70, 70, 70, 255));
    sfRectangleShape_setOutlineColor(but->rect, create_color(160, 160
    , 160, 255));
    but->pass = 5;
}

void but_fc_hvex_reward(button_t *but, IGNORE void *scene_void)
{
    sfRectangleShape_setFillColor(but->rect, create_color(130, 130, 130, 255));
    sfRectangleShape_setOutlineColor(but->rect, create_color(255, 255
    , 255, 255));
    but->pass = 1;
}

void but_fc_pr_reward(button_t *but, IGNORE void *scene_void)
{
    sfRectangleShape_setFillColor(but->rect, create_color(30, 30, 30, 255));
    sfRectangleShape_setOutlineColor(but->rect, create_color(110, 110
    , 110, 255));
    but->pass = 6;
}

void but_fc_cl_reward_inventory(IGNORE button_t *but, void *rpg_void)
{
    inventory((rpg_t *) rpg_void);
}

void but_fc_rl_reward(button_t *but, void *back_void)
{
    int *back = (int *) back_void;
    fight_t *fight = (fight_t *) but->to_send_click2;
    inventory_t *save = fight->player->inventory;
    int count = 0;
    char *item = recup_str_spe(fight->reward, "Item={", '}');

    if (item != NULL) {
        while (save != NULL) {
            count++;
            save = save->next;
        }
        if (count < 15)
            add_item_to_inventory(fight->player, item);
        free(item);
    }
    *back = 1;
    but->pass = 1;
}