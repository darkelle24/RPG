/*
** EPITECH PROJECT, 2019
** game_struct.h
** File description:
** contains principal informations
*/

#ifndef GAME_STRUCT_H_
    #define GAME_STRUCT_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #include "struct/option.h"
    #include "struct/competence.h"
    #include "struct/ennemy.h"
    #include "struct/texture_load.h"

    typedef struct player_s player_t;

    typedef struct s_game_object
    {
        char *tab_scene[10];
        texture_list_t *tab_text[10];
    } game_assets_t;

    typedef struct s_rpg {
        sfMusic *music_neon;
        game_assets_t *assets;
        sfRenderWindow *window;
        sfVideoMode video_mode;
        sfEvent event;
        option_t *option;
        sfClock *game;
        player_t *player;
        int mob_kill;
        ennemy_t *ennemi_list;
    } rpg_t;


#endif /* !GAME_STRUCT_H_ */
