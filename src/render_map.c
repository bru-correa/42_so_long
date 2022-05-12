/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:56:53 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/11 18:56:55 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "render_tile.h"

static void	render_current_tile(t_game *game, char c, t_vector2d position);

void	render_map(t_game *game)
{
	t_vector2d	position;
	char		current_tile;

	position.y = 0;
	while (position.y < game->map_size.y)
	{
		position.x = 0;
		current_tile = game->map[position.y][position.x];
		while (position.x < game->map_size.x)
		{
			render_current_tile(game, current_tile, position);
			position.x++;
		}
		position.y++;
	}
}

static void	render_current_tile(t_game *game, char c, t_vector2d position)
{
	if (c == '0')
		render_floor(game, position);
	else if (c == '1')
		render_wall(game, position);
	else if (c == 'P')
		render_player(game, position);
	else if (c == 'C')
		render_collectible(game, position);
	else if (c == 'E')
		render_exit(game, position);
}
