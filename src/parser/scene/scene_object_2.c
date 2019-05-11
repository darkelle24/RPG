/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** scene_objet_2
*/

#include <SFML/Graphics/Rect.h>
#include <SFML/System/Vector2.h>
#include <stdlib.h>
#include "proto/lib.h"

int my_strlenchar(char *str, char arrest)
{
    int i = 0;

    while (str[i] != arrest && str[i] != '\0')
        i++;
    return (i);
}

char *recup_str(char *phrase, int n, char arrest)
{
    int i = my_strlenchar(&phrase[n + 1], arrest);
    char *str_return = malloc(sizeof(char) * (i + 1));
    int a = 0;

    if (str_return == NULL)
        return (NULL);
    while (a != i) {
        str_return[a] = phrase[n + 1 + a];
        a++;
    }
    str_return[a] = '\0';
    return (str_return);
}

sfVector2f recup_pos(char *phrase, int pos)
{
    char *pos_strx = recup_str(phrase, pos, ',');
    char *pos_stry = recup_str(phrase
    , pos + my_strlenchar(pos_strx, '\0') + 1, ')');
    sfVector2f to_return = create_vect(getnbr(pos_strx), getnbr(pos_stry));

    free(pos_strx);
    free(pos_stry);
    return (to_return);
}

sfIntRect recup_rect(char *phrase, int pos)
{
    char *strx = recup_str(phrase, pos, ',');
    char *stry = recup_str(phrase
    , pos + my_strlenchar(strx, '\0') + 1, ',');
    char *strwidth = recup_str(phrase
    , pos + my_strlenchar(strx, '\0')
    + my_strlenchar(stry, '\0') + 2, ',');
    char *strheight = recup_str(phrase
    , pos + my_strlenchar(strx, '\0')
    + my_strlenchar(stry, '\0') + my_strlenchar(strwidth, '\0') + 3, ')');
    sfIntRect rect = create_rect(getnbr(strx), getnbr(stry)
    , getnbr(strwidth), getnbr(strheight));

    free(strx);
    free(stry);
    free(strwidth);
    free(strheight);
    return (rect);
}