/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:56:53 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 02:30:50 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	render_current_tile(t_game *game, char tile, t_vector2d position);
static void	render_img(t_game *game, void *img_ptr, t_vector2d position);
static void	render_player(t_game *game, t_vector2d position);

void	render_map(t_game *game)
{
	t_vector2d	position;
	char		current_tile;

	position.y = 0;
	while (position.y < game->map_size.y)
	{
		position.x = 0;
		while (position.x < game->map_size.x)
		{
			current_tile = game->map[position.y][position.x];
			render_current_tile(game, current_tile, position);
			position.x++;
		}
		position.y++;
	}
}

static void	render_current_tile(t_game *game, char tile, t_vector2d position)
{
	if (tile == '0')
		render_img(game, game->assets.floor_img, position);
	else if (tile == '1')
		render_img(game, game->assets.wall_img, position);
	else if (tile == 'P')
		render_player(game, position);
	else if (tile == 'C')
		render_img(game, game->assets.coin_img, position);
	else if (tile == 'E')
		render_img(game, game->assets.exit_img, position);
}

static void	render_img(t_game *game, void *img_ptr, t_vector2d position)
{
	position.x = position.x * TILE_SIZE;
	position.y = position.y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr,
		position.x, position.y);
}

static void	render_player(t_game *game, t_vector2d position)
{
	if (game->player.direction.x == 1)
		render_img(game, game->assets.player_right_img, position);
	else if (game->player.direction.x == -1)
		render_img(game, game->assets.player_left_img, position);
	else if (game->player.direction.y == 1)
		render_img(game, game->assets.player_front_img, position);
	else if (game->player.direction.y == -1)
		render_img(game, game->assets.player_back_img, position);
}
