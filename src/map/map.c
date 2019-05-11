/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

void map_shortcut(rpg_t *rpg, scene_t *scene)
{
    if (rpg->event.type == sfEvtKeyReleased && other_find(scene->other
    , 20001)->disp == 0) {
        if (rpg->event.key.code == sfKeyI)
            button_cl_map_inventory(button_find(scene->list_but, 22000)
            , (void *) scene);
        if (rpg->event.key.code == sfKeyS)
            button_cl_map_stat(button_find(scene->list_but, 23000)
            , (void *) scene);
        if (rpg->event.key.code == sfKeyEscape) {
            if (button_find(scene->list_but, 99002)->pass == 4) {
                button_cl_map_pause(button_find(scene->list_but, 24000)
                , (void *) scene);
            } else
                button_cl_map_resume(button_find(scene->list_but, 99002),
                (void *) scene);
        }
    }
}

void free_map_real(map_t *map)
{
    entity_t *save;
    block_invi_t *save2;

    sfRenderTexture_destroy(map->map);
    sfRenderTexture_destroy(map->layer_sup);
    sfView_destroy(map->view);
    while (map->entity != NULL) {
        free(map->entity->str);
        save = map->entity;
        map->entity = map->entity->next;
        free(save);
    }
    while (map->block != NULL) {
        save2 = map->block;
        map->block = map->block->next;
        free(save2);
    }
    free(map->path);
    free(map);
}

void map_2(rpg_t *rpg, scene_t *scene, map_t *map)
{
    while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
        event_for_button(rpg->event, scene, rpg->window);
        if (rpg->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->window);
        if (rpg->event.type == sfEvtKeyReleased
        && rpg->event.key.code == sfKeyReturn)
            diag_mouse_press(rpg, map);
        map_shortcut(rpg, scene);
        event_on_window(rpg);
    }
    if (button_find(scene->list_but, 99002)->pass == 4) {
        button_find(scene->list_but, 99001)->pass = 4;
        scene->keyboard = NULL;
        if (other_find(map->scene->other, 20001)->disp == 0)
            deplacement(map, map->perso, rpg);
    }
    sfRenderWindow_clear(rpg->window, sfBlack);
    display_map(rpg->window, map);
    display_list_display(rpg->window, scene->order);
    if (map->go_to_menu == sfFalse)
        sfRenderWindow_display(rpg->window);
}

void map_game(rpg_t *rpg, char *path, sfVector2f pos)
{
    scene_t *scene = load_scene("src/parser/scene_files/hud_map.dji"
    , rpg->assets->tab_text[1]);
    map_t *map = map_init(game_object_find(scene->list_ob, 18)
    , game_object_find(scene->list_ob, 20), rpg, scene);
    int back = 0;

    if (scene == NULL || map == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window)) {
        map_scene_init(rpg, scene, map, &back);
        map_set_to_game_object(path, rpg->assets->tab_text[1]
        , map, pos);
    }
    while (sfRenderWindow_isOpen(rpg->window) && back == 0
    && map->go_to_menu == sfFalse)
        map_2(rpg, scene, map);
    free_scene(scene);
    free_map_real(map);
}