/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:21:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/05 17:23:05 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_direction(t_game *game);

// int	update(t_game *game)
// {
// 	static int	frame_counter = 0;

// 	if (game->player.position.x <= WINDOW_WIDTH - SPRITE_SIZE
// 		&& game->player.position.y <= WINDOW_HEIGHT - SPRITE_SIZE)
// 	{
// 		if (frame_counter == FRAME_DELAY)
// 		{
// 			game->player.position.x += game->input.direction.x;
// 			game->player.position.y += game->input.direction.y;
// 			ft_printf("Player Moved");
// 			frame_counter = 0;
// 			render(game);
// 		}
// 		else
// 			frame_counter++;
// 	}
// 	return (0);
// }

int	update(t_game *game)
{
	static int	frame_counter = 0;

	if (frame_counter == FRAME_DELAY)
	{
		update_player_direction(game);
		game->player.position.x += game->input.direction.x * 2;
		game->player.position.y += game->input.direction.y * 2;
		render(game);
		frame_counter = 0;
	}
	frame_counter++;
	return (0);
}

static void	update_player_direction(t_game *game)
{
	if (game->input.right == 1)
		game->input.direction.x = 1;
	else if (game->input.left == 1)
		game->input.direction.x = -1;
	else
		game->input.direction.x = 0;
	if (game->input.down == 1)
		game->input.direction.y = 1;
	else if (game->input.up == 1)
		game->input.direction.y = -1;
	else
		game->input.direction.y = 0;
}
