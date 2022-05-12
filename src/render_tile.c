/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:55 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/11 15:53:00 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "render_tile.h"

void	render_floor(t_game *game, t_vector2d position)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->assets.floor_img, position.x, position.y);
}

void	render_wall(t_game *game, t_vector2d position)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->assets.wall_img, position.x, position.y);
}

void	render_player(t_game *game, t_vector2d position)
{
	render_floor(game, position);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->assets.player_img, position.x, position.y);
}

void	render_collectible(t_game *game, t_vector2d position)
{
	render_floor(game, position);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->assets.collectible_img, position.x, position.y);
}

void	render_exit(t_game *game, t_vector2d position)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
			game->assets.exit_img, position.x, position.y);
}
