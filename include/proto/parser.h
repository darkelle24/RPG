/*
** EPITECH PROJECT, 2019
** parser.h
** File description:
** parser.h
*/

#ifndef PARSER_H_
    #define PARSER_H_

    #include <unistd.h>
    #include "struct/particule.h"
    #include "struct/combats.h"

    sfVector2f create_vect(float x, float y);
    text_bar_t *create_text_bar(int lenght_max, sfVector2f pos
    , int sizechar, sfFont *font);
    void option(rpg_t *rpg);
    int combats_analyse_str(rpg_t *rpg, map_t *map, char *str);
    int combats(rpg_t *rpg, fight_t *fight);
    void free_entity(map_t *map);
    void map_entity(FILE *fp, map_t *map);
    void entity_trigger(map_t *map, rpg_t *rpg);
    void analyse_folder_ennemy(char *path_folder, rpg_t *rpg);
    void equipped(item_t *item, scene_t *scene, rpg_t *rpg);
    void init_item_inventory(rpg_t *rpg, scene_t *scene);
    void destroy_item(rpg_t *rpg, item_t *item, scene_t *scene);
    void text_bar_create_barre(text_bar_t *text, int size_longeur
    , sfColor color);
    void init_ath_player(fight_t *fight, scene_t *scene);
    fstat_t *get_fstat(char **ennemy);
    void test_desequipped(item_t *item, scene_t *scene, rpg_t *rpg);
    void change_nbr(item_t *item, scene_t *scene, inventory_t *list);
    void set_part(item_t *item, scene_t *scene);
    void change_effect(rpg_t *rpg, scene_t *scene);
    void init_spe_stat(rpg_t *rpg, scene_t *scene);
    void add_effect(item_t *item, player_t *player, int type);
    void map_block(FILE *fp, map_t *map);
    void volume_bar_set_value(volume_bar_t *vol, int value);
    void map_render_texture_2(sfRenderTexture *render, sfTexture *texture
    , int count, int a);
    void key_biding(rpg_t *rpg);
    void set_value_frame_rate(rpg_t *rpg, scene_t *scene);
    char *recup_str_spe(char *str, char *to_find, char end_char);
    void init_inventory(rpg_t *rpg, scene_t *scene, int *back);
    void inventory(rpg_t *rpg);
    void add_item_to_inventory(player_t *player, char *effect);
    int find_number_spe(char *str, char end, int *pos);
    void text_bar_free(void *text_void);
    void text_bar_write(sfEvent event, scene_t *scene);
    void display_text_bar(other_t *other, sfRenderWindow *window);
    other_t *other_list_add(other_t **list, void *other, char type, int id);
    void scene_text_bar(scene_t *scene, char *phrase);
    char *create_array(char *nb, int i);
    void display_map(sfRenderWindow *window, map_t *map);
    float calcul_lenght(sfVector2f pos_target, sfVector2f pos_circle);
    sfSound *sound_find(multi_sound *list_sound, int id);
    button_t *check_up(button_list_t *list, button_t *button
    , sfRenderWindow *window);
    other_t *other_find(other_t *list, int id);
    text_t *text_find(text_list_t *list, int id);
    void map_set_to_game_object(char *path, texture_list_t *list
    , map_t *map, sfVector2f pos);
    map_t *map_init(game_object *obj, game_object *perso
    , rpg_t *rpg, scene_t *scene);
    void rectangle_display(other_t *other, sfRenderWindow *window);
    void rectangle_free(void *rectangle_void);
    void scene_rectangle(scene_t *scene, char *phrase);
    void progress_bar_change_value(progress_bar_t *pro_bar, float new_value);
    void progress_bar_free(void *pro_bar_void);
    sfRenderTexture **map_create(texture_list_t *list, FILE *fp, map_t *map
    , char *path);
    void scene_progress_bar(scene_t *scene, char *phrase);
    void progress_bar_display(other_t *other, sfRenderWindow *window);
    void progress_bar_mini_bar(progress_bar_t *strct, int mini_bar
    , sfColor color, int size);
    sfTexture *find_texture(texture_list_t *list, int id_to_find);
    button_t *check_down(button_list_t *list, button_t *button
    , sfRenderWindow *window);
    void volume_bar_free(void *vol_bar_void);
    void diag_mouse_press(rpg_t *rpg, map_t *map);
    text_list_t *create_text_list();
    void free_text_list(texture_list_t *list);
    void button_list_is_hover(scene_t *scene, button_list_t *button_list
    , sfRenderWindow *window);
    void other_free(other_t *list);
    progress_bar_t *progress_bar_init(sfVector2f pos
    , sfVector2f size, int pourc);
    void button_move_with_button(sfEvent event, scene_t *scene
    , sfRenderWindow *window);
    void scene_volume_bar(scene_t *scene, char *phrase);
    volume_bar_t *volume_bar_init(sfVector2f pos, sfVector2f size, int volume);
    void volume_bar_active(volume_bar_t *vol_bar, sfRenderWindow *window);
    int text_list_add(text_list_t *list, text_t *text);
    char *str_recup(char *phrase, char *to_find);
    int my_put_nbr(long long nb);
    void text_init(text_t *text, sfVector2f position, int disp, int id);
    int my_strlenchar(char *str, char arrest);
    void display_list_text(sfRenderWindow *window, text_list_t *list);
    void button_init(button_t *button, sfVector2f position
    , sfVector2f size, int id);
    void button_desactivate(button_t *button, sfColor color);
    void button_activate(button_t *button, sfColor color);
    void button_invisible(button_t *button);
    void button_invi_and_desac(button_t *button);
    void button_set_status(button_t *button, int pass, sfColor color);
    void button_set_callback_on_click(button_t *button
    , void (*to_callback)(button_t *, void *), void *a_envoyer);
    int button_is_clicked(button_t *button, sfVector2f click_position);
    void destroy_object(game_object *obj, int nb, sfTexture **texture);
    void sprite_rotate(sfSprite *to_rotate, sfVector2f pos
    , float angle_of_start);
    void button_list_is_clicked(button_list_t *button_list
    , sfRenderWindow *window);
    button_list_t *create_button_list();
    void button_list_free(button_list_t *list);
    void button_free(button_t *button);
    int button_list_add(button_list_t *list, button_t *button);
    void button_set_outline(button_t *button, float thickness, sfColor color);
    void button_list_draw(sfRenderWindow *window, button_list_t *list);
    sfColor degrade_color(colordegrade *coloradd, sfColor actuelle
    , sfText *text);
    int find_nbr(char *str, char *to_find);
    char *recup_str(char *phrase, int n, char arrest);
    sfVector2f recup_pos(char *phrase, int pos);
    game_object *game_object_copy(game_object *to_copy, int display);
    int button_list_remove(button_list_t *list, button_t *button, int nbr);
    game_object *create_object(const char *path_to_spritesheet,
    sfVector2f pos, sfIntRect rect, int type);
    sfIntRect create_rect(int top, int left, int width, int height);
    sfRenderWindow *create_windows(int width, int height, int bit, char *title);
    sfColor degrade_color_basse(colordegrade *coloradd, sfColor actuelle);
    sfColor degrade_color_haute(colordegrade *coloradd, sfColor actuelle);
    sfColor create_color(int r, int b, int g, int a);
    sfFloatRect create_frect(float top, float left, float width, float height);
    void sprite_rotate(sfSprite *to_rotate, sfVector2f pos
    , float angle_of_start);
    texture_list_t *load_texture(char *path);
    sfIntRect rect_recup(char *phrase);
    sfRectangleShape *create_rectangle(sfVector2f pos
    , sfVector2f size, sfColor col);
    sfCircleShape *create_circle(sfVector2f pos, float radius
    , float outline_thickness, sfColor color_outline);
    game_list *create_game_list();
    void scene_font(scene_t *scene, char *phrase);
    int strfind(char const *str, char const *to_find);
    void scene_object(scene_t *scene, char *phrase);
    void scene_music(scene_t *scene, char *phrase);
    void scene_button(scene_t *scene, char *phrase);
    void scene_text(scene_t *scene, char *phrase);
    scene_t *load_scene(char *path, texture_list_t *list);
    void scene_loader(rpg_t *rpg);
    game_object *game_object_find(game_list *list_ob, int id);
    button_t *button_find(button_list_t *list, int id);
    int game_list_add(game_list *list, game_object *object);
    sfColor recup_color(char *phrase, int pos);
    char *path_recup(char *phrase);
    multi_music *create_music_list();
    void event_for_button(sfEvent event, scene_t *scene
    , sfRenderWindow *window);
    int music_list_add(multi_music *list, sfMusic *music, int id);
    void display_list_add_button(display_order **list
    , button_t *button, int prio);
    void display_list_add_object(display_order **list
    , game_object *object, int prio);
    void display_list_add_text(display_order **list, text_t *text, int prio);
    void button_desactivate(button_t *button, sfColor color);
    void button_activate(button_t *button, sfColor color);
    display_order *create_display_list();
    void volume_bar_display(other_t *other, sfRenderWindow *window);
    display_order **my_rev_list(display_order **begin, int size);
    void display_list_display(sfRenderWindow *window, display_order *list);
    void game_list_free(game_list *list);
    void music_list_free(multi_music *list);
    void free_scene(scene_t *scene);
    void button_list_is_pressed(button_list_t *button_list
    , sfRenderWindow *window);
    void desactive_all_mode(button_list_t *list);
    void display_list_free(display_order *list);
    int button_list_remove_with_number(button_list_t *list, int number);
    int button_list_remove_with_button(button_list_t *list, button_t *button);
    sfIntRect recup_rect(char *phrase, int pos);
    multi_sound *create_sound_list();
    int sound_list_add(multi_sound *list, sfSound *sound
    , sfSoundBuffer *buffer, int id);
    competence_t *analyse_competence(char *str);
    void scene_sound(scene_t *scene, char *phrase);
    void sound_list_free(multi_sound *list);
    void remove_display_object(display_order *list, game_object *object);
    void game_list_remove(game_list *list, game_object *object);
    sfColor color_recup(char *phrase, char *to_find);
    void display_list_add_other(display_order **list, other_t *other, int prio);
    sfVector2f pos_object_recup_str(char *phrase, char *to_find);
    void deplacement(map_t *map, game_object *obj, rpg_t *rpg);
    void free_block(map_t *map);
    void texture_loader(rpg_t *rpg);
    void init_ath_ennemy(fight_t *fight, scene_t *scene);
    void init_ath_player(fight_t *fight, scene_t *scene);
    void set_compt_active(fight_t *fight, scene_t *scene
    , competence_t *compt, int nbr);
    void refresh_other_info(fight_t *fight, scene_t *scene);
    void button_cl_combat_but_compt(button_t *but, void *fight_void);
    void goto_inventory(button_t *but, void *rpg_void);
    void button_cl_combat_but_turn(button_t *but, void *fight_void);
    void set_text_mid(sfText *text, sfFloatRect rect);
    void ennemy_turn(fight_t *fight, scene_t *scene);
    int calcul_flag(fight_t *fight, char *effect, int target);
    void button_cl_combat_but_flee(button_t *but, void *fight_void);
    void map_game(rpg_t *rpg, char *path, sfVector2f pos);
    void set_speed_ennemy(fight_t *fight, scene_t *scene);
    void set_speed_player(fight_t *fight, scene_t *scene);
    void stat_display(rpg_t *rpg);
    void set_one_stat(scene_t *scene, int valeur, int nbr);
    void map_init_all_value(rpg_t *rpg, scene_t *scene);
    void button_cl_map_inventory(button_t *but, void *scene_void);
    void button_cl_map_stat(button_t *but, void *scene_void);
    void button_cl_map_option(button_t *but, void *rpg_void);
    void reward_menu(rpg_t *rpg, fight_t *fight);
    void change_map(rpg_t *rpg, map_t *map, char *str);
    void combats_analyse_str_call(rpg_t *rpg, map_t *map, char *str);
    void dialogue_init(rpg_t *rpg, map_t *map, char *str);
    void door_of_boss(rpg_t *rpg, map_t *map, char *str);
    void create_perso(rpg_t *rpg);
    void cyborgs_init(scene_t *scene);
    void corsair_init(scene_t *scene);
    void hacker_init(scene_t *scene);
    void inti_player(rpg_t *rpg);
    void hacker_save(scene_t *scene, rpg_t *rpg);
    void corsair_save(scene_t *scene, rpg_t *rpg);
    void cyborgs_save(scene_t *scene, rpg_t *rpg);
    void button_cl_item(button_t *button, void *item_void);
    void destroy_item_fc(button_t *button, void *item_void);
    void desequipped(item_t *item, scene_t *scene, rpg_t *rpg);
    ssize_t my_fprintf(FILE *stream, const char *str, ...);
    void button_cl_map_pause(button_t *but, void *scene_void);
    void button_cl_map_resume(button_t *but, void *scene_void);
    void load_player(rpg_t *rpg);
    void deplacement_test(map_t *map, rpg_t *rpg);
    void free_player(rpg_t *rpg);
    void free_compt(competence_t *compt);
    entity_t *create_entity(char *str);
    void link_fc(char *str, entity_t *new);
    void recup_name(map_t *map, char *buff, rpg_t *rpg);
    void credit(rpg_t *rpg);
    void boss(rpg_t *rpg, map_t *map, char *str);

#endif /* !PARSER_H_ */
