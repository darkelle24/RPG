/*
** EPITECH PROJECT, 2019
** MUL_my_RPG_2018
** File description:
** fc_for_button
*/

#ifndef FC_FOR_BUTTON_H_
    #define FC_FOR_BUTTON_H_
    #include <stddef.h>
    #include "struct/button.h"
    #include "proto/proto.h"

    void button_cl_return(button_t *button, void *back_void);
    void button_cl_quit(button_t *button, void *rpg_void);
    void button_hv_return(button_t *button, void *back_void);
    void button_hv_quit(button_t *button, void *rpg_void);
    void button_hvex_return(button_t *button, void *back_void);
    void button_hvex_quit(button_t *button, void *rpg_void);
    void button_pr_return(button_t *button, void *back_void);
    void button_pr_quit(button_t *button, void *rpg_void);
    void button_hv_item(button_t *button, void *unused);
    void button_hvex_item(button_t *button, void *unused);
    void button_pr_item(button_t *button, void *unused);
    void button_cl_item(button_t *button, void *item_void);
    void button_cl_inventory_trash(button_t *but, void *scene_void);
    void button_ho_inventory_trash(button_t *but, void *scene_void);
    void button_pr_inventory_trash(button_t *but, void *scene_void);
    void button_hoex_inventory_trash(button_t *but, void *scene_void);
    void button_cl_save_opt(button_t *button, void *scene_void);
    void button_pr_save_opt(button_t *button, void *scene_void);
    void button_hvex_save_opt(button_t *button, void *scene_void);
    void button_hv_save_opt(button_t *button, void *scene_void);
    void button_rl_key_opt(button_t *button, void *scene_void);

    void button_cl_menu_option(button_t *but, void *rpg_void);
    void button_cl_menu_new_game(button_t *but, void *rpg_void);
    void button_cl_menu_continue(button_t *but, void *rpg_void);
    void button_pr_menu_option(button_t *but, void *rpg_void);
    void button_hv_menu_option(button_t *but, void *rpg_void);
    void button_hvex_menu_option(button_t *but, void *rpg_void);
    void button_cl_menu_howtoplay(button_t *but, void *scene_null);

    void button_hv_combat_but_aux(button_t *but, void *useless);
    void button_hvex_combat_but_aux(button_t *but, void *useless);
    void button_pr_combat_but_aux(button_t *but, void *useless);
    void button_hv_combat_but_compt(button_t *but, void *useless);
    void button_hvex_combat_but_compt(button_t *but, void *useless);
    void button_pr_combat_but_compt(button_t *but, void *useless);
    void button_cl_combat_but_compt(button_t *but, void *fight_void);
    void button_cl_combat_but_turn(button_t *but, void *fight_void);
    void button_cl_combat_but_flee(button_t *but, void *fight_void);

    void goto_inventory(button_t *but, void *rpg_void);

    void but_fc_cl_stat(button_t *but, void *scene_void);
    void but_fc_hv_stat(button_t *but, void *scene_void);
    void but_fc_pr_stat(button_t *but, void *scene_void);
    void but_fc_hvex_stat(button_t *but, void *scene_void);

    void button_cl_map_inventory(button_t *but, void *scene_void);
    void button_cl_map_stat(button_t *but, void *scene_void);
    void button_cl_map_option(button_t *but, void *rpg_void);
    void button_cl_map_pause(button_t *but, void *rpg_void);
    void button_cl_map_resume(button_t *but, void *scene_void);
    void button_cl_map_save(button_t *but, void *rpg_void);

    void but_fc_hv_reward(button_t *but, void *scene_void);
    void but_fc_hvex_reward(button_t *but, void *scene_void);
    void but_fc_pr_reward(button_t *but, void *scene_void);
    void but_fc_cl_reward_inventory(button_t *but, void *rpg_void);
    void but_fc_rl_reward(button_t *but, void *back_void);

    void button_fc_cl_create_player_choose_class(button_t *but, void *rpg_void);
    void button_fc_cl_create_player_save(button_t *but, void *rpg_void);
    void button_fc_hv_create_player_choose_class(button_t *but
    , void *rpg_void);
    void button_fc_hvex_create_player_choose_class(button_t *but
    , void *rpg_void);
    void button_fc_pr_create_player_choose_class(button_t *but
    , void *rpg_void);

    const char *fc_name[] = {
        "button_cl_return",
        "button_cl_quit",
        "button_hv_return",
        "button_hv_quit",
        "button_hvex_return",
        "button_hvex_quit",
        "button_pr_return",
        "button_pr_quit",
        "button_hv_item",
        "button_hvex_item",
        "button_pr_item",
        "button_cl_item",
        "button_cl_save_opt",
        "button_pr_save_opt",
        "button_hvex_save_opt",
        "button_hv_save_opt",
        "button_rl_key_opt",
        "goto_inventory",
        "button_hv_combat_but_aux",
        "button_hvex_combat_but_aux",
        "button_pr_combat_but_aux",
        "button_hv_combat_but_compt",
        "button_hvex_combat_but_compt",
        "button_pr_combat_but_compt",
        "button_cl_combat_but_compt",
        "button_cl_combat_but_turn",
        "button_cl_combat_but_flee",
        "button_cl_stat",
        "button_hv_stat",
        "button_pr_stat",
        "button_hvex_stat",
        "button_cl_map_inventory",
        "button_cl_map_stat",
        "button_cl_map_option",
        "but_fc_hv_reward",
        "but_fc_hvex_reward",
        "but_fc_pr_reward",
        "button_cl_menu_new_game",
        "button_cl_menu_option",
        "button_fc_cl_create_player_choose_class",
        "button_fc_cl_create_player_save",
        "button_cl_inventory_trash",
        "button_ho_inventory_trash",
        "button_pr_inventory_trash",
        "button_hoex_inventory_trash_can",
        "button_cl_map_pause",
        "button_cl_map_resume",
        "button_cl_map_save",
        "button_cl_menu_continue",
        "button_fc_hv_create_player_choose_class",
        "button_fc_hvex_create_player_choose_class",
        "button_fc_pr_create_player_choose_class",
        "button_pr_menu_option",
        "button_hv_menu_option",
        "button_hvex_menu_option",
        "but_fc_cl_reward_inventory",
        "but_fc_rl_reward",
        "button_cl_menu_howtoplay",
        "NULL",
        NULL
    };

    void (* const fonction[])(button_t *, void *) = {
        &button_cl_return,
        &button_cl_quit,
        &button_hv_return,
        button_hv_quit,
        button_hvex_return,
        button_hvex_quit,
        button_pr_return,
        button_pr_quit,
        &button_hv_item,
        &button_hvex_item,
        &button_pr_item,
        &button_cl_item,
        &button_cl_save_opt,
        &button_pr_save_opt,
        &button_hvex_save_opt,
        &button_hv_save_opt,
        &button_rl_key_opt,
        &goto_inventory,
        &button_hv_combat_but_aux,
        &button_hvex_combat_but_aux,
        &button_pr_combat_but_aux,
        &button_hv_combat_but_compt,
        &button_hvex_combat_but_compt,
        &button_pr_combat_but_compt,
        &button_cl_combat_but_compt,
        &button_cl_combat_but_turn,
        &button_cl_combat_but_flee,
        &but_fc_cl_stat,
        &but_fc_hv_stat,
        &but_fc_pr_stat,
        &but_fc_hvex_stat,
        &button_cl_map_inventory,
        &button_cl_map_stat,
        &button_cl_map_option,
        &but_fc_hv_reward,
        &but_fc_hvex_reward,
        &but_fc_pr_reward,
        &button_cl_menu_new_game,
        &button_cl_menu_option,
        &button_fc_cl_create_player_choose_class,
        &button_fc_cl_create_player_save,
        &button_cl_inventory_trash,
        &button_ho_inventory_trash,
        &button_pr_inventory_trash,
        &button_hoex_inventory_trash,
        &button_cl_map_pause,
        &button_cl_map_resume,
        &button_cl_map_save,
        &button_cl_menu_continue,
        &button_fc_hv_create_player_choose_class,
        &button_fc_hvex_create_player_choose_class,
        &button_fc_pr_create_player_choose_class,
        &button_pr_menu_option,
        &button_hv_menu_option,
        &button_hvex_menu_option,
        &but_fc_cl_reward_inventory,
        &but_fc_rl_reward,
        &button_cl_menu_howtoplay,
        NULL
    };

#endif /* !FC_FOR_BUTTON_H_ */