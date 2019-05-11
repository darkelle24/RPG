/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** dialogue
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void diag_read_2(map_t *map)
{
    char *buff = NULL;
    size_t size = 0;
    text_t *text = NULL;
    int i = 0;

    while (i != 5) {
        text = text_find(map->scene->list_text, 20010 + i);
        text->disp = 0;
        buff = NULL;
        if (map->diag != NULL && getline(&buff, &size, map->diag) != -1) {
            free(text->str);
            text->str = buff;
            sfText_setString(text->text, text->str);
            text->disp = 1;
        } else if (map->diag != NULL) {
            fclose(map->diag);
            map->diag = NULL;
        }
        i++;
    }
}

void diag_read(rpg_t *rpg, map_t *map)
{
    char *buff = NULL;
    size_t size = 0;

    if (getline(&buff, &size, map->diag) != -1) {
        recup_name(map, buff, rpg);
        diag_read_2(map);
        buff = NULL;
        if (map->diag != NULL) {
            getline(&buff, &size, map->diag);
            free(buff);
        }
    } else {
        fclose(map->diag);
        map->diag = NULL;
        exit_dial(map);
        return ;
    }
}

void diag_mouse_press(rpg_t *rpg, map_t *map)
{
    other_t *other = other_find(map->scene->other, 20001);

    if (other->disp == 1 && map->diag == NULL) {
        exit_dial(map);
    } else if (other->disp == 1 && map->diag != NULL)
        diag_read(rpg, map);
}

void dialogue_init_2(map_t *map, char *str, rpg_t *rpg)
{
    entity_t *save_en = map->entity;

    while (save_en != NULL && save_en->str != str)
        save_en = save_en->next;
    if (save_en != NULL) {
        map->talk = save_en;
        diag_read(rpg, map);
    } else
        diag_read(rpg, map);
}

void dialogue_init(rpg_t *rpg, map_t *map, char *str)
{
    button_list_t *save = map->scene->list_but;
    int i = 0;

    while (save != NULL) {
        save->button->pass = 2;
        save = save->next;
    }
    other_find(map->scene->other, 20001)->disp = 1;
    text_find(map->scene->list_text, 20002)->disp = 1;
    while (i != 5) {
        button_find(map->scene->list_but, 99000 + (i + 1))->pass = 4;
        text_find(map->scene->list_text, 20010 + i)->disp = 1;
        i++;
    }
    map->diag = fopen(str, "r");
    if (map->diag != NULL) {
        dialogue_init_2(map, str, rpg);
    } else
        exit_dial(map);
}