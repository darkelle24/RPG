/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** map_loader
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"

sfRenderTexture *map_render_texture(char **map, texture_list_t *list
, sfRenderTexture *render, int size)
{
    int count = 0;
    int pos = 0;
    int a = 0;
    int nbr = 0;
    sfTexture *texture;

    while (map[a] != NULL){
        count = 0;
        pos = -1;
        while (count != size) {
            nbr = find_number_spe(map[a], ';', &pos);
            if (nbr != 0 && (texture = find_texture(list, nbr)) != NULL) {
                map_render_texture_2(render, texture, count, a);
            } else if (nbr != 0 && texture == NULL)
                write(2, "Problem texture don't exist\n", 28);
            count++;
        }
        a++;
    }
    return (render);
}

sfRenderTexture **map_create_2(char **map, int size_map, FILE *fp
, texture_list_t *list)
{
    int width;
    sfRenderTexture **render = malloc(sizeof(sfRenderTexture *) * 2);
    char *buff = NULL;
    size_t size = 0;

    map = generate_map(map, size_map, fp);
    width = my_strcountchar(map[0], ';');
    render[0] = sfRenderTexture_create(width * 64, size_map * 64, sfFalse);
    render[1] = sfRenderTexture_create(width * 64, size_map * 64, sfFalse);
    sfRenderTexture_clear(render[0], sfTransparent);
    sfRenderTexture_clear(render[1], sfTransparent);
    map_render_texture(map, list, render[0], width);
    getline(&buff, &size, fp);
    map = generate_map(map, size_map, fp);
    map_render_texture(map, list, render[0], width);
    getline(&buff, &size, fp);
    map = generate_map(map, size_map, fp);
    map_render_texture(map, list, render[1], width);
    free_map(1, map);
    return (render);
}

sfRenderTexture **map_create(texture_list_t *list, FILE *fp, map_t *map_recup
, char *path)
{
    char *buff = NULL;
    size_t size = 0;
    int size_map = 0;
    char **map = NULL;

    getline(&buff, &size, fp);
    size_map = getnbr(buff);
    free(buff);
    map = malloc(sizeof(char *) * (size_map + 1));
    map[size_map] = NULL;
    map_recup->path = my_strdup(path);
    return (map_create_2(map, size_map, fp, list));
}