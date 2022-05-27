/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:23:55 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/07 17:46:43 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_d && game->wait_for_render == FALSE)
		update_player(game, 1, 0);
	else if (keysym == XK_a && game->wait_for_render == FALSE)
		update_player(game, -1, 0);
	else if (keysym == XK_w && game->wait_for_render == FALSE)
		update_player(game, 0, -1);
	else if (keysym == XK_s && game->wait_for_render == FALSE)
		update_player(game, 0, 1);
	if (keysym == XK_Escape)
		exit_game(game);
	return (0);
}

/* TODO Move this to data init function */
void	init_player(t_game *game)
{
	game->player.direction.x = 0;
	game->player.direction.y = 1;
	game->player.steps = 0;
}

// int	handle_keypress(int keysym, t_game *game)
// {
// 	if (keysym == XK_d)
// 		game->input.right = 1;
// 	if (keysym == XK_a)
// 		game->input.left = 1;
// 	if (keysym == XK_s)
// 		game->input.down = 1;
// 	if (keysym == XK_w)
// 		game->input.up = 1;
// 	if (keysym == XK_Escape)
// 	{
// 		exit_game(game);
// 		return (0);
// 	}
// 	if (game->wait_for_render == FALSE)
// 		update_map(game);
// 	return (0);
// }

// int	handle_keypress(int keysym, t_game *game)
// {
// 	if (keysym == XK_d)
// 		game->input.direction.x = 1;
// 	if (keysym == XK_a)
// 		game->input.direction.x = -1;
// 	if (keysym == XK_s)
// 		game->input.direction.y = 1;
// 	if (keysym == XK_w)
// 		game->input.direction.y = -1;
// 	if (game->wait_for_render == FALSE)
// 		update_map(game);
// 	if (keysym == XK_Escape)
// 	{
// 		exit_game(game);
// 		return (0);
// 	}
// 	return (0);
// }

// int	handle_keyrelease(int keysym, t_game *game)
// {
// 	if (keysym == XK_d || keysym == XK_a)
// 		game->input.direction.x = 0;
// 	if (keysym == XK_w || keysym == XK_s)
// 		game->input.direction.y = 0;
// 	return (0);
// }

// int	handle_keyrelease(int keysym, t_game *game)
// {
// 	if (keysym == XK_d)
// 		game->input.right = 0;
// 	if (keysym == XK_a)
// 		game->input.left = 0;
// 	if (keysym == XK_s)
// 		game->input.down = 0;
// 	if (keysym == XK_w)
// 		game->input.up = 0;
// 	return (0);
// }
