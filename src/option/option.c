/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** option
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void init_button(rpg_t *rpg, scene_t *scene, int *back)
{
    button_t *but;

    button_find(scene->list_but, 900)->to_send_click = (void *) back;
    button_find(scene->list_but, 901)->to_send_click = (void *) rpg;
    but = button_find(scene->list_but, 1011);
    but->to_send_click = (void *) scene;
    but->to_send_click2 = (void *) rpg;
    but = button_find(scene->list_but, 1010);
    but->to_send_click = (void *) scene;
    but->to_send_click2 = (void *) rpg;
}

void init_option(rpg_t *rpg, scene_t *scene, int *back)
{
    volume_bar_t *vol;
    text_t *text;

    vol = ((volume_bar_t *) (other_find(scene->other, 201)->other));
    volume_bar_set_value(vol, rpg->option->music_volume);
    text = text_find(scene->list_text, 101);
    text->str = inttochar(vol->volume);
    sfText_setString(text->text, text->str);
    vol = ((volume_bar_t *) (other_find(scene->other, 202)->other));
    volume_bar_set_value(vol, rpg->option->sound_volume);
    text = text_find(scene->list_text, 102);
    text->str = inttochar(vol->volume);
    sfText_setString(text->text, text->str);
    set_value_frame_rate(rpg, scene);
    init_button(rpg, scene, back);
}

void change_value(scene_t *scene, other_t *other)
{
    text_t *text = text_find(scene->list_text, other->id - 100);
    volume_bar_t *vol = ((volume_bar_t *) (other->other));

    if (text->str != NULL)
        free(text->str);
    text->str = inttochar(vol->volume);
    sfText_setString(text->text, text->str);
}

void option_do(scene_t *scene)
{
    other_t *vol = NULL;

    vol = other_find(scene->other, 201);
    if (((volume_bar_t *) (vol->other))->onclick == sfTrue)
        change_value(scene, vol);
    vol = other_find(scene->other, 202);
    if (((volume_bar_t *) (vol->other))->onclick == sfTrue)
        change_value(scene, vol);
}

void option(rpg_t *rpg)
{
    scene_t *scene_inventory = load_scene(rpg->assets->tab_scene[2], NULL);
    int back = 0;

    if (scene_inventory == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window))
        init_option(rpg, scene_inventory, &back);
    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_for_button(rpg->event, scene_inventory, rpg->window);
            if (rpg->event.type == sfEvtTextEntered)
                text_bar_write(rpg->event, scene_inventory);
            event_on_window(rpg);
        }
        option_do(scene_inventory);
        sfRenderWindow_clear(rpg->window, sfBlack);
        display_list_display(rpg->window, scene_inventory->order);
        sfRenderWindow_display(rpg->window);
    }
    free_scene(scene_inventory);
}