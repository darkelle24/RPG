/*
** EPITECH PROJECT, 2019
** C_lib
** File description:
** my_frpintf || my strtools
*/

#include <stdio.h>
#include <malloc.h>
#include "proto/lib.h"

ssize_t my_strlen_lilian(char const *str, char c)
{
    ssize_t i = 0;

    if (!str)
        return (-1);
    while (str[i] != '\0' && str[i] != c)
        ++i;
    return (i);
}

char *my_strdup_lilian(char const *str)
{
    char *strduped = malloc(sizeof(char) * (my_strlen_lilian(str, '\0') + 1));
    size_t i = 0;

    if (!str || strduped == NULL)
    {
        free(strduped);
        return (NULL);
    }
    while (str && str[i] != '\0')
    {
        strduped[i] = str[i];
        ++i;
    }
    strduped[i] = '\0';
    return (strduped);
}

ssize_t my_charcomp(const char ch, char *str)
{
    size_t i = 0;

    while (str[i] != '\0')
    {
        if (ch == str[i])
            return (i);
        ++i;
    }
    return (-1);
}

void my_strncpy(const char *source, char *dest, ssize_t n)
{
    ssize_t i = 0;

    if (n != -1)
    {
        while (i != n)
        {
            dest[i] = source[i];
            ++i;
        }
    }
}
