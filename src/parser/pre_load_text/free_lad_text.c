/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** free_lad_text
*/

#include <SFML/Graphics.h>
#include "struct/texture_load.h"
#include "proto/lib.h"
#include "proto/proto.h"

void free_text_list(texture_list_t *list)
{
    texture_list_t *save;

    while (list != NULL) {
        sfTexture_destroy(list->texture);
        save = list;
        list = list->next;
        free(save);
    }
}