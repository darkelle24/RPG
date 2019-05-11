/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** my_fprintf header
*/

#ifndef CHAIN_TOOLS_H_
    #define CHAIN_TOOLS_H_

    #include <unistd.h>
    #include "./my_fprintf_main_header.h"

    int add_last_str_chain(buffer_list_t *s_list, char *str);
    int add_last_ch_chain(buffer_list_t *s_list, char ch);
    int supr_all_elements(buffer_list_t *s_list);
#endif /* !CHAIN_TOOLS_H */
