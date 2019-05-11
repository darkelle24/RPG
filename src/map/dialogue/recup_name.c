/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** recup_name
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void recup_name(map_t *map, char *buff, rpg_t *rpg)
{
    text_t *text = text_find(map->scene->list_text, 20002);
    char *name = NULL;

    free(text->str);
    name = recup_str_spe(buff, "Name=\"", '\"');
    if (name == NULL)
        text->str = my_strdup(rpg->player->name);
    else
        text->str = name;
    sfText_setString(text->text, text->str);
}