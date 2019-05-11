/*
** EPITECH PROJECT, 2019
** create_text.c
** File description:
** create_text.c
*/

#include <SFML/Graphics/Text.h>
#include <SFML/System/Vector2.h>

sfText *create_text(char *valeur, sfVector2f pos, int police, sfFont *font)
{
    sfText *message = sfText_create();

    sfText_setPosition(message, pos);
    sfText_setFont(message, font);
    sfText_setCharacterSize(message, police);
    sfText_setColor(message, sfBlack);
    sfText_setString(message, valeur);
    return (message);
}