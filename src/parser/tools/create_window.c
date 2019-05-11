/*
** EPITECH PROJECT, 2019
** create_window.c
** File description:
** create_window.c
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_windows(int width, int height, int bit, char *title)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bit;
    window = sfRenderWindow_create
    (video_mode, title, sfFullscreen, NULL);
    return (window);
}
