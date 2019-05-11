/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** scene_music
*/

#include <stdlib.h>
#include <unistd.h>
#include "struct/scene.h"
#include "proto/proto.h"

multi_music *create_music_list(void)
{
    multi_music *list = malloc(sizeof(multi_music));

    if (list == NULL)
        return (NULL);
    list->music = NULL;
    list->next = NULL;
    return (list);
}

int music_list_add(multi_music *list, sfMusic *music, int id)
{
    while (list->next != NULL)
        list = list->next;
    if (list->music == NULL) {
        list->music = music;
        list->id = id;
    } else {
        list->next = malloc(sizeof(multi_music));
        if (list->next == NULL)
            return (-1);
        list->next->music = music;
        list->next->id = id;
        list->next->next = NULL;
    }
    return (0);
}

void music_list_free(multi_music *list)
{
    multi_music *save;

    while (list != NULL) {
        sfMusic_destroy(list->music);
        save = list;
        list = list->next;
        free(save);
    }
}

void scene_music(scene_t *scene, char *phrase)
{
    char *path = path_recup(phrase);
    int id = find_nbr(phrase, "ID=");
    int volume = find_nbr(phrase, "Vol=");
    int loop = find_nbr(phrase, "Loop=");
    sfMusic *music;

    music = sfMusic_createFromFile(path);
    if (music == NULL) {
        write(2, "Problem with the path of a music\n", 33);
        return;
    }
    sfMusic_setVolume(music, volume);
    sfMusic_setLoop(music, loop);
    music_list_add(scene->list_music, music, id);
}