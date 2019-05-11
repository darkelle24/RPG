/*
** EPITECH PROJECT, 2019
** texture_loader
** File description:
** texture_loader
*/

#include "struct/scene.h"
#include "proto/proto.h"
#include "proto/parser.h"

void texture_loader(rpg_t *rpg)
{
    rpg->assets->tab_text[0] = load_texture("src/parser/tex_files/menu.txt");
    rpg->assets->tab_text[1] = load_texture("assets/map/tiles");
    rpg->assets->tab_text[2] = 
    load_texture("src/parser/tex_files/competences.txt");
    rpg->assets->tab_text[3] = load_texture
    ("src/parser/tex_files/cinematic.txt");
    rpg->assets->tab_text[4] = load_texture("src/parser/tex_files/item.txt");
    rpg->assets->tab_text[5] = NULL;
    rpg->assets->tab_text[6] = NULL;
    rpg->assets->tab_text[7] = NULL;
    rpg->assets->tab_text[8] = NULL;
    rpg->assets->tab_text[9] = NULL;
}