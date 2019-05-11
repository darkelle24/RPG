/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** free_scene
*/

#include <stddef.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "proto/proto.h"

void game_list_remove(game_list *list, game_object *object)
{
    game_list *save;

    while (list != NULL && list->next->object != object)
        list = list->next;
    if (list != NULL) {
        list->next->object = NULL;
        save = list->next;
        list->next = list->next->next;
        free(save);
    }
}

void game_list_free(game_list *list)
{
    game_list *save;

    while (list != NULL && list->object != NULL) {
        if (list->object->texture != NULL
        && sfSprite_getTexture(list->object->sprite) != NULL) {
            sfTexture_destroy(list->object->texture);
            list->object->texture = NULL;
        }
        sfSprite_destroy(list->object->sprite);
        free(list->object);
        save = list;
        list = list->next;
        free(save);
    }
}

void text_list_free(text_list_t *list)
{
    text_list_t *save;

    if (list->text != NULL) {
        while (list != NULL) {
            save = list;
            list = list->next;
            sfText_destroy(save->text->text);
            if (save->text->str != NULL)
                free(save->text->str);
            free(save->text);
            free(save);
        }
    }
}

void display_list_free(display_order *list)
{
    display_order *save;

    while (list != NULL) {
        save = list;
        list = list->next;
        free(save);
    }
}

void free_scene(scene_t *scene)
{
    if (scene != NULL) {
        button_list_free(scene->list_but);
        game_list_free(scene->list_ob);
        music_list_free(scene->list_music);
        sound_list_free(scene->list_sound);
        text_list_free(scene->list_text);
        display_list_free(scene->order);
        other_free(scene->other);
        if (scene->font != NULL)
            sfFont_destroy(scene->font);
        free(scene);
    }
}