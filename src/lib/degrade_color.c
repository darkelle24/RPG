/*
** EPITECH PROJECT, 2019
** color.c
** File description:
** color.
*/

#include <SFML/Graphics/Color.h>
#include "struct/color.h"

colordegrade create_degrade(sfColor color, colordegradsens_t sens)
{
    colordegrade colordeg;

    colordeg.degrade = color;
    colordeg.sensr = sens.sensr;
    colordeg.sensb = sens.sensb;
    colordeg.sensg = sens.sensg;
    colordeg.sensa = sens.sensa;
    return (colordeg);
}

colordegradsens_t create_sensdregrad(int sensr, int sensb, int sensg, int sensa)
{
    colordegradsens_t colordsens;

    colordsens.sensr = sensr;
    colordsens.sensb = sensb;
    colordsens.sensg = sensg;
    colordsens.sensa = sensa;
    return (colordsens);
}

sfColor degrade_color_basse(colordegrade *coloradd, sfColor actuelle)
{
    if (actuelle.r <= 0) {
        actuelle.r = 0;
        coloradd->sensr = 1;
    }
    if (actuelle.g <= 0) {
        actuelle.g = 0;
        coloradd->sensg = 1;
    }
    if (actuelle.b <= 0) {
        actuelle.b = 0;
        coloradd->sensb = 1;
    }
    if (actuelle.a <= 0) {
        actuelle.a = 0;
        coloradd->sensa = 1;
    }
    return (actuelle);
}

sfColor degrade_color_haute(colordegrade *coloradd, sfColor actuelle)
{
    if (actuelle.r >= 255) {
        actuelle.r = 255;
        coloradd->sensr = -1;
    }
    if (actuelle.g >= 255) {
        actuelle.g = 255;
        coloradd->sensg = -1;
    }
    if (actuelle.b >= 255) {
        actuelle.b = 255;
        coloradd->sensb = -1;
    }
    if (actuelle.a >= 255) {
        actuelle.a = 255;
        coloradd->sensa = -1;
    }
    return (actuelle);
}