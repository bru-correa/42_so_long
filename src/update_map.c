/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:22:45 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/25 22:23:04 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player(t_game *game);
static void	move_player(t_game *game, t_vector2d next_pos);

void	update_map(t_game *game)
{
	game->wait_for_render = TRUE;
	update_player(game);
}

static void	update_player(t_game *game)
{
	t_vector2d	next_pos;
	char		next_tile;

	next_pos.x = game->player_position.x + game->input.direction.x;
	next_pos.y = game->player_position.y + game->input.direction.y;
	next_tile = game->map[next_pos.y][next_pos.x];
	if (next_tile == '0')
		move_player(game, next_pos);
	else if (next_tile == 'C')
	{
		move_player(game, next_pos);
		game->collectible_left--;
	}
	else if (next_tile == 'E' && game->collectible_left == 0)
	{
		ft_printf("Level Complete!\n");
		exit_game(game);
	}
}

static void	move_player(t_game *game, t_vector2d next_pos)
{
	game->map[next_pos.y][next_pos.x] = 'P';
	game->map[game->player_position.y][game->player_position.x] = '0';
	game->player_position = next_pos;
	game->input.direction.x = 0;
	game->input.direction.y = 0;
	game->steps_counter++;
	ft_printf("Steps: %d\n", game->steps_counter);
}
