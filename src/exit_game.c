/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 17:14:17 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/11 20:35:06 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_game(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_loop_end(game->mlx_ptr);
	mlx_destroy_image(game->mlx_ptr, game->player.img_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free_map(game->map);
	exit(0);
}
