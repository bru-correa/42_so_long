NAME				= so_long
CC					= clang
CFLAGS				= $(INCLUDE) $(CFLAGS_LIBFT)
CFLAGS				+= $(CFLAGS_LIBMLX)
# CFLAGS				+= -Wall -Wextra -Werror
CFLAGS_LIBFT		= -L $(LIBFT_DIR) -lft -I $(LIBFT_DIR)
CFLAGS_LIBMLX		= -lX11 -lXext -L $(LIBMLX_DIR) -lmlx -I $(LIBMLX_DIR)
INCLUDE				= -I $(INCLUDE_DIR)

INCLUDE_DIR			= ./include
SRC_DIR				= ./src
OBJ_DIR				= ./obj
APPS_DIR			= ./apps
BIN_DIR				= ./bin
LIB_DIR				= ./lib

LIBFT_DIR			= $(LIB_DIR)/libft
LIBMLX_DIR			= $(LIB_DIR)/libmlx

# FILENAMES			=
SRC_FILES			= $(patsubst %, $(SRC_DIR)/%, $(FILENAMES))
OBJ_FILES			= $(patsubst %, $(OBJ_DIR)/%, $(FILENAMES))
MAIN				= $(APPS_DIR)/$(NAME).c
PROGRAM				= $(BIN_DIR)/$(NAME)

all:				$(NAME)

$(NAME):			$(OBJ_DIR) $(OBJ_FILES) libft libmlx
					$(CC) $(MAIN) $(OBJ_FILES) $(CFLAGS) -o $(PROGRAM)

$(OBJ_DIR):
					mkdir -p $@

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					$(CC) -c $< $(CFLAGS) -o $@

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

.PHONY:	all libft libmlx run clean fclean re
