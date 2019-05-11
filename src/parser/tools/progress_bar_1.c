/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** progress_bar
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "proto/proto.h"
#include "struct/progress_bar.h"

progress_bar_t *progress_bar_init(sfVector2f pos, sfVector2f size, int pourc)
{
    progress_bar_t *strct = malloc(sizeof(progress_bar_t));

    strct->rect = sfRectangleShape_create();
    strct->rect_ori = sfRectangleShape_create();
    sfRectangleShape_setPosition(strct->rect_ori, pos);
    sfRectangleShape_setSize(strct->rect_ori, size);
    sfRectangleShape_setFillColor(strct->rect_ori, sfTransparent);
    sfRectangleShape_setOutlineColor(strct->rect_ori, sfWhite);
    sfRectangleShape_setOutlineThickness(strct->rect_ori, 5);
    sfRectangleShape_setPosition(strct->rect, pos);
    sfRectangleShape_setFillColor(strct->rect, create_color(200, 200
    , 200, 200));
    sfRectangleShape_setSize(strct->rect, create_vect((size.x / 100 * pourc)
    , size.y));
    strct->pourc = pourc;
    return (strct);
}

void progress_bar_mini_bar(progress_bar_t *strct, int mini_bar
, sfColor color, int size)
{
    int count = 0;
    sfVector2f position;
    sfVector2f size_ori;

    if (mini_bar != 0 && mini_bar != 1) {
        size_ori = sfRectangleShape_getSize(strct->rect_ori);
        position = sfRectangleShape_getPosition(strct->rect_ori);
        strct->mini_bar = malloc(sizeof(sfRectangleShape *) * (mini_bar));
        while (count != mini_bar - 1) {
            strct->mini_bar[count] = sfRectangleShape_create();
            sfRectangleShape_setFillColor(strct->mini_bar[count], color);
            sfRectangleShape_setSize(strct->mini_bar[count], create_vect(size
            , sfRectangleShape_getSize(strct->rect_ori).y));
            sfRectangleShape_setPosition(strct->mini_bar[count]
            , create_vect(position.x + (size_ori.x
            / mini_bar * (count + 1)) - (size / 2), position.y));
            count++;
        }
        strct->mini_bar[count] = NULL;
    } else
        strct->mini_bar = NULL;
}

void progress_bar_change_value(progress_bar_t *pro_bar, float new_value)
{
    sfVector2f size = sfRectangleShape_getSize(pro_bar->rect_ori);

    pro_bar->pourc = new_value;
    if (pro_bar->pourc <= 0) {
        sfRectangleShape_setSize(pro_bar->rect, create_vect(0, size.y));
    } else if (pro_bar->pourc >= 100) {
        sfRectangleShape_setSize(pro_bar->rect, size);
    } else {
        sfRectangleShape_setSize(pro_bar->rect, create_vect(
        (pro_bar->pourc / 100) * size.x, size.y));
    }
}

void progress_bar_active(progress_bar_t *pro_bar, sfRenderWindow *window)
{
    int count = 0;

    sfRenderWindow_drawRectangleShape(window, pro_bar->rect_ori, NULL);
    sfRenderWindow_drawRectangleShape(window, pro_bar->rect, NULL);
    if (pro_bar->mini_bar != NULL) {
        while (pro_bar->mini_bar[count] != NULL) {
            sfRenderWindow_drawRectangleShape(window, pro_bar->mini_bar[count]
            , NULL);
            count++;
        }
    }
}

void progress_bar_display(other_t *other, sfRenderWindow *window)
{
    progress_bar_active(((progress_bar_t *) other->other), window);
}