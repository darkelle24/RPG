/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** key_biding
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void init_key_biding(rpg_t *rpg, scene_t *scene, int *back)
{
    button_t *but;

    button_find(scene->list_but, 900)->to_send_click = (void *) back;
    button_find(scene->list_but, 901)->to_send_click = (void *) rpg;
    but = button_find(scene->list_but, 1011);
    but->to_send_click = (void *) scene;
    but->to_send_click2 = (void *) rpg;
}

void key_biding(rpg_t *rpg)
{
    scene_t *scene_key_biding = load_scene(rpg->assets->tab_scene[3], NULL);
    int back = 0;

    if (scene_key_biding == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window))
        init_key_biding(rpg, scene_key_biding, &back);
    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_for_button(rpg->event, scene_key_biding, rpg->window);
            event_on_window(rpg);
        }
        sfRenderWindow_clear(rpg->window, sfBlack);
        display_list_display(rpg->window, scene_key_biding->order);
        sfRenderWindow_display(rpg->window);
    }
    free_scene(scene_key_biding);
}