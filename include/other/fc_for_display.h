/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** fc_for_display
*/

#ifndef FC_FOR_DISPLAY_H_
    #define FC_FOR_DISPLAY_H_

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "struct/scene.h"

    const char disp_name[] = {
        'V',
        'P',
        'R',
        't'
    };

    void (* const command[])(other_t *, sfRenderWindow *) = {
        &volume_bar_display,
        &progress_bar_display,
        &rectangle_display,
        &display_text_bar,
        NULL
    };

#endif /* !FC_FOR_DISPLAY_H_ */
