/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:22:45 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/27 22:46:52 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		game->collectible_left--;
	}
	else if (next_tile == 'E' && game->collectible_left == 0)
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
	ft_printf("Steps: %d\n", game->player.steps);
}

// static void	update_player(t_game *game);
// static void	update_player_dir(t_game *game);
// static void	move_player(t_game *game, t_vector2d next_pos);

// void	update_map(t_game *game)
// {
// 	game->wait_for_render = TRUE;
// 	update_player(game);
// }

// static void	update_player(t_game *game)
// {
// 	t_vector2d	next_pos;
// 	char		next_tile;

// 	update_player_dir(game);
// 	next_pos.x = game->player_position.x + game->input.direction.x;
// 	next_pos.y = game->player_position.y + game->input.direction.y;
// 	next_tile = game->map[next_pos.y][next_pos.x];
// 	if (next_tile == '0')
// 		move_player(game, next_pos);
// 	else if (next_tile == 'C')
// 	{
// 		move_player(game, next_pos);
// 		game->collectible_left--;
// 	}
// 	else if (next_tile == 'E' && game->collectible_left == 0)
// 	{
// 		ft_printf("Level Complete!\n");
// 		exit_game(game);
// 	}
// }

// static void	update_player_dir(t_game *game)
// {
// 	if (game->input.right)
// 		game->input.direction.x = 1;
// 	else if (game->input.left)
// 		game->input.direction.x = -1;
// 	else if (game->input.up)
// 		game->input.direction.y = -1;
// 	else if (game->input.down)
// 		game->input.direction.y = 1;
// }

// static void	move_player(t_game *game, t_vector2d next_pos)
// {
// 	game->map[next_pos.y][next_pos.x] = 'P';
// 	game->map[game->player_position.y][game->player_position.x] = '0';
// 	game->player_position = next_pos;
// 	game->input.direction.x = 0;
// 	game->input.direction.y = 0;
// 	game->steps_counter++;
// 	ft_printf("Steps: %d\n", game->steps_counter);
// }
