/*
** EPITECH PROJECT, 2019
** utilities
** File description:
** utilities to help adapted
*/

#include <SFML/System/Vector2.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <stdlib.h>

sfVector2f create_vect(float x, float y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfColor create_color(int red, int blue, int green, int alpha)
{
    sfColor color;

    color.r = red;
    color.b = blue;
    color.g = green;
    color.a = alpha;
    return (color);
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rectangle;

    rectangle.top = top;
    rectangle.left = left;
    rectangle.height = height;
    rectangle.width = width;
    return (rectangle);
}

sfFloatRect create_frect(float top, float left, float width, float height)
{
    sfFloatRect rectangle;

    rectangle.top = top;
    rectangle.left = left;
    rectangle.height = height;
    rectangle.width = width;
    return (rectangle);
}