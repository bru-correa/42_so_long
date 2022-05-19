/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:21:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 00:05:14 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	update_player_direction(t_game *game);

/* HACK Testing memory leak */
int	update(t_game *game)
{
	static int	frame_counter = 0;

	if (frame_counter == FRAME_DELAY)
	{
		render(game);
		frame_counter = 0;
	}
	frame_counter++;
	return (0);
}

/* TODO Needs a rework */
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
