/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** free_scene_2
*/

#include <stddef.h>
#include <stdlib.h>
#include "struct/scene.h"
#include "other/fc_for_free.h"
#include "proto/proto.h"

void other_free(other_t *list)
{
    int count = 0;
    other_t *save;

    while (list != NULL) {
        while (command_free[count] != NULL) {
            if (disp_name_free[count] == list->type) {
                command_free[count](list->other);
            }
            count++;
        }
        save = list;
        list = list->next;
        free(save);
    }
}