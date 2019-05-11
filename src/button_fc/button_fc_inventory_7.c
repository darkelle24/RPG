/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** button_fc_inventory_7
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void destroy_item_fc_2(int nbr, scene_t *scene)
{
    int i = 2;
    button_t *button;

    if (nbr != 17) {
        button = button_find(scene->list_but, 200 + nbr);
        button->to_send_click = NULL;
        button->to_send_click2 = NULL;
        button->to_send_click3 = NULL;
        button->callback_hover_exit = NULL;
        button->callback_hover = NULL;
        button->pass = 4;
        while (i != 11) {
            text_find(scene->list_text, 800 + i)->disp = 0;
            i++;
        }
    }
}

void destroy_item_fc(button_t *button, void *item_void)
{
    item_t *item = (item_t *) item_void;
    scene_t *scene = (scene_t *) button->to_send_click2;
    rpg_t *rpg = (rpg_t *) button->to_send_click3;
    inventory_t *save = rpg->player->inventory;
    int nbr = 1;

    if (item->equiped == sfTrue)
        desequipped(item, scene, rpg);
    destroy_item(rpg, item, scene);
    save = rpg->player->inventory;
    while (save != NULL) {
        nbr++;
        save = save->next;
    }
    destroy_item_fc_2(nbr, scene);
}