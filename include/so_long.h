/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:44:02 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/12 17:19:18 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

/* MACROS */

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 896
# define SPRITE_SIZE 64
# define MLX_ERROR 1
# define FRAME_DELAY 1000

/* Structs */

typedef enum e_tag {Player, Pickup, Enemy, Wall, Exit, Dead}	t_tag;

typedef struct s_vector2d
{
	int	x;
	int	y;
}	t_vector2d;

typedef struct s_game_obj
{
	void		*img_ptr;
	t_vector2d	position;
	t_vector2d	size;
	t_tag		tag;
}	t_game_obj;

typedef struct s_tile
{
	void		*img_ptr;
	t_vector2d	position;
}	t_tile;

typedef struct s_collider
{
	t_vector2d	position;
	t_vector2d	size;
	t_tag		tag;
}	t_collider;

typedef struct s_input
{
	t_vector2d	direction;
	int			up;
	int			down;
	int			left;
	int			right;
	int			attack;
}	t_input;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			steps;
	int			coins_left;
	t_game_obj	*game_objs;
	t_game_obj	player; //HACK Just for quick testing
	t_input		input;
	t_tile		*bg_tiles;
	t_collider	*bg_colliders;
}	t_data;

int		update(t_data *data);
int		render(t_data *data);
int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
void	*create_img_ptr(t_data data, char *file_path);

#endif
