/*
** EPITECH PROJECT, 2019
** events
** File description:
** handle events
*/

#include "proto/proto.h"
#include "struct/game_struct.h"

void event_on_window(rpg_t *rpg)
{
    if (rpg->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg->window);
}