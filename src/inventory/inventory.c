/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** inventory
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

void inventory(rpg_t *rpg)
{
    scene_t *scene_inventory = load_scene(rpg->assets->tab_scene[1]
    , rpg->assets->tab_text[4]);
    int back = 0;

    if (scene_inventory == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window))
        init_inventory(rpg, scene_inventory, &back);
    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_for_button(rpg->event, scene_inventory, rpg->window);
            event_on_window(rpg);
        }
        sfRenderWindow_clear(rpg->window, sfBlack);
        display_list_display(rpg->window, scene_inventory->order);
        sfRenderWindow_display(rpg->window);
    }
    free_scene(scene_inventory);
}