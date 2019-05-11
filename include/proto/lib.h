/*
** EPITECH PROJECT, 2019
** lib
** File description:
** constains all things in lib
*/

#ifndef LIB_H_
    #define LIB_H_
    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>

    int my_strlen(const char *str);
    void my_putstr(char *str);
    int getnbr(char *buff);
    int my_strcountchar(char *str, char to_count);
    int my_put_nbr(long long nb);
    char *my_strdup(char const *src);
    char *inttochar(int nblist);
    char *str_append(char *add, char *to_add, int free_first, int free_second);
    sfVector2f create_vect(float x, float y);
    int is_nbr(char *str);
    float get_floatnbr(char *str);
    sfColor create_color(int red, int blue, int green, int alpha);
    sfIntRect create_rect(int top, int left, int width, int height);
    sfFloatRect create_frect(float top, float left, float width, float height);
    char **seperate(char *str, char del);
#endif
