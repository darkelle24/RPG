/*
** EPITECH PROJECT, 2019
** map_tools
** File description:
** functions tools for free or generate map, and parsing files
*/

#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#include "proto/proto.h"
#include "proto/lib.h"
#include "struct/map.h"

int find_number_spe(char *str, char end, int *pos)
{
    int nbr = 0;
    char *temp;

    temp = recup_str(str, *pos, end);
    *pos += my_strlen(temp) + 1;
    nbr = getnbr(temp);
    free (temp);
    return (nbr);
}

char **generate_map(char **map, int size_map, FILE *fp)
{
    int i = 0;
    size_t size = 0;
    char *buff = NULL;

    while (i != size_map) {
        buff = NULL;
        size = 0;
        getline(&buff, &size, fp);
        map[i] = buff;
        i++;
    }
    return (map);
}

void free_map(int all, char **map)
{
    int i = 0;

    while (map[i] != NULL) {
        free(map[i]);
        i++;
    }
    if (all == 1)
        free(map);
}