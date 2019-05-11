/*
** EPITECH PROJECT, 2019
** init_game
** File description:
** init_game
*/

#include "struct/game_struct.h"
#include "proto/proto.h"

void default_value(option_t *opt)
{
    FILE *fp = fopen(".option", "w");

    opt->fps = 60;
    opt->music_volume = 60;
    opt->sound_volume = 30;
    my_fprintf(fp, "fps=%i music=%i sound=%i ", opt->fps, opt->music_volume
    , opt->sound_volume);
    fclose(fp);
}

void recupt_opt(option_t *opt, FILE *fp)
{
    char *buff = NULL;
    size_t size = 0;

    getline(&buff, &size, fp);
    opt->fps = find_nbr(buff, "fps=");
    opt->music_volume = find_nbr(buff, "music=");
    opt->sound_volume = find_nbr(buff, "sound=");
    fclose(fp);
    free(buff);
}

option_t *init_option_game(void)
{
    FILE *fp = fopen(".option", "r");
    option_t *opt = malloc(sizeof(option_t));

    if (fp == NULL) {
        default_value(opt);
    } else
        recupt_opt(opt, fp);
    return (opt);
}

void set_up_game(rpg_t *rpg, char *str)
{
    rpg->video_mode.width = 1920;
    rpg->video_mode.height = 1080;
    rpg->video_mode.bitsPerPixel = 32;
    rpg->assets = malloc(sizeof(game_assets_t));
    if (str == NULL)
        rpg->window = sfRenderWindow_create(rpg->video_mode,
                                        "Neon Knights",
                                        sfFullscreen,
                                        NULL);
    else
        rpg->window = sfRenderWindow_create(rpg->video_mode,
                                        "Neon Knights",
                                        sfDefaultStyle,
                                        NULL);
    rpg->option = init_option_game();
    sfRenderWindow_setVerticalSyncEnabled(rpg->window, sfTrue);
    sfRenderWindow_setFramerateLimit(rpg->window, rpg->option->fps);
    scene_loader(rpg);
    texture_loader(rpg);
    rpg->mob_kill = 0;
    rpg->game = sfClock_create();
}