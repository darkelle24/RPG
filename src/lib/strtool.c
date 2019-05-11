/*
** EPITECH PROJECT, 2018
** strtool
** File description:
** is normal
*/

#include <unistd.h>

int my_strlen(const char *str)
{
    int len = 0;

    while (str[len] != '\n' && str[len] != '\0') {
        len++;
    }
    return (len);
}

void my_putstr(char *str)
{
    int co = 0;

    while (str[co] != '\0') {
        write(1, &str[co], 1);
        co++;
    }
}

int getnbr(char *buff)
{
    int co = 0;
    int neg = 1;
    int nbr = 0;

    while (!(buff[co] >= '0' && buff[co] <= '9')) {
        ++co;
    }
    if (co != 0 && buff[co - 1] == '-') {
        neg = -1;
    }
    while (buff[co] >= '0' && buff[co] <= '9') {
        nbr = (nbr * 10) + buff[co] - '0';
        ++co;
    }
    return (neg * nbr);
}

int my_put_nbr(long long nb)
{
    int mb = 0;

    if (nb < 0) {
        nb = nb * -1;
        write(1, "-" , 1);
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
    }
    mb = nb % 10 + '0';
    write(1, &mb , 1);
    return (0);
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    if (!src)
        return (dest);
    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}