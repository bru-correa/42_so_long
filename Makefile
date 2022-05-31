RED					= \033[1;31m
YELLOW				= \033[1;33m
GREEN				= \033[1;32m
NOCOLOR				= \033[0m
DONE_MSG			= "$(GREEN)Done!$(NOCOLOR)"
COMPILING_MSG		= "$(YELLOW)Compiling...$(NOCOLOR)"
CLEANING_MSG		= "$(RED)Cleaning up...$(NOCOLOR)"

NAME				= so_long
CC					= clang
CFLAGS				= -Wall -Wextra -Werror $(INCLUDE)
CFLAGS_LIB			= $(CFLAGS_LIBFT) $(CFLAGS_LIBMLX)
CFLAGS_LIBFT		= -L $(LIBFT_DIR) -lft
CFLAGS_LIBMLX		= -lX11 -lXext -lmlx
INCLUDE				= -I $(INCLUDE_DIR) -I $(LIBFT_DIR)

INCLUDE_DIR			= ./include
SRC_DIR				= ./src
OBJ_DIR				= ./obj
LIB_DIR				= ./lib

LIBFT_DIR			= $(LIB_DIR)/libft

FILENAMES			= hooks get_map validate_map
FILENAMES			+= validate_map_walls validate_map_objs exit_game
FILENAMES			+= load_assets get_map_size render_map
FILENAMES			+= create_game_data
FILENAMES			+= get_char_count update_player print_ascii_art

OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES))
MAIN				= $(NAME).c

# BONUS
FILENAMES_BONUS		= $(addsuffix _bonus, $(FILENAMES))
FILENAMES_BONUS		+= render_hud_bonus load_coin_assets_bonus
FILENAMES_BONUS		+= set_animation_bonus

OBJ_BONUS_FILES		= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES_BONUS))
MAIN_BONUS			= $(NAME)_bonus.c
SRC_BONUS_DIR		= ./src_bonus

# TESTS
TESTS_DIR			= ./tests
TESTS_CFLAGS		= -I $(TESTS_DIR)
TESTS_MAIN			= $(TESTS_DIR)/tests.c
TESTS_FILENAMES		= test_maps
TESTS_OBJ_FILES		= $(patsubst %, $(TESTS_DIR)/%.o, $(TESTS_FILENAMES))
TESTS				= $(TESTS_DIR)/tests
VALGRIND			= valgrind --leak-check=full --show-leak-kinds=all
VALGRIND			+= --track-origins=yes --quiet --tool=memcheck
VALGRIND			+= --keep-debuginfo=yes

all:				$(NAME)

bonus:				required_bonus
					@$(CC) -g $(MAIN_BONUS) $(OBJ_BONUS_FILES) $(CFLAGS) \
						$(CFLAGS_LIB) -o $(NAME)_bonus

required:			compile_message $(OBJ_DIR) $(OBJ_FILES) libft

required_bonus:		compile_message $(OBJ_DIR) $(OBJ_BONUS_FILES) libft

debug:				required
					@$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o debug

$(NAME):			required
					@$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(NAME)
					@echo $(DONE_MSG)

$(OBJ_DIR):
					@mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					@$(CC) -c -g $< $(CFLAGS) -o $@

$(OBJ_DIR)/%.o:		$(SRC_BONUS_DIR)/%.c
					@$(CC) -c -g $< $(CFLAGS) -o $@

libft:
					@$(MAKE) -C $(LIBFT_DIR)

run:				all
					@./$(NAME) resources/maps/default.ber

runv:				all
					$(VALGRIND) ./$(NAME) resources/maps/default.ber

run_bonus:			bonus
					@./$(NAME)_bonus resources/maps/bonus.ber

run_bonusv:			bonus
					$(VALGRIND) ./$(NAME)_bonus resources/maps/bonus.ber

clean:
					@echo $(CLEANING_MSG)
					@$(MAKE) -C $(LIBFT_DIR) clean
					@rm -rf $(OBJ_DIR)
					@rm -rf $(BIN_DIR)

fclean:				clean
					@$(MAKE) -C $(LIBFT_DIR) fclean
					@rm -f $(NAME)
					@rm -f $(NAME)_bonus

re:					fclean all

compile_message:
					@echo $(COMPILING_MSG)

# TESTS [REMOVE LATER]
tests:				required $(TESTS_OBJ_FILES)
					@$(CC) -g $(TESTS_MAIN) $(OBJ_FILES) $(TESTS_OBJ_FILES) \
						$(CFLAGS) $(TESTS_CFLAGS) $(CFLAGS_LIB) -o $(TESTS)

$(TESTS_DIR)/%.o:	$(SRC_DIR)%.c
					@$(CC) -c -g $< $(CFLAGS) $(TESTS_CFLAGS) -o $@

runt:				tests
					$(VALGRIND) $(TESTS)

.PHONY:	all libft run clean fclean re debug test runt runv runb runbv
