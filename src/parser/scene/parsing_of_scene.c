/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** parsing_of_scene
*/

#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "other/tab_of_fc.h"
#include "struct/text.h"
#include "struct/scene.h"
#include "proto/proto.h"
#include "proto/lib.h"

sfColor recup_color(char *phrase, int pos)
{
    char *strr = recup_str(phrase, pos, ',');
    char *strb = recup_str(phrase
    , pos + my_strlenchar(strr, '\0') + 1, ',');
    char *strg = recup_str(phrase
    , pos + my_strlenchar(strr, '\0')
    + my_strlenchar(strb, '\0') + 2, ',');
    char *stra = recup_str(phrase
    , pos + my_strlenchar(strr, '\0')
    + my_strlenchar(strb, '\0') + my_strlenchar(strg, '\0') + 3, ')');
    sfColor color = create_color(getnbr(strr), getnbr(strb), getnbr(strg),
    getnbr(stra));

    free(strr);
    free(strb);
    free(strg);
    free(stra);
    return (color);
}

int command_test(char *phrase, scene_t *scene)
{
    int count = 0;

    while (Class_name[count] != NULL) {
        if (Class_name[count][0] == phrase[0]) {
            Command[count](scene, phrase);
            return (1);
        }
        count++;
    }
    return (-1);
}

void init_scene(scene_t *scene, texture_list_t *list)
{
    scene->texture_list = list;
    scene->list_but = create_button_list();
    scene->list_ob = create_game_list();
    scene->list_text = create_text_list();
    scene->list_music = create_music_list();
    scene->list_sound = create_sound_list();
    scene->other = NULL;
    scene->order = create_display_list();
    scene->font = NULL;
    scene->keyboard = NULL;
}

void write_error_path(char *path)
{
    write(2, "Problem with open scene : ", 26);
    write(2, path, my_strlen(path));
    write(2, "\n", 1);
}

scene_t *load_scene(char *path, texture_list_t *list)
{
    FILE *fp = fopen(path, "r");
    char *buff = NULL;
    size_t len = 0;
    scene_t *scene = malloc(sizeof(scene_t));

    if (fp == NULL || strfind(path, ".dji") == -1) {
        write_error_path(path);
        return (NULL);
    }
    init_scene(scene, list);
    while (getline(&buff, &len, fp) != -1) {
        if (buff[0] != '#') {
            if (command_test(buff, scene) == -1)
                return NULL;
        }
        free(buff);
        buff = NULL;
    }
    fclose(fp);
    return (scene);
}
