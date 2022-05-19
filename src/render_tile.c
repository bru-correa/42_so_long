/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:44:55 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 00:44:42 by bcorrea-         ###   ########.fr       */
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
	render_floor(game, position);
	render_img(game, game->assets.player_img, position);
}

void	render_collectible(t_game *game, t_vector2d position)
{
	render_floor(game, position);
	render_img(game, game->assets.collectible_img, position);
}

void	render_exit(t_game *game, t_vector2d position)
{
	render_img(game, game->assets.exit_img, position);
}
