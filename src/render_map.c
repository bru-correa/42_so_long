/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:56:53 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 01:05:31 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_tile.h"

static void	render_current_tile(t_game *game, char tile, t_vector2d position);

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
		render_floor(game, position);
	else if (tile == '1')
		render_wall(game, position);
	else if (tile == 'P')
		render_player(game, position);
	else if (tile == 'C')
		render_collectible(game, position);
	else if (tile == 'E')
		render_exit(game, position);
}
