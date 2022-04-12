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

FILENAMES			= handle_input render update
SRC_FILES			= $(patsubst %, $(SRC_DIR)/%.c, $(FILENAMES))
OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%.o, $(FILENAMES))
MAIN				= $(APPS_DIR)/$(NAME).c
PROGRAM				= $(BIN_DIR)/$(NAME)

all:				$(NAME)

debug:				$(OBJ_DIR) $(BIN_DIR) $(OBJ_FILES) libft libmlx
					$(CC) -g $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(BIN_DIR)/debug

$(NAME):			$(OBJ_DIR) $(BIN_DIR) $(OBJ_FILES) libft libmlx
					$(CC) $(MAIN) $(OBJ_FILES) $(CFLAGS) $(CFLAGS_LIB) \
						-o $(PROGRAM)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) -c $< $(CFLAGS) -o $@

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

.PHONY:	all libft libmlx run clean fclean re debug
