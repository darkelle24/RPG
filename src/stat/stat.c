/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** stat
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

void set_one_stat(scene_t *scene, int valeur, int nbr)
{
    text_t *text = text_find(scene->list_text, nbr);

    free(text->str);
    text->str = inttochar(valeur);
    sfText_setString(text->text, text->str);
}

void set_stat(scene_t *scene, player_t *player)
{
    set_one_stat(scene, player->stat->hp_max, 6001);
    set_one_stat(scene, player->stat->mana_max, 7001);
    set_one_stat(scene, player->stat->ap, 8001);
    set_one_stat(scene, player->stat->ad, 9001);
    set_one_stat(scene, player->stat->armor, 10001);
    set_one_stat(scene, player->stat->magic_resi, 11001);
    set_one_stat(scene, player->stat->speed, 12001);
    set_one_stat(scene, player->point, 5000);
}

void set_xp(scene_t *scene, rpg_t *rpg)
{
    other_t *other = other_find(scene->other, 600);
    text_t *text = text_find(scene->list_text, 601);

    free(text->str);
    text->str = inttochar(rpg->player->lvl);
    sfText_setString(text->text, text->str);
    text = text_find(scene->list_text, 602);
    free(text->str);
    text->str = inttochar(rpg->player->lvl + 1);
    sfText_setString(text->text, text->str);
    progress_bar_change_value((progress_bar_t *) (other->other)
    , ((float) rpg->player->xp
    / ((float) rpg->player->lvl * 10 + 100)) * 100);
}

void stat_init(rpg_t *rpg, scene_t *scene, int *back)
{
    button_find(scene->list_but, 900)->to_send_click = (void *) back;
    button_find(scene->list_but, 901)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 6002)->to_send_click = (void *) scene;
    button_find(scene->list_but, 6002)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 7002)->to_send_click = (void *) scene;
    button_find(scene->list_but, 7002)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 8002)->to_send_click = (void *) scene;
    button_find(scene->list_but, 8002)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 9002)->to_send_click = (void *) scene;
    button_find(scene->list_but, 9002)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 10002)->to_send_click = (void *) scene;
    button_find(scene->list_but, 10002)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 11002)->to_send_click = (void *) scene;
    button_find(scene->list_but, 11002)->to_send_click2 = (void *) rpg;
    button_find(scene->list_but, 12002)->to_send_click = (void *) scene;
    button_find(scene->list_but, 12002)->to_send_click2 = (void *) rpg;
    sfText_setString(text_find(scene->list_text, 151)->text, rpg->player->name);
    set_stat(scene, rpg->player);
    if (rpg->player->point > 0)
        activated_but(scene);
    set_xp(scene, rpg);
}

void stat_display(rpg_t *rpg)
{
    scene_t *scene = load_scene("src/parser/scene_files/stat.dji", NULL);
    int back = 0;

    if (scene == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window))
        stat_init(rpg, scene, &back);
    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_for_button(rpg->event, scene, rpg->window);
            event_on_window(rpg);
        }
        sfRenderWindow_clear(rpg->window, sfBlack);
        display_list_display(rpg->window, scene->order);
        sfRenderWindow_display(rpg->window);
    }
    free_scene(scene);
}