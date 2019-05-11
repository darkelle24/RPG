/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** option_2
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void set_value_frame_rate(rpg_t *rpg, scene_t *scene)
{
    text_bar_t *text = (text_bar_t *)
    (other_find(scene->other, 300)->other);
    char *nbr = inttochar(rpg->option->fps);
    int i = 0;
    sfFloatRect rect;
    sfVector2f pos = sfText_getPosition(text->text);
    sfVector2f size = sfRectangleShape_getSize(text->barre);

    while (nbr[i] != '\0') {
        text->str[i] = nbr[i];
        i++;
        text->pos_in_str++;
    }
    sfText_setString(text->text, text->str);
    rect = sfText_getGlobalBounds(text->text);
    sfRectangleShape_setPosition(text->barre, create_vect(pos.x +
    (size.x / 2) + text->ecart + rect.width, pos.y + (size.y / 2)));
    free(nbr);
}