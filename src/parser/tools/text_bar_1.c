/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** text_bar
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "proto/proto.h"

void display_text_bar(other_t *other, sfRenderWindow *window)
{
    sfVector2f pos;
    text_bar_t *text = ((text_bar_t *) other->other);

    if (other->disp != 0) {
        if (text->rect_text != NULL)
            sfRenderWindow_drawRectangleShape(window
            , text->rect_text->rect, NULL);
        sfRenderWindow_drawText(window, text->text, NULL);
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
    && sfRenderWindow_hasFocus(window) == sfTrue) {
        pos = sfRenderWindow_mapPixelToCoords(window
        , sfMouse_getPositionRenderWindow(window)
        , sfRenderWindow_getDefaultView(window));
        if (sfFloatRect_contains(&text->rect, pos.x, pos.y) == sfTrue)
            text->focus = sfTrue;
        else
            text->focus = sfFalse;
    }
    if (text->barre != NULL && text->focus == sfTrue)
        sfRenderWindow_drawRectangleShape(window, text->barre, NULL);
}

void text_bar_write_really(sfEvent event, text_bar_t *text)
{
    sfFloatRect rect;
    sfVector2f pos = sfText_getPosition(text->text);
    sfVector2f size = sfRectangleShape_getSize(text->barre);

    if (text->pos_in_str != 0 && event.key.code == 8) {
        text->pos_in_str--;
        text->str[text->pos_in_str] = '\0';
    } else if (text->pos_in_str != text->lenght_max
    && event.key.code != 8 && event.key.code != 127) {
        text->str[text->pos_in_str] = ((char)event.text.unicode);
        text->pos_in_str++;
    }
    sfText_setString(text->text, text->str);
    rect = sfText_getGlobalBounds(text->text);
    sfRectangleShape_setPosition(text->barre, create_vect(pos.x +
    (size.x / 2) + text->ecart + rect.width, pos.y + (size.y / 2)));
}

void text_bar_write(sfEvent event, scene_t *scene)
{
    other_t *list = scene->other;
    int exit_value = 0;
    text_bar_t *text;

    while (list != NULL && exit_value == 0) {
        if (list->type == 't' && ((text_bar_t *)list->other)->focus == sfTrue)
            exit_value = 1;
        else
            list = list->next;
    }
    if (list != NULL && event.key.code != 13) {
        text = (text_bar_t *) list->other;
        text_bar_write_really(event, text);
    }
}

void text_bar_create_barre(text_bar_t *text, int size_longeur, sfColor color)
{
    sfVector2f pos = sfText_getPosition(text->text);
    float largeur = sfText_getGlobalBounds(text->text).height;
    sfVector2f size = create_vect(size_longeur, largeur);
    int count = 0;

    text->barre = create_rectangle(create_vect(pos.x + text->ecart
    + (size.x / 2), pos.y + (size.y / 2)), create_vect(size_longeur
    , largeur), color);
    while (count != text->lenght_max){
        text->str[count] = '\0';
        count++;
    }
    sfText_setString(text->text, text->str);
    text->pos_in_str = 0;
}

text_bar_t *create_text_bar(int lenght_max, sfVector2f pos
, int sizechar, sfFont *font)
{
    text_bar_t *text_bar = malloc(sizeof(text_bar_t));
    int count = 0;

    text_bar->str = malloc(sizeof(char) * (lenght_max + 1));
    text_bar->text = sfText_create();
    sfText_setCharacterSize(text_bar->text, sizechar);
    sfText_setPosition(text_bar->text, pos);
    text_bar->focus = sfFalse;
    text_bar->lenght_max = lenght_max;
    text_bar->str[lenght_max] = '\0';
    while (count != lenght_max){
        text_bar->str[count] = 'W';
        count++;
    }
    sfText_setFont(text_bar->text, font);
    sfText_setString(text_bar->text, text_bar->str);
    text_bar->rect = sfText_getGlobalBounds(text_bar->text);
    text_bar->barre = NULL;
    return (text_bar);
}