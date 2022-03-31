# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/25 17:50:16 by bcorrea-          #+#    #+#              #
#    Updated: 2022/03/31 01:12:05 by bcorrea-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= libft.a
CFLAGS				= -Wall -Werror -Wextra $(INCLUDE)
CC					= gcc
INCLUDE				= -I ./ -I ./include

# Main files
FILENAMES			= ft_isalpha ft_isdigit ft_isalnum ft_isascii
FILENAMES			+= ft_isprint ft_strlen ft_memset ft_bzero
FILENAMES			+= ft_memcpy ft_memmove
FILENAMES			+= ft_strlcpy ft_strlcat ft_toupper ft_tolower
FILENAMES			+= ft_strchr ft_strrchr ft_strncmp ft_memchr
FILENAMES			+= ft_memcmp ft_strnstr ft_atoi ft_calloc
FILENAMES			+= ft_strdup ft_substr ft_strjoin ft_strtrim
FILENAMES			+= ft_putchar_fd ft_putstr_fd ft_putendl_fd
FILENAMES			+= ft_putnbr_fd ft_split ft_itoa ft_strmapi
FILENAMES			+= ft_striteri
# Bonus files
FILENAMES			+= ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast
FILENAMES			+= ft_lstadd_back ft_lstdelone ft_lstclear
FILENAMES			+= ft_lstiter ft_lstmap
# Extra files that i added during the course
FILENAMES			+= ft_get_next_line ft_reset_ptr ft_printf print_char
FILENAMES			+= print_decimal print_hexadecimal printf_utils

SRC_FILES			= $(patsubst %, %.c, $(FILENAMES))
OBJ_FILES			= $(patsubst %, %.o, $(FILENAMES))

all:				$(NAME)

$(NAME):			$(OBJ_FILES)
					ar -rcs $@ $(OBJ_FILES)

%.o:				%.c
					$(CC) -c $< -o $@ $(CFLAGS)

clean:
					rm -f $(OBJ_FILES)

fclean:				clean
					rm -f $(NAME)

re:					fclean all

.PHONY:	all clean fclean re
