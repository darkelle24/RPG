/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** create_perso
*/

#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/player.h"

void set_text(scene_t *scene, int id, char *value)
{
    text_t *text = text_find(scene->list_text, id);

    free(text->str);
    text->str = value;
    sfText_setString(text->text, text->str);
}

void recup_compt(rpg_t *rpg, char *path)
{
    FILE *fp = fopen(path, "r");
    char *buff = NULL;
    size_t size = 0;

    getline(&buff, &size, fp);
    rpg->player->base = analyse_competence(buff);
    buff = NULL;
    getline(&buff, &size, fp);
    rpg->player->comp_1 = analyse_competence(buff);
    buff = NULL;
    getline(&buff, &size, fp);
    rpg->player->comp_2 = analyse_competence(buff);
    buff = NULL;
    getline(&buff, &size, fp);
    rpg->player->comp_3 = analyse_competence(buff);
    buff = NULL;
    fclose(fp);
}

void inti_player(rpg_t *rpg)
{
    rpg->player = malloc(sizeof(player_t));
    rpg->player->lvl = 1;
    rpg->player->xp = 0;
    rpg->player->point = 0;
    rpg->player->inventory = NULL;
    rpg->player->base = NULL;
    rpg->player->comp_1 = NULL;
    rpg->player->comp_2 = NULL;
    rpg->player->comp_3 = NULL;
    rpg->player->name = NULL;
    rpg->player->stat = NULL;
}

void create_perso_init(rpg_t *rpg, scene_t *scene, int *back)
{
    button_find(scene->list_but, 901)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 2100)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 2100)->to_send_click2 = (void *) scene;
    button_find(scene->list_but, 2101)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 2101)->to_send_click2 = (void *) scene;
    button_find(scene->list_but, 2102)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 2102)->to_send_click2 = (void *) scene;
    button_find(scene->list_but, 1051)->to_send_click = (void *) rpg;
    button_find(scene->list_but, 1051)->to_send_click2 = (void *) scene;
    button_find(scene->list_but, 1051)->to_send_click3 = (void *) back;
    hacker_init(scene);
}

void create_perso(rpg_t *rpg)
{
    scene_t *scene = load_scene("src/parser/scene_files/create_perso.dji"
    , NULL);
    int back = 0;

    if (scene == NULL)
        sfRenderWindow_close(rpg->window);
    else if (sfRenderWindow_isOpen(rpg->window))
        create_perso_init(rpg, scene, &back);
    while (sfRenderWindow_isOpen(rpg->window) && back == 0) {
        while (sfRenderWindow_pollEvent(rpg->window, &rpg->event)) {
            event_for_button(rpg->event, scene, rpg->window);
            event_on_window(rpg);
            if (rpg->event.type == sfEvtTextEntered)
                text_bar_write(rpg->event, scene);
        }
        sfRenderWindow_clear(rpg->window, sfBlack);
        display_list_display(rpg->window, scene->order);
        sfRenderWindow_display(rpg->window);
    }
    free_scene(scene);
}