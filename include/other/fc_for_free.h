/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** fc_for_free
*/

#ifndef FC_FOR_FREE_H_
    #define FC_FOR_FREE_H_

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "struct/scene.h"

    const char disp_name_free[] = {
        'V',
        'P',
        'R',
        't'
    };

    void (* const command_free[])(void *) = {
        &volume_bar_free,
        &progress_bar_free,
        &rectangle_free,
        &text_bar_free,
        NULL
    };


#endif /* !FC_FOR_FREE_H_ */