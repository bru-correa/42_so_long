/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:14:17 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 00:32:24 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_loop_end(game->mlx_ptr);
	free_assets(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game->map);
	exit(0);
	return (0);
}

void	free_game_data(t_game *game)
{
	free_assets(game);
	free(game->win_ptr);
	free(game->mlx_ptr);
	free_map(game->map);
}

void	free_map(char **map)
{
	int	row;

	row = 0;
	while (map[row] != NULL)
	{
		free(map[row]);
		row++;
	}
	free(map);
}
