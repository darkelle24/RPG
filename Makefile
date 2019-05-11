##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC		=	gcc

SRC		=	src/parser/button/button_list.c					\
			src/parser/button/lib_button_1.c				\
			src/parser/button/lib_button_2.c				\
			src/parser/button/lib_button_3.c				\
			src/parser/button/lib_button_4.c				\
			src/parser/button/lib_button_5.c				\
			src/parser/button/lib_button_6.c				\
			src/parser/button/lib_button_set_stat.c			\
			src/create_perso/create_perso.c					\
			src/create_perso/corsair_perso.c				\
			src/create_perso/cyborgs_perso.c				\
			src/create_perso/hacker_perso.c 				\
			src/particle_generator/init_particule.c 		\
			src/particle_generator/particule.c 				\
			src/particle_generator/system_particule.c		\
			src/map/map.c									\
			src/map/init_map.c 								\
			src/map/door_of_the_boss.c						\
			src/map/call_entity_combat.c					\
			src/map/dialogue/dialogue.c						\
			src/map/dialogue/exit_dialogue.c				\
			src/map/dialogue/recup_name.c					\
			src/lib/degrade_color.c							\
			src/lib/strfind.c								\
			src/lib/strtool.c								\
			src/lib/strtool_2.c 							\
			src/lib/strtool_3.c								\
			src/lib/utilities.c								\
			src/lib/get_floatnbr.c							\
			src/lib/char_to_array_of_char.c					\
			src/lib/my_fprintf/chain_tools.c				\
			src/lib/my_fprintf/function_pointer_array.c		\
			src/lib/my_fprintf/my_itoa.c					\
			src/lib/my_fprintf/str_tools.c					\
			src/lib/my_fprintf/my_fprintf.c					\
			src/stat/stat.c									\
			src/stat/button_stat.c 							\
			src/parser/scene/free_scene_2.c					\
			src/parser/scene/free_scene.c					\
			src/parser/scene/parsing_of_scene.c				\
			src/parser/scene/scene_boutton.c				\
			src/parser/scene/scene_event.c					\
			src/parser/scene/scene_font.c					\
			src/parser/scene/scene_music.c					\
			src/parser/pre_load_text/pre_load_text.c 		\
			src/parser/pre_load_text/free_lad_text.c		\
			src/parser/scene/scene_object_1.c				\
			src/parser/scene/scene_object_2.c				\
			src/parser/scene/scene_other_1.c				\
			src/parser/scene/scene_other_2.c				\
			src/parser/scene/scene_other_3.c				\
			src/parser/scene/scene_sound.c					\
			src/parser/scene/scene_text.c					\
			src/parser/scene/scene_loader.c					\
			src/parser/scene/texture_loader.c				\
			src/parser/sounds/music_soud_lib.c				\
			src/parser/sounds/volume_bar.c					\
			src/parser/tools/create_array.c					\
			src/parser/tools/create_geo_form.c				\
			src/parser/tools/create_object.c				\
			src/parser/tools/create_text.c					\
			src/parser/tools/create_window.c				\
			src/parser/tools/destroy_object.c				\
			src/parser/tools/display_list_add.c				\
			src/parser/tools/display_list.c					\
			src/parser/tools/progress_bar_1.c				\
			src/parser/tools/progress_bar_2.c				\
			src/parser/tools/rev_list_order.c				\
			src/parser/tools/rotate_sprite.c				\
			src/parser/tools/text_bar_1.c					\
			src/parser/tools/text_bar_2.c					\
			src/parser/tools/text_list.c					\
			src/parser/competence/competence.c				\
			src/parser/ennemy/ennemy_parser.c				\
			src/parser/ennemy/ennemy_parser_2.c				\
			src/combat/combat.c								\
			src/combat/ennemy_ia.c							\
			src/combat/ennemy_ia_comp.c 					\
			src/combat/combat_tools.c 						\
			src/combat/competences_combat.c					\
			src/combat/ennemy_combat.c 						\
			src/combat/init_ath_combat.c					\
			src/combat/init_combat.c 						\
			src/combat/speed_combat.c 						\
			src/combat/flags/ad.c							\
			src/combat/flags/ap.c							\
			src/combat/flags/missing_hp.c					\
			src/combat/reward.c								\
			src/combat/init_reward.c 						\
			src/cinematic/cinematic.c  						\
			src/button_fc/mini_fc.c							\
			src/button_fc/button_fc_inventory.c				\
			src/button_fc/button_fc_inventory_2.c			\
			src/button_fc/button_fc_inventory_3.c			\
			src/button_fc/button_fc_inventory_4.c			\
			src/button_fc/button_fc_inventory_5.c			\
			src/button_fc/button_fc_inventory_6.c			\
			src/button_fc/button_fc_inventory_7.c			\
			src/button_fc/button_fc_inventory_trash.c		\
			src/button_fc/button_fc_option.c				\
			src/button_fc/button_fc_combat.c				\
			src/button_fc/button_fc_combat_2.c				\
			src/button_fc/button_fc_combat_3.c				\
			src/button_fc/button_fc_combat_5.c				\
			src/button_fc/button_fc_reward.c				\
			src/button_fc/button_fc_stat.c					\
			src/button_fc/button_fc_stat_2.c 				\
			src/button_fc/button_fc_map.c					\
			src/button_fc/button_fc_map_2.c					\
			src/button_fc/button_fc_menu.c					\
			src/button_fc/button_fc_menu_2.c				\
			src/button_fc/button_fc_create_player.c			\
			src/parser/map/map_loader.c						\
			src/parser/map/map_loader_2.c					\
			src/parser/map/map_block.c 						\
			src/parser/map/map_entity.c						\
			src/parser/map/map_entity_2.c					\
			src/parser/map/map_tools.c 						\
			src/parser/map/change_map.c						\
			src/map/final_boss.c							\
			src/game/play_game.c							\
			src/game/play_rpg.c								\
			src/game/load_player.c							\
			src/inventory/init_inventory_1.c				\
			src/inventory/init_inventory_2.c				\
			src/inventory/init_inventory_item.c				\
			src/inventory/inventory.c						\
			src/option/option.c								\
			src/option/option_2.c							\
			src/option/key_biding.c							\
			src/initialize/init_game.c						\
			src/end/end_game.c								\
			src/end/credit.c								\
			src/events/events.c								\
			src/player/player_inventory.c					\
			src/player/player_movement.c 					\
			src/player/movement_directions.c				\
			src/menu/menu_parallax.c 						\
			src/main.c										\

INCLUDE =	include/

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

override CFLAGS +=	-Wall			\
					-Wextra			\
					-I $(INCLUDE)	\

SFML_FLAGS	=	-lcsfml-system		\
				-lcsfml-window		\
				-lcsfml-graphics	\
				-lcsfml-audio		\
				-lm					\

RULE =	--no-print-directory

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(SFML_FLAGS)

spe:	fclean
	make $(RULE) all CFLAGS=-ggdb

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re spe
