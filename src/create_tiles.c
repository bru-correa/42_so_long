/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:38:36 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/10 16:41:01 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// IDEIA Maybe turn row/collumn into vector2 position
t_tile	create_tiles(t_game *game, t_map map)
{
	t_vector2d	position;
	int	current_tile;
	int	tiles_count;

	//HACK Counting the map tiles as: tilemap area - player - exit + 1(NULL)
	tiles_count = map.width * map.height
	game->tiles = malloc(sizeof(t_tile) * (map.width * map.height) - 1);
	position.x = 0;
	while (map.tilemap[position.x][position.y] < map.height)
	{
		position.y = 0;
		while (map.tilemap[position.x][position.y] != '\0' ||
				map.tilemap[position.x][position.y] != '\n')
		{
			if (map.tilemap[position.x][position.y] == '0')
			{
				create_floor(game, position.x, position.y);
			}
			position.y++;
		}
		position.x++;
	}


	//TODO Put NULL in the last tile
}

static int	get_tiles_count(t_map map)
{
	int	tiles_count;

	tiles_count = map.width * map.height;
	tiles_count -= map.player_count - map.exit_count;
}

static t_tile	create_floor(t_game *game, int row, int collumn)
{
	t_tile	floor;

	floor.img_ptr = create_img_ptr(game, "resources/sprites/tiles/floor.xpm");
	floor.position.x = row * TILE_SIZE;
	floor.position.y = collumn * TILE_SIZE;
	return (floor);
}

static t_tile	create_wall(t_game *game, int row, int collumn)
{

}
