/*
** EPITECH PROJECT, 2019
** game
** File description:
** functions for playin to rpg
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "struct/particule.h"
#include "proto/proto.h"

particule_t *initialize_play_game(scene_t *scene_cine, rpg_t *rpg)
{
    int fp = open(".save", O_RDONLY);

    if (fp == -1) {
        button_invi_and_desac(button_find(scene_cine->list_but, 4));
        text_find(scene_cine->list_text, 4)->disp = 0;
        button_find(scene_cine->list_but, 4)->keyboard = 0;
    } else
        close(fp);
    game_object_find(scene_cine->list_ob, 5)->last_anim
    = sfClock_getElapsedTime(rpg->game);
    if (scene_cine == NULL) {
        sfRenderWindow_close(rpg->window);
        return (NULL);
    }
    button_find(scene_cine->list_but, 3)->to_send_click = (void *) scene_cine;
    button_find(scene_cine->list_but, 4)->to_send_click = (void *) rpg;
    button_find(scene_cine->list_but, 901)->to_send_click = (void *) rpg;
    button_find(scene_cine->list_but, 2)->to_send_click = (void *) rpg;
    button_find(scene_cine->list_but, 3)->to_send_click = (void *) rpg;
    button_find(scene_cine->list_but, 30)->to_send_click = (void *) scene_cine;
    return (init_particule(rpg));
}

void menu_gest_event(rpg_t *rpg, game_object *ob, particule_t *part
, scene_t *scene_cine)
{
    if (rpg->event.type == sfEvtMouseButtonReleased && ob->display == 0)
        start_explosion(part, create_vect(rpg->event.mouseButton.x - 3,
        rpg->event.mouseButton.y - 3));
    if (ob->display == 1 && rpg->event.type == sfEvtKeyPressed
    && rpg->event.key.code == sfKeyReturn)
        ob->display = 0;
    if (ob->display == 0)
        event_for_button(rpg->event, scene_cine, rpg->window);
    if (ob->display == 1 && scene_cine->keyboard != NULL)
        scene_cine->keyboard = NULL;
}

void music_gestion(rpg_t *rpg, scene_t *scene_cine)
{
    rpg->music_neon = scene_cine->list_music->music;
    sfMusic_setVolume(rpg->music_neon, rpg->option->music_volume);
    sfMusic_play(rpg->music_neon);
}

void menu_display(game_object *ob, scene_t *scene_cine, rpg_t *rpg
, particule_t *part)
{
    if (ob->display == 0)
        display_parallax(scene_cine, rpg);
    display_list_display(rpg->window, scene_cine->order);
    if (ob->display == 0)
        clock_systeme_particule(part, rpg);
    sfRenderWindow_display(rpg->window);
}

int play_game(rpg_t *rpg)
{
    scene_t *scene_cine = load_scene(rpg->assets->tab_scene[0],
    rpg->assets->tab_text[0]);
    particule_t *part = initialize_play_game(scene_cine, rpg);
    game_object *ob = game_object_find(scene_cine->list_ob, 30);

    music_gestion(rpg, scene_cine);
    while (sfRenderWindow_isOpen(rpg->window)) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_on_window(rpg);
            menu_gest_event(rpg, ob, part, scene_cine);
        }
        menu_display(ob, scene_cine, rpg, part);
    }
    free_scene(scene_cine);
    free_part(part);
    return (0);
}