/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** music_soud_lib
*/

#include <SFML/Audio/Sound.h>
#include "struct/scene.h"

sfSound *sound_find(multi_sound *list_sound, int id)
{
    while (list_sound != NULL && list_sound->sound != NULL
    && list_sound->id != id) {
        list_sound = list_sound->next;
    }
    if (list_sound == NULL)
        return (NULL);
    return (list_sound->sound);
}