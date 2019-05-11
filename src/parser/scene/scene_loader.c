/*
** EPITECH PROJECT, 2019
** scene_loader
** File description:
** scene_loader
*/

#include "struct/scene.h"
#include "proto/proto.h"

void scene_loader(rpg_t *rpg)
{
    rpg->assets->tab_scene[0] = "src/parser/scene_files/menu.dji";
    rpg->assets->tab_scene[1] = "src/parser/scene_files/scene_inventory.dji";
    rpg->assets->tab_scene[2] = "src/parser/scene_files/scene_option.dji";
    rpg->assets->tab_scene[3] = "src/parser/scene_files/key_biding.dji";
    rpg->assets->tab_scene[4] = "src/parser/scene_files/cinematic.dji";
    rpg->assets->tab_scene[5] = NULL;
    rpg->assets->tab_scene[6] = NULL;
    rpg->assets->tab_scene[7] = NULL;
    rpg->assets->tab_scene[8] = NULL;
    rpg->assets->tab_scene[9] = NULL;
}