/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:37:51 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/25 22:09:04 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game)
{
	if (game->win_ptr == NULL)
		return (ERROR);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_map(game);
	game->wait_for_render = FALSE;
	return (0);
}
