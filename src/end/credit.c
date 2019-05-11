/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** credit
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void credit(rpg_t *rpg)
{
    int back = 0;
    game_object *obj = create_object("assets/images/end.png"
    , create_vect(960, 540), create_rect(0, 0, 1920, 1080), 1);

    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_on_window(rpg);
            if (rpg->event.type == sfEvtKeyReleased
            && rpg->event.key.code == sfKeyEscape)
                back = 1;
        }
        sfRenderWindow_drawSprite(rpg->window, obj->sprite, NULL);
        sfRenderWindow_display(rpg->window);
    }
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    free(obj);
}