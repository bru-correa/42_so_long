/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:44:02 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 22:53:01 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
# define FRAME_DELAY 4000

/* Structs */

typedef struct s_vector2d
{
	int	x;
	int	y;
}	t_vector2d;

typedef struct player
{
	t_vector2d	position;
	t_vector2d	direction;
	int			steps;
}	t_player;

typedef struct s_assets
{
	void	*floor_img;
	void	*wall_img;
	void	*player_front_img;
	void	*player_back_img;
	void	*player_right_img;
	void	*player_left_img;
	void	*coin_img;
	void	*exit_img;
	void	*score_img;
}	t_assets;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_assets	assets;
	int			coins;
	t_player	player;
	char		**map;
	t_vector2d	map_size;
	int			wait_for_render;
}	t_game;

int			create_game_data(t_game *game, char *map_path);
int			get_char_count(char **map, char c, t_vector2d map_size);
void		free_game_data(t_game *game);
int			update(t_game *game);
int			handle_keypress(int keysym, t_game *game);
int			load_assets(t_game *game);
void		free_assets(t_game *game);
t_vector2d	get_map_size(char *map_path);
char		**get_map(char *map_path, t_vector2d map_size);
void		free_map(char **map);
void		render_map(t_game *game);
void		update_player(t_game *game, int x, int y);
int			exit_game(t_game *game);
void		render_hud(t_game *game);

#endif
