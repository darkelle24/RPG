/*
** EPITECH PROJECT, 2019
** exit_dialogue
** File description:
** function for exit a dialogue
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void exit_dial(map_t *map)
{
    button_list_t *save = map->scene->list_but;
    int i = 0;

    while (save != NULL) {
        save->button->pass = 1;
        save = save->next;
    }
    if (map->talk != NULL)
        map->talk->active = 0;
    map->talk = NULL;
    other_find(map->scene->other, 20001)->disp = 0;
    text_find(map->scene->list_text, 20002)->disp = 0;
    while (i != 5) {
        button_find(map->scene->list_but, 99000 + (i + 1))->pass = 4;
        text_find(map->scene->list_text, 20010 + i)->disp = 0;
        i++;
    }
}
