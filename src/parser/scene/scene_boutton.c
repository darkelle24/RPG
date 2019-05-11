/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** scene_boutton
*/

#include <SFML/Graphics/Color.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "other/fc_for_button.h"
#include "proto/lib.h"
#include "proto/proto.h"

sfVector2f pos_object_recup_str(char *phrase, char *to_find)
{
    int pos = strfind(phrase, to_find);

    if (pos != -1)
        return (recup_pos(phrase, pos));
    else
        return (create_vect(0, 0));
}

int find_fc(char *phrase, int pos)
{
    char *find = recup_str(phrase, pos - 1, ' ');
    int i = 0;

    while (fc_name[i] != NULL && strfind(fc_name[i], find) == -1) {
        i++;
    }
    free(find);
    if (fc_name[i] == NULL)
        return (-1);
    return (i);
}

void set_button_call(button_t *button, char *phrase, char *to_find, int i)
{
    int pos = strfind(phrase, to_find);
    int fc_pos;

    if (pos != -1) {
        fc_pos = find_fc(phrase, pos);
        if (i == 1) {
            if (fc_pos != -1)
                button_set_callback_on_click(button, fonction[fc_pos], NULL);
            else
                button_set_callback_on_click(button, NULL, NULL);
        } else if (i == 2 && fc_pos != -1) {
            button->callback_hover = fonction[fc_pos];
        } else {
            if (i == 3 && fc_pos != -1)
                button->callback_hover_exit = fonction[fc_pos];
            else if (i == 4 && fc_pos != -1)
                button->callback_click_press = fonction[fc_pos];
        }
    }
}

void set_fc_call(button_t *bouton, char *phrase, scene_t *scene)
{
    char *path = path_recup(phrase);
    sfTexture *texture = find_texture(scene->texture_list
    , find_nbr(phrase, "ID_text="));
    int keyboard = find_nbr(phrase, "Key=");
    sfIntRect rect = rect_recup(phrase);

    set_button_call(bouton, phrase, "Fc_clrl=", 1);
    set_button_call(bouton, phrase, "Fc_ho=", 2);
    set_button_call(bouton, phrase, "Fc_hoex=", 3);
    set_button_call(bouton, phrase, "Fc_clpr=", 4);
    if (path != NULL) {
        bouton->texture = sfTexture_createFromFile(path, NULL);
        sfRectangleShape_setTexture(bouton->rect, bouton->texture, sfFalse);
        free(path);
    } else if (texture != NULL)
        sfRectangleShape_setTexture(bouton->rect, texture, sfFalse);
    if (keyboard > 0)
        bouton->keyboard = sfTrue;
    sfRectangleShape_setTextureRect(bouton->rect, rect);
}

void scene_button(scene_t *scene, char *phrase)
{
    button_t *bouton = malloc(sizeof(button_t));
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfVector2f size = pos_object_recup_str(phrase, "Size=");
    sfColor color = color_recup(phrase, "Color=");
    sfColor color_outline = color_recup(phrase, "Color_Out=");
    int status = find_nbr(phrase, "Status=");
    int id = find_nbr(phrase, "ID=");
    int prio = find_nbr(phrase, "Prio=");
    int game_object_link = find_nbr(phrase, "GO=");
    int outline_thick = find_nbr(phrase, "Size_Out=");

    button_init(bouton, position, size, id);
    if (status == 0)
        status = 4;
    button_set_status(bouton, status, color);
    if (game_object_link != 0)
        bouton->on_button = game_object_find(scene->list_ob, game_object_link);
    set_fc_call(bouton, phrase, scene);
    button_set_outline(bouton, outline_thick, color_outline);
    button_list_add(scene->list_but, bouton);
    display_list_add_button(&scene->order, bouton, prio);
}