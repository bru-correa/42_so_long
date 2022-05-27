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
APPS_DIR			= ./apps
BIN_DIR				= ./bin
LIB_DIR				= ./lib

LIBFT_DIR			= $(LIB_DIR)/libft

FILENAMES			= hooks get_map validate_map
FILENAMES			+= validate_map_walls validate_map_objs exit_game
FILENAMES			+= load_assets get_map_size render_map
FILENAMES			+= create_game_data
FILENAMES			+= get_char_count update_player

OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES))
MAIN				= $(APPS_DIR)/$(NAME).c
PROGRAM				= $(BIN_DIR)/$(NAME)

# TESTS
TESTS_DIR			= ./tests
TESTS_CFLAGS		= -I $(TESTS_DIR)
TESTS_MAIN			= $(TESTS_DIR)/tests.c
TESTS_FILENAMES		= test_maps
TESTS_OBJ_FILES		= $(patsubst %, $(TESTS_DIR)/%.o, $(TESTS_FILENAMES))
TESTS				= $(TESTS_DIR)/tests
VALGRIND			= valgrind -q --leak-check=full --show-leak-kinds=all \
						-s --track-origins=yes --verbose

all:				$(NAME)

required:			$(OBJ_DIR) $(BIN_DIR) $(OBJ_FILES) libft

debug:				required
					$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(BIN_DIR)/debug

$(NAME):			required
					$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(PROGRAM)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) -c -g $< $(CFLAGS) -o $@

$(BIN_DIR):
					mkdir -p $@

libft:
					$(MAKE) -C $(LIBFT_DIR)

run:				all
					$(PROGRAM) resources/maps/default.ber

clean:
					$(MAKE) -C $(LIBFT_DIR) clean
					rm -rf $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_DIR) fclean
					rm -f $(PROGRAM)

# TESTS [REMOVE LATER]
tests:				required $(TESTS_OBJ_FILES)
					$(CC) -g $(TESTS_MAIN) $(OBJ_FILES) $(TESTS_OBJ_FILES) \
						$(CFLAGS) $(TESTS_CFLAGS) $(CFLAGS_LIB) -o $(TESTS)

$(TESTS_DIR)/%.o:	$(SRC_DIR)%.c
					$(CC) -c -g $< $(CFLAGS) $(TESTS_CFLAGS) -o $@

runt:				tests
					$(VALGRIND) $(TESTS)

runv:				all
					$(VALGRIND) $(PROGRAM) resources/maps/default.ber

.PHONY:	all libft run clean fclean re debug test runt
