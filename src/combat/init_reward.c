/*
** EPITECH PROJECT, 2019
** init_reward
** File description:
** functions for initialise rewards
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

void reward_item_4(int count, scene_t *scene)
{
    if (count >= 15) {
        button_activate(button_find(scene->list_but, 903)
        , create_color(150, 150, 150, 150));
        text_find(scene->list_text, 902)->disp = 1;
        text_find(scene->list_text, 903)->disp = 1;
    }
}

void reward_init_3(rpg_t *rpg, scene_t *scene, fight_t *fight)
{
    char *item = recup_str_spe(fight->reward, "Item={", '}');
    inventory_t *save = fight->player->inventory;
    int count = 0;
    text_t *text = text_find(scene->list_text, 901);

    button_find(scene->list_but, 903)->to_send_click = (void *) rpg;
    if (item != NULL) {
        while (save != NULL) {
            count++;
            save = save->next;
        }
        text_find(scene->list_text, 900)->disp = 1;
        text->disp = 1;
        text->str = recup_str_spe(item, "Name=\'", '\'');
        sfText_setString(text->text, text->str);
        reward_item_4(count, scene);
        free(item);
    }
}

void reward_init_2(rpg_t *rpg, scene_t *scene, fight_t *fight)
{
    progress_bar_t *prog = (progress_bar_t *) (other_find(scene->other
    , 600)->other);
    text_t *text = text_find(scene->list_text, 401);

    progress_bar_change_value(prog, ((float) rpg->player->xp
    / ((float) rpg->player->lvl * 10 + 100)) * 100);
    set_text_int(scene, 601, rpg->player->lvl);
    set_text_int(scene, 602, rpg->player->lvl + 1);
    free(text->str);
    text->str = str_append(inttochar(fight->player->xp), "\\", 1, 0);
    text->str = str_append(text->str, inttochar(rpg->player->lvl * 10 + 100)
    , 1, 1);
    sfText_setString(text->text, text->str);
    set_text_mid(text->text
    , sfRectangleShape_getGlobalBounds(prog->rect_ori));
}

void reward_init(rpg_t *rpg, scene_t *scene, fight_t *fight, int *back)
{
    int total = 0;
    int point = 0;
    int lvl = 0;

    button_find(scene->list_but, 901)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 902)->to_send_click = (void *) back;
    button_find(scene->list_but, 902)->to_send_click2 = (void *) fight;
    total = calcul(scene, rpg, fight);
    while (total > (lvl + rpg->player->lvl) * 10 + 100) {
        total -= (lvl + rpg->player->lvl) * 10 + 100;
        lvl++;
        point += (lvl + rpg->player->lvl) % 3 + 10;
    }
    set_text_int(scene, 1004, lvl);
    set_text_int(scene, 1005, point);
    rpg->player->xp = total;
    rpg->player->lvl += lvl;
    rpg->player->point += point;
    reward_init_2(rpg, scene, fight);
    reward_init_3(rpg, scene, fight);
}