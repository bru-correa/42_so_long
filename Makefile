# TODO Use the linux version from mlx
NAME				= so_long
CC					= clang
CFLAGS				= -Wall -Wextra -Werror $(INCLUDE)
CFLAGS_LIB			= $(CFLAGS_LIBFT) $(CFLAGS_LIBMLX)
CFLAGS_LIBFT		= -L $(LIBFT_DIR) -lft
CFLAGS_LIBMLX		= -lX11 -lXext -L $(LIBMLX_DIR) -lmlx
INCLUDE				= -I $(INCLUDE_DIR) -I $(LIBMLX_DIR) -I $(LIBFT_DIR)

INCLUDE_DIR			= ./include
SRC_DIR				= ./src
OBJ_DIR				= ./obj
APPS_DIR			= ./apps
BIN_DIR				= ./bin
LIB_DIR				= ./lib

LIBFT_DIR			= $(LIB_DIR)/libft
LIBMLX_DIR			= $(LIB_DIR)/libmlx

FILENAMES			= handle_input render update get_map validate_map
FILENAMES			+= validate_map_walls validate_map_objs exit_game
FILENAMES			+= load_assets get_map_size free_map render_map render_tile

SRC_FILES			= $(patsubst %, $(SRC_DIR)/%.c, $(FILENAMES))
OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES))
MAIN				= $(APPS_DIR)/$(NAME).c
PROGRAM				= $(BIN_DIR)/$(NAME)

# TESTS
TESTS_DIR			= ./tests
TESTS_MAIN			= $(TESTS_DIR)/tests.c
TESTS				= $(TESTS_DIR)/tests
VALGRIND			= valgrind -q --leak-check=full --show-leak-kinds=all \
						-s --track-origins=yes --verbose

all:				$(NAME)

required:			$(OBJ_DIR) $(BIN_DIR) $(OBJ_FILES) libft libmlx

debug:				required
					$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(BIN_DIR)/debug

$(NAME):			required
					$(CC) $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(PROGRAM)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) -c -g $< $(CFLAGS) -o $@

$(BIN_DIR):
					mkdir -p $@

libft:
					$(MAKE) -C $(LIBFT_DIR)

libmlx:
					$(MAKE) -C $(LIBMLX_DIR)

run:				all
					$(PROGRAM)

clean:
					$(MAKE) -C $(LIBFT_DIR) clean
					$(MAKE) -C $(LIBMLX_DIR) clean
					rm -rf $(OBJ_DIR)

fclean:				clean
					$(MAKE) -C $(LIBFT_DIR) fclean
					rm -f $(PROGRAM)

# TESTS [REMOVE LATER]
tests:				required
					$(CC) -g $(TESTS_MAIN) $(OBJ_FILES) $(CFLAGS) \
					$(CFLAGS_LIB) -o $(TESTS)

runt:				tests
					$(VALGRIND) $(TESTS)

runv:				all
					$(VALGRIND) $(PROGRAM) resources/maps/default.ber

.PHONY:	all libft libmlx run clean fclean re debug test runt
