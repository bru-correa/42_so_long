/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:44:02 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/16 17:42:32 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

/* MACROS */

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 896
# define TILE_SIZE 64
# define ERROR 1
# define FRAME_DELAY 1000

/* Structs */

typedef enum e_tag {Player, Pickup, Wall, Exit}	t_tag;

typedef struct s_vector2d
{
	int	x;
	int	y;
}	t_vector2d;

//HACK Maybe add a collider to game_obj, moving tag and size to colllider
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

typedef struct s_input
{
	t_vector2d	direction;
	int			up;
	int			down;
	int			left;
	int			right;
	int			attack;
}	t_input;

typedef struct s_assets
{
	void	*floor_img;
	void	*wall_img;
	void	*player_img;
	void	*collectible_img;
	void	*exit_img;
}	t_assets;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_assets	assets;
	int			steps_counter;
	int			collectible_left;
	t_game_obj	*objs;
	t_game_obj	player;
	t_input		input;
	t_tile		*tiles;
	char		**map;
	t_vector2d	map_size;
}	t_game;

typedef struct s_map
{
	char	**tilemap;
	int		player_count;
	int		exit_count;
	int		collectible_count;
	int		width;
	int		height;
}	t_map;

int			update(t_game *game);
int			render(t_game *game);
int			handle_keypress(int keysym, t_game *game);
int			handle_keyrelease(int keysym, t_game *game);
t_input		init_input(void);
int			load_assets(t_game *game);
t_vector2d	get_map_size(char *map_path);
char		**get_map(char *map_path, t_vector2d map_size);
void		free_map(char **map);
int			is_map_valid(char **map, t_vector2d map_size);
int			is_map_chars_valid(char **map, t_vector2d map_size);
int			is_map_objs_count_valid(char **map, t_vector2d map_size);
int			is_map_walled(char **map, t_vector2d map_size);
void		render_map(t_game *game);
void		exit_game(t_game *game);

#endif
