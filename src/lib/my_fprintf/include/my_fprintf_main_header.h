/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** my_fprintf header
*/

#ifndef CHAINED_LIST_TOOLS_H_
    #define CHAINED_LIST_TOOLS_H_

    #include <unistd.h>

    typedef struct buffer_list_s buffer_list_t;
    typedef struct chained_list_s chained_list_t;

    struct chained_list_s {
        char *str;
        ssize_t len;
        chained_list_t *next;
    };

    struct buffer_list_s {
        chained_list_t *list;
        size_t nbr_chain;
    };

    int add_start_chain(buffer_list_t *s_list, char *str);
    int add_last_chain(buffer_list_t *s_list, char *str);
    buffer_list_t *create_saved_list(void);
    void display_chained_list(buffer_list_t *s_list, char *delim);
    int supr_save_list(buffer_list_t **s_list);
    int add_arg_buffer(buffer_list_t *buffers, va_list va, const char *ch);

#endif /* !CHAINED_LIST_TOOLS_H */
