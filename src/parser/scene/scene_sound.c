/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** scene_sound
*/

#include <SFML/Audio/Sound.h>
#include <SFML/Audio/SoundBuffer.h>
#include <unistd.h>
#include <stdlib.h>
#include "struct/music_sound.h"
#include "struct/scene.h"
#include "proto/proto.h"

multi_sound *create_sound_list(void)
{
    multi_sound *list = malloc(sizeof(multi_sound));

    if (list == NULL)
        return (NULL);
    list->sound = NULL;
    list->buffersound = NULL;
    list->next = NULL;
    return (list);
}

int sound_list_add(multi_sound *list, sfSound *sound
, sfSoundBuffer *buffer, int id)
{
    while (list->next != NULL)
        list = list->next;
    if (list->sound == NULL) {
        list->sound = sound;
        list->buffersound = buffer;
        list->id = id;
    } else {
        list->next = malloc(sizeof(multi_sound));
        if (list->next == NULL)
            return (-1);
        list->next->sound = sound;
        list->next->buffersound = buffer;
        list->next->id = id;
        list->next->next = NULL;
    }
    return (0);
}

void sound_list_free(multi_sound *list)
{
    multi_sound *save;

    while (list != NULL) {
        sfSound_destroy(list->sound);
        sfSoundBuffer_destroy(list->buffersound);
        save = list;
        list = list->next;
        free(save);
    }
}

void scene_sound(scene_t *scene, char *phrase)
{
    char *path = path_recup(phrase);
    int id = find_nbr(phrase, "ID=");
    int volume = find_nbr(phrase, "Vol=");
    int loop = find_nbr(phrase, "Loop=");
    sfSoundBuffer *soundbuf;
    sfSound *sound = sfSound_create();

    soundbuf = sfSoundBuffer_createFromFile(path);
    if (soundbuf == NULL) {
        write(2, "Problem with the path of a sound\n", 33);
        return;
    }
    sfSound_setBuffer(sound, soundbuf);
    sfSound_setVolume(sound, volume);
    sfSound_setLoop(sound, loop);
    sound_list_add(scene->list_sound, sound, soundbuf, id);
}