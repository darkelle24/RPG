/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** progress_bar_2
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "proto/proto.h"
#include "struct/progress_bar.h"

void progress_bar_free(void *pro_bar_void)
{
    int count = 0;
    progress_bar_t *pro_bar = pro_bar_void;

    sfRectangleShape_destroy(pro_bar->rect);
    sfRectangleShape_destroy(pro_bar->rect_ori);
    if (pro_bar->mini_bar != NULL) {
        while (pro_bar->mini_bar[count] != NULL) {
            sfRectangleShape_destroy(pro_bar->mini_bar[count]);
            count++;
        }
        free(pro_bar->mini_bar);
    }
}