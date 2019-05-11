/*
** EPITECH PROJECT, 2019
** C_lib
** File description:
** my_frpintf
*/

#include <stdarg.h>
#include <malloc.h>
#include "./include/str_tools.h"
#include "./include/chain_tools.h"

int add_char_buffer(buffer_list_t *buffers, va_list va)
{
    char ch = va_arg(va, int);

    add_last_ch_chain(buffers, ch);
    return (0);
}

int add_string_buffer(buffer_list_t *buffers, va_list va)
{
    char *str = va_arg(va, char *);

    add_last_str_chain(buffers, str);
    return (0);
}

int add_int_buffer(buffer_list_t *buffers, va_list va)
{
    int nbr = va_arg(va, int);
    char *nstr = my_itoa(nbr);

    if (!nstr)
        return (-1);
    add_last_str_chain(buffers, nstr);
    free(nstr);
    return (0);
}

int add_arg_buffer(buffer_list_t *buffers, va_list va, const char *ch)
{
    char *flag = "csd\0";
    int (*ptr[3])(buffer_list_t *, va_list) = {&add_char_buffer,
        &add_string_buffer, &add_int_buffer};
    ssize_t chcomp = my_charcomp(*ch, flag);

    if (chcomp == -1 || ptr[chcomp](buffers, va) == -1)
        return (-1);
    return (0);
}
