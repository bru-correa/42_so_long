/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:35:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/11 21:14:52 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int			create_game_data(t_game *game, char *map_path);
static int			get_map_data(t_game *game, char *map_path);
static void			enter_game_loop(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;
	int		status;

	if (argc != 2)
	{
		ft_printf("Error\nYou must pass the map path as argument");
		return (ERROR);
	}
	status = create_game_data(&game, argv[1]);
	if (status == ERROR)
		return (ERROR);
	enter_game_loop(&game);
	return (0);
}

static int	create_game_data(t_game *game, char *map_path)
{
	int	status;

	status = get_map_data(game, map_path);
	if (status == ERROR)
		return (ERROR);
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (ERROR);
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map_size.x * TILE_SIZE,
			game->map_size.y * TILE_SIZE, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return (ERROR);
	}
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
	return (0);
}

static void	enter_game_loop(t_game *game)
{
	mlx_loop_hook(game->mlx_ptr, &update, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		game);
	mlx_loop(game->mlx_ptr);
}
