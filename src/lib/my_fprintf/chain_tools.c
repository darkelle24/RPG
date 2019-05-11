/*
** EPITECH PROJECT, 2019
** C_lib
** File description:
** my_frpintf || my chaintools
*/

#include <malloc.h>
#include <stdarg.h>
#include "./include/my_fprintf_main_header.h"
#include "./include/str_tools.h"

int add_last_str_chain(buffer_list_t *s_list, char *str)
{
    chained_list_t *chain = malloc(sizeof(*chain));
    chained_list_t *discover = s_list->list;

    if (!chain)
        return (-1);
    chain->str = my_strdup_lilian(str);
    if (!chain->str){
        free(chain);
        return (-1);
    }
    chain->len = my_strlen_lilian(str, '\0');
    chain->next = NULL;
    while (discover && discover->next != NULL)
        discover = discover->next;
    if (!discover)
        s_list->list = chain;
    else
        discover->next = chain;
    s_list->nbr_chain += 1;
    return (0);
}

int add_last_ch_chain(buffer_list_t *s_list, char ch)
{
    chained_list_t *chain = malloc(sizeof(*chain));
    chained_list_t *discover = s_list->list;
    char str[2] = {ch, '\0'};

    if (!chain)
        return (-1);
    chain->str = my_strdup_lilian(str);
    if (!chain->str) {
        free(chain);
        return (-1);
    }
    chain->len = 1;
    chain->next = NULL;
    while (discover && discover->next != NULL)
        discover = discover->next;
    if (!discover)
        s_list->list = chain;
    else
        discover->next = chain;
    s_list->nbr_chain += 1;
    return (0);
}

int supr_all_elements(buffer_list_t *s_list)
{
    chained_list_t *current = NULL;
    chained_list_t *next = NULL;

    if (!s_list)
        return (-1);
    current = s_list->list;
    while (current != NULL)
    {
        next = current->next;
        free(current->str);
        free(current);
        current = next;
    }
    s_list->list = NULL;
    return (0);
}
