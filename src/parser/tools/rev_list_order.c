/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** rev_list_order
*/

#include <stdlib.h>
#include "struct/scene.h"

display_order **my_rev_list_1(int end, int mid, display_order **array)
{
    int count = 0;
    display_order *tmp;

    while (count < mid) {
        tmp = array[count];
        array[count] = array[end];
        array[end] = tmp;
        end--;
        count++;
    }
    return (array);
}

display_order **my_rev_list(display_order **begin, int size)
{
    display_order **array;
    int count = 0;

    array = malloc(sizeof(display_order *) * size + 1);
    array[0] = *begin;
    while (count < size) {
        array[count + 1] = array[count]->next;
        count++;
    }
    array = my_rev_list_1(size - 1, size / 2, array);
    return (array);
}