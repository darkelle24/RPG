/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** scene_other_3
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "struct/progress_bar.h"
#include "proto/proto.h"

void scene_progress_bar_2(progress_bar_t *pro, char *phrase)
{
    int mini_bar = find_nbr(phrase, "MB=");
    int size = find_nbr(phrase, "SizeMB=");
    sfColor color = color_recup(phrase, "Color_MB=");

    progress_bar_mini_bar(pro, mini_bar, color, size);
}

void scene_progress_bar(scene_t *scene, char *phrase)
{
    sfVector2f position = pos_object_recup_str(phrase, "Pos=");
    sfVector2f size = pos_object_recup_str(phrase, "Size=");
    sfColor color = color_recup(phrase, "Color=");
    sfColor color_miss = color_recup(phrase, "Color_Miss=");
    sfColor color_out = color_recup(phrase, "Color_Out=");
    int outlinethick = find_nbr(phrase, "Size_Out=");
    int pourc = find_nbr(phrase, "Pour=");
    int prio = find_nbr(phrase, "Prio=");
    int disp = find_nbr(phrase, "Disp=");
    int id = find_nbr(phrase, "ID=");
    progress_bar_t *pro = progress_bar_init(position, size, pourc);
    other_t *other = other_list_add(&scene->other, (void *) pro, 'P', id);

    scene_progress_bar_2(pro, phrase);
    other->disp = disp;
    sfRectangleShape_setOutlineColor(pro->rect_ori, color_out);
    sfRectangleShape_setOutlineThickness(pro->rect_ori, outlinethick);
    sfRectangleShape_setFillColor(pro->rect, color);
    sfRectangleShape_setFillColor(pro->rect_ori, color_miss);
    display_list_add_other(&scene->order, other, prio);
}

void volume_bar_set_value(volume_bar_t *vol, int value)
{
    sfVector2f size = sfRectangleShape_getSize(vol->rect_ori);

    sfRectangleShape_setSize(vol->rect, create_vect((size.x / 100 * value)
    , size.y));
    vol->volume = value;
}