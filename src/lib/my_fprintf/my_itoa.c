/*
** EPITECH PROJECT, 2019
** lib
** File description:
** my_revatoi
*/

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static char *my_revnbr(char *str, size_t size)
{
    size_t e = 0;
    char *revstr = malloc(sizeof(char) * (size + 1));
    size_t limit = 0;

    if (str[0] == '-') {
        revstr[e++] = '-';
        limit = 1;
    }
    while (size != limit) {
        revstr[e] = str[size - 1];
        ++e;
        --size;
    }
    revstr[e] = '\0';
    free(str);
    return (revstr);
}

static size_t my_intlen(int nbr)
{
    size_t x = 10;
    size_t i = 0;

    if (nbr < 0) {
        nbr = -nbr;
        ++i;
    }
    while ((size_t)nbr % x != (size_t)nbr) {
        x *= 10;
        ++i;
    }
    return (i + 1);
}

static void neg_tester(int *nbr, char **str, size_t *i)
{
    if (*nbr < 0) {
        *nbr = -*nbr;
        (*str)[*i] = '-';
        *i += 1;
    }
}

char *my_itoa(int nbr)
{
    size_t int_len = my_intlen(nbr);
    char *str = malloc(sizeof(char) * (int_len + 1));
    size_t x = 10;
    size_t i = 0;
    size_t cc = 0;

    if (str == NULL)
        return (NULL);
    str[int_len] = '\0';
    neg_tester(&nbr, &str, &i);
    while ((cc = (size_t)nbr % x) != (size_t)nbr) {
        if (cc >= 10)
            cc /= x / 10;
        str[i] = cc + '0';
        x *= 10;
        ++i;
    }
    str[i] = nbr / (x / 10) + '0';
    str = my_revnbr(str, int_len);
    return (str);
}
