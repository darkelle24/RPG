/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** tab_of_fc
*/

#ifndef TAB_OF_FC_H_
    #define TAB_OF_FC_H_
    #include "struct/scene.h"
    #include "proto/proto.h"

    const char *Class_name[] = {
        "G",
        "B",
        "M",
        "S",
        "T",
        "F",
        "V",
        "P",
        "R",
        "t",
        NULL
    };

    void (* const Command[])(scene_t *, char *) = {
        &scene_object,
        &scene_button,
        &scene_music,
        &scene_sound,
        &scene_text,
        &scene_font,
        &scene_volume_bar,
        &scene_progress_bar,
        &scene_rectangle,
        &scene_text_bar
    };

#endif /* !TAB_OF_FC_H_ */
