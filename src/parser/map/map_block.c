/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_block
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include "struct/map.h"
#include "proto/proto.h"
#include "proto/lib.h"

void add_block(block_invi_t **list, sfFloatRect rect)
{
    block_invi_t *new = malloc(sizeof(block_invi_t));
    block_invi_t *save = *list;

    while (*list && (*list)->next != NULL)
        *list = (*list)->next;
    new->next = NULL;
    new->rect = rect;
    if (*list == NULL)
        *list = new;
    else {
        (*list)->next = new;
        *list = save;
    }
}

void map_block(FILE *fp, map_t *map)
{
    char *buff = NULL;
    size_t size = 0;
    sfIntRect rect;

    getline(&buff, &size, fp);
    free(buff);
    buff = NULL;
    while (getline(&buff, &size, fp) != -1 && buff != NULL && (buff[0] == 'B'
    || buff[0] == '#')) {
        if (buff[0] != '#') {
            rect = rect_recup(buff);
            add_block(&map->block, create_frect(rect.top, rect.left
            , rect.width, rect.height));
        }
        free(buff);
        buff = NULL;
        size = 0;
    }
}

void free_block(map_t *map)
{
    block_invi_t *save;

    while (map->block != NULL) {
        save = map->block;
        map->block = map->block->next;
        free(save);
    }
}