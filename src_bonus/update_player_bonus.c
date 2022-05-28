/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:22:45 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 03:01:22 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_new_position(t_game *game, t_vector2d new_pos);
static void	move_player(t_game *game, t_vector2d new_pos);

void	update_player(t_game *game, int x, int y)
{
	t_vector2d	new_pos;

	game->wait_for_render = TRUE;
	new_pos.x = game->player.position.x + x;
	new_pos.y = game->player.position.y + y;
	game->player.direction.x = x;
	game->player.direction.y = y;
	check_new_position(game, new_pos);
}

static void	check_new_position(t_game *game, t_vector2d new_pos)
{
	char	next_tile;

	next_tile = game->map[new_pos.y][new_pos.x];
	if (next_tile == '0')
		move_player(game, new_pos);
	else if (next_tile == 'C')
	{
		move_player(game, new_pos);
		game->coins--;
	}
	else if (next_tile == 'E' && game->coins == 0)
	{
		ft_printf("Level Complete!\n");
		exit_game(game);
	}
}

static void	move_player(t_game *game, t_vector2d new_pos)
{
	game->map[game->player.position.y][game->player.position.x] = '0';
	game->map[new_pos.y][new_pos.x] = 'P';
	game->player.position = new_pos;
	game->player.steps++;
}
