/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:21:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 02:30:29 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	render(t_game *game);

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

static int	render(t_game *game)
{
	if (game->win_ptr == NULL)
		return (ERROR);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_map(game);
	game->wait_for_render = FALSE;
	return (0);
}
