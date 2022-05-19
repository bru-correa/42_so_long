/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:37:51 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 00:25:38 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game)
{
	if (game->win_ptr == NULL)
		return (ERROR);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_map(game);
	return (0);
}
