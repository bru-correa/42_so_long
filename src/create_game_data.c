/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:35:06 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/25 02:13:21 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int			get_map_data(t_game *game, char *map_path);
static int			create_new_window(t_game *game);
static t_vector2d	get_player_position(char **map, t_vector2d map_size);

int	create_game_data(t_game *game, char *map_path)
{
	int			data_status;

	data_status = get_map_data(game, map_path);
	if (data_status == ERROR)
		return (ERROR);
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (ERROR);
	load_assets(game);
	data_status = create_new_window(game);
	game->steps_counter = 0;
	game->input = init_input();
	return (0);
}

static int	get_map_data(t_game *game, char *map_path)
{
	game->map_size = get_map_size(map_path);
	if (game->map_size.x <= 0 || game->map_size.y <= 0)
		return (ERROR);
	game->map = get_map(map_path, game->map_size);
	if (game->map == NULL)
		return (ERROR);
	game->collectible_left = get_char_count(game->map, 'C', game->map_size);
	game->player_position = get_player_position(game->map, game->map_size);
	return (0);
}

static t_vector2d	get_player_position(char **map, t_vector2d map_size)
{
	t_vector2d	position;

	position.y = 0;
	while (position.y < map_size.y)
	{
		position.x = 0;
		while (position.x < map_size.x)
		{
			if (map[position.y][position.x] == 'P')
				return (position);
			position.x++;
		}
		position.y++;
	}
	return (position);
}

static int	create_new_window(t_game *game)
{
	t_vector2d	window_size;

	window_size.x = game->map_size.x * TILE_SIZE;
	window_size.y = game->map_size.y * TILE_SIZE;
	game->win_ptr = mlx_new_window(game->mlx_ptr, window_size.x, window_size.y,
			"so_long");
	if (game->win_ptr == NULL)
	{
		free_game_data(game);
		return (ERROR);
	}
	return (0);
}
