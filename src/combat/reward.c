/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** reward
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

int set_text_int(scene_t *scene, int id_text, int valeur)
{
    text_t *text = text_find(scene->list_text, id_text);

    if (valeur < 0)
        valeur = 0;
    free(text->str);
    text->str = inttochar(valeur);
    sfText_setString(text->text, text->str);
    return (valeur);
}

int calcul(scene_t *scene, rpg_t *rpg, fight_t *fight)
{
    int total = 0;

    total += set_text_int(scene, 1000, find_nbr(fight->reward, "XP="));
    total += set_text_int(scene, 1001, 500 - (fight->turn * 10));
    total += set_text_int(scene, 1002, (fight->ennemy->lvl
    - rpg->player->lvl) * 50);
    set_text_int(scene, 1003, total);
    total += rpg->player->xp;
    return (total);
}

void reward_menu(rpg_t *rpg, fight_t *fight)
{
    scene_t *scene = load_scene("src/parser/scene_files/reward.dji", NULL);
    int back = 0;

    if (scene == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window))
        reward_init(rpg, scene, fight, &back);
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