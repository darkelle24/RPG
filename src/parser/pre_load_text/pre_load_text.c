/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** pre_load_text
*/

#include <SFML/Graphics.h>
#include <unistd.h>
#include <stdio.h>
#include "struct/texture_load.h"
#include "proto/lib.h"
#include "proto/proto.h"

sfTexture *find_texture(texture_list_t *list, int id_to_find)
{
    while (list != NULL && list->id != id_to_find)
        list = list->next;
    if (list == NULL)
        return (NULL);
    else
        return (list->texture);
}

void write_error_path_text(char *path)
{
    write(2, "Problem with open texture : ", 26);
    write(2, path, my_strlen(path));
    write(2, "\n", 1);
}

texture_list_t *add_texture(texture_list_t **list, int id, sfTexture *texture)
{
    texture_list_t *new = malloc(sizeof(texture_list_t));
    texture_list_t *save = *list;

    while (*list && (*list)->next != NULL)
        *list = (*list)->next;
    new->next = NULL;
    new->texture = texture;
    new->id = id;
    if (*list == NULL)
        *list = new;
    else {
        (*list)->next = new;
        *list = save;
    }
    return (new);
}

texture_list_t *recup_texture(texture_list_t *list, char *str)
{
    char *path = path_recup(str);
    sfIntRect rect = rect_recup(str);
    int id = find_nbr(str, "ID=");
    sfTexture *texture = sfTexture_createFromFile(path, &rect);

    add_texture(&list, id, texture);
    return (list);
}

texture_list_t *load_texture(char *path)
{
    FILE *fp = fopen(path, "r");
    char *buff = NULL;
    size_t len = 0;
    texture_list_t *list = malloc(sizeof(texture_list_t));

    if (fp == NULL) {
        write_error_path_text(path);
        return (NULL);
    }
    list = NULL;
    while (getline(&buff, &len, fp) != -1) {
        if (buff[0] != '#')
            list = recup_texture(list, buff);
        free(buff);
        buff = NULL;
    }
    fclose(fp);
    return (list);
}