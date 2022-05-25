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
	if (keysym == XK_d)
		game->input.right = 1;
	if (keysym == XK_a)
		game->input.left = 1;
	if (keysym == XK_s)
		game->input.down = 1;
	if (keysym == XK_w)
		game->input.up = 1;
	if (keysym == XK_Escape)
	{
		exit_game(game);
		return (0);
	}
	return (0);
}

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
// 	if (keysym == XK_Escape)
// 	{
// 		exit_game(game);
// 		return (0);
// 	}
// 	return (0);
// }

int	handle_keyrelease(int keysym, t_game *game)
{
	if (keysym == XK_d)
		game->input.right = 0;
	if (keysym == XK_a)
		game->input.left = 0;
	if (keysym == XK_s)
		game->input.down = 0;
	if (keysym == XK_w)
		game->input.up = 0;
	return (0);
}

t_input	init_input(void)
{
	t_input	input;

	input.direction.x = 0;
	input.direction.y = 0;
	input.right = 0;
	input.left = 0;
	input.up = 0;
	input.down = 0;
	input.attack = 0;
	return (input);
}
