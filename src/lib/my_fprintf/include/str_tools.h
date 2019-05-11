/*
** EPITECH PROJECT, 2019
** C lib
** File description:
** my_fprintf header
*/

#ifndef STR_TOOLS_H_
    #define STR_TOOLS_H_

    #include <unistd.h>

ssize_t my_strlen_lilian(char const *str, char c);
char *my_strdup_lilian(char const *str);
ssize_t my_charcomp(const char ch, char *str);
void my_strncpy(const char *source, char *dest, ssize_t n);
char *my_itoa(int nbr);
#endif /* !STR_TOOLS_H */
