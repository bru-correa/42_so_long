/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:55 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/27 22:33:54 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_tile.h"

void	render_floor(t_game *game, t_vector2d position)
{
	render_img(game, game->assets.floor_img, position);
}

void	render_wall(t_game *game, t_vector2d position)
{
	render_img(game, game->assets.wall_img, position);
}

void	render_player(t_game *game, t_vector2d position)
{
	if (game->input.direction.x == 1)
		render_img(game, game->assets.player_right_img, position);
	else if (game->input.direction.x == -1)
		render_img(game, game->assets.player_left_img, position);
	else if (game->input.direction.y == 1)
		render_img(game, game->assets.player_front_img, position);
	else if (game->input.direction.y == -1)
		render_img(game, game->assets.player_back_img, position);
}

void	render_collectible(t_game *game, t_vector2d position)
{
	render_img(game, game->assets.collectible_img, position);
}

void	render_exit(t_game *game, t_vector2d position)
{
	render_img(game, game->assets.exit_img, position);
}
