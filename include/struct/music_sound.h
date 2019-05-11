/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** music_sound
*/

#ifndef MUSIC_SOUND_H_
    #define MUSIC_SOUND_H_

    #include <SFML/Audio.h>

    typedef struct multi_music_t
    {
        sfMusic *music;
        int id;
        struct multi_music_t *next;
    }       multi_music;

    typedef struct multi_sound_t
    {
        sfSound *sound;
        sfSoundBuffer *buffersound;
        int id;
        struct multi_sound_t *next;
    }       multi_sound;

#endif /* !MUSIC_SOUND_H_ */
