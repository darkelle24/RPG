/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** proto.h
*/

#ifndef PROTO_H_
    #define PROTO_H_

    #include <SFML/System/Vector2.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Color.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include "struct/map.h"
    #include "struct/button.h"
    #include "struct/color.h"
    #include "struct/game_object.h"
    #include "struct/game_struct.h"
    #include "struct/music_sound.h"
    #include "struct/scene.h"
    #include "struct/progress_bar.h"
    #include "struct/text.h"
    #include "struct/volume_bar.h"
    #include "struct/geo_form.h"
    #include "struct/text_bar.h"
    #include "struct/texture_load.h"
    #include "struct/player.h"
    #include "struct/inventory.h"

    #include "parser.h"

    // ------- GAME --------- //
    int play_rpg(char *str);
    int play_game(rpg_t *rpg);
    void set_up_game(rpg_t *rpg, char *str);
    void end_game(rpg_t *rpg);
    void event_on_window(rpg_t *rpg);

    // ------- MENU --------- //
    void display_parallax(scene_t *scene_cine, rpg_t *rpg);

    // ------ CINEMATIC ----- //
    void cinematic(rpg_t *rpg);

    // ------- MOVE -------- //
    void move_up(map_t *map, game_object *obj, rpg_t *rpg);
    void move_left(map_t *map, game_object *obj, rpg_t *rpg);
    void move_right(map_t *map, game_object *obj, rpg_t *rpg);
    void move_down(map_t *map, game_object *obj, rpg_t *rpg);

    // ------- MAP -------- //
    sfBool test_block(map_t *map, game_object *obj,
    sfVector2f pos_add);

    // ------ PERSO ------ //
    void recup_compt(rpg_t *rpg, char *path);
    void set_text(scene_t *scene, int id, char *value);

    // ---- PARTICULE ---- //
    void system_particule(particule_t *part);
    void system_particule_2(particule_t *part);
    particule_t *init_particule(rpg_t *rpg);
    void start_explosion(particule_t *part, sfVector2f pos);
    void clock_systeme_particule(particule_t *part, rpg_t *rpg);
    void free_part(particule_t *part);

    // ----- COMBAT ----- //
    void combat_init(rpg_t *rpg, scene_t *scene, int *back, fight_t *fight);
    void set_speed(fight_t *fight, scene_t *scene);
    ennemy_t *find_ennemy(ennemy_t *list, int id);
    stat_t *init_stat_ennemy(ennemy_t *ennemy, int lvl);
    void init_ath_info(fight_t *fight, scene_t *scene);
    void init_compt(fight_t *fight, scene_t * scene,
                    competence_t *compt, int nbr);
    void set_sound(scene_t *scene, rpg_t *rpg);

    // --- ENNEMY IA --- //
    int test_is_okay_compt(fight_t *fight, competence_t *compt,
    int nbr);
    int ennemy_choose_compt(int valid_compt[4]);
    competence_t *link_compt(fight_t *fight, int compt_choose);

    // ----- STAT ----- //
    void activated_but(scene_t *scene);

    // -- BUTTON STAT -- //
    void desactivated_but(scene_t *scene);

    // - BUTTON COMBAT - //
    int calcul_damage_ap_player(fight_t *fight, competence_t *compt);
    int calcul_damage_ad_player(fight_t *fight, competence_t *compt);
    int calcul_heal_player(fight_t *fight, competence_t *compt);
    void disp_damage(scene_t *scene, fight_t *fight, competence_t *compt);

    // -- MAP TOOLS -- //
    int find_number_spe(char *str, char end, int *pos);
    char **generate_map(char **map, int size_map, FILE *fp);
    void free_map(int all, char **map);

    // -- DIALOGUE -- //
    void exit_dial(map_t *map);

    // --- REWARD --- //
    void reward_init(rpg_t *rpg, scene_t *scene, fight_t *fight, int *back);
    void reward_init_2(rpg_t *rpg, scene_t *scene, fight_t *fight);
    void reward_init_3(rpg_t *rpg, scene_t *scene, fight_t *fight);
    void reward_item_4(int count, scene_t *scene);
    int set_text_int(scene_t *scene, int id_text, int valeur);
    int calcul(scene_t *scene, rpg_t *rpg, fight_t *fight);

    // - INIT MAP - //
    void map_scene_init(rpg_t *rpg, scene_t *scene, map_t *map, int *back);

    // - INIT INVENTORY - //
    void init_item_inventory(rpg_t *rpg, scene_t *scene);
    void init_item_inventory_2(inventory_t *list, scene_t *scene
    , int i, rpg_t *rpg);

#endif /* !PROTO_H_ */
