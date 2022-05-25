/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:35:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/25 22:33:08 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void			enter_game_loop(t_game *game);

int	main(int argc, char *argv[])
{
	t_game	game;
	int		data_status;

	if (argc != 2)
	{
		ft_printf("Error\nYou must pass the map path as argument");
		return (ERROR);
	}
	data_status = create_game_data(&game, argv[1]);
	if (data_status == ERROR)
		return (ERROR);
	enter_game_loop(&game);
	return (0);
}

static void	enter_game_loop(t_game *game)
{
	mlx_loop_hook(game->mlx_ptr, &update, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		game);
	mlx_hook(game->win_ptr, DestroyNotify, NoEventMask, &exit_game, game);
	mlx_loop(game->mlx_ptr);
}
