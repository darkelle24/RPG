/*
** EPITECH PROJECT, 2019
** init_inventory_item
** File description:
** functions for initialise items in inventory
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"
#include "struct/inventory.h"

void init_item_inventory_2(inventory_t *list, scene_t *scene, int i, rpg_t *rpg)
{
    button_t *button;
    game_object *obj;
    text_t *text;

    button = button_find(scene->list_but, 200 + i);
    button->keyboard = 1;
    button->to_send_click = (void *) list->item;
    button->to_send_click2 = (void *) scene;
    button->to_send_click3 = (void *) rpg;
    button_activate(button, create_color(255, 255, 255, 100));
    obj = game_object_find(scene->list_ob, 200 + i);
    obj->texture = NULL;
    sfSprite_setTexture(obj->sprite, find_texture(scene->texture_list
    , list->item->id_texture), sfTrue);
    obj->display = 1;
    text_find(scene->list_text, 1000 + i)->disp = 1;
    text = text_find(scene->list_text, 1100 + i);
    text->disp = 1;
    sfText_setString(text->text, list->item->type);
}

void init_item_inventory(rpg_t *rpg, scene_t *scene)
{
    inventory_t *list = rpg->player->inventory;
    int i = 1;
    text_t *text;

    while (list != NULL) {
        init_item_inventory_2(list, scene, i, rpg);
        text = text_find(scene->list_text, 200 + i);
        sfText_setString(text->text, list->item->name);
        text->disp = 1;
        text_find(scene->list_text, 300 + i)->disp = 1;
        text = text_find(scene->list_text, 400 + i);
        text->disp = 1;
        text->str = inttochar(list->item->nbr);
        sfText_setString(text->text, text->str);
        if (list->item->equiped == sfTrue) {
            text_find(scene->list_text, 1200 + i)->disp = 1;
            set_part(list->item, scene);
        }
        i++;
        list = list->next;
    }
}