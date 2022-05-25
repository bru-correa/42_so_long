/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:21:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/25 20:56:16 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_direction(t_game *game);
static void	update_player(t_game *game);
static void	move_player(t_game *game, t_vector2d next_pos);

int	update(t_game *game)
{
	static int	frame_counter = 0;

	// update_player_direction(game);
	if (frame_counter == FRAME_DELAY)
	{
		update_player(game);
		render(game);
		frame_counter = 0;
	}
	frame_counter++;
	return (0);
}

static void	update_player(t_game *game)
{
	t_vector2d	next_pos;
	char		next_tile;

	update_player_direction(game);
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

static void	update_player_direction(t_game *game)
{
	if (game->input.right == 1)
		game->input.direction.x = 1;
	else if (game->input.left == 1)
		game->input.direction.x = -1;
	if (game->input.down == 1)
		game->input.direction.y = 1;
	else if (game->input.up == 1)
		game->input.direction.y = -1;
}

// static void	update_player_direction(t_game *game)
// {
// 	if (game->input.right == 1)
// 		game->input.direction.x = 1;
// 	else if (game->input.left == 1)
// 		game->input.direction.x = -1;
// 	else
// 		game->input.direction.x = 0;
// 	if (game->input.down == 1)
// 		game->input.direction.y = 1;
// 	else if (game->input.up == 1)
// 		game->input.direction.y = -1;
// 	else
// 		game->input.direction.y = 0;
// }

static void	move_player(t_game *game, t_vector2d next_pos)
{
	game->map[next_pos.y][next_pos.x] = 'P';
	game->map[game->player_position.y][game->player_position.x] = '0';
	game->player_position = next_pos;
	game->input.direction.x = 0;
	game->input.direction.y = 0;
}
