/*
** EPITECH PROJECT, 2019
** button_fc_stat
** File description:
** function for manage desactivation of buttons in stat scene
*/

#include "proto/proto.h"
#include "proto/lib.h"
#include "other/macro.h"

void desactivated_but(scene_t *scene)
{
    int i = 0;
    button_t *but;

    while (i != 7) {
        text_find(scene->list_text, 6003 + (i * 1000))->disp = 0;
        but = button_find(scene->list_but, 6002 + (i * 1000));
        but->keyboard = 0;
        button_invi_and_desac(but);
        i++;
    }
}