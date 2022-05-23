/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:45:48 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 21:46:13 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game_data(t_game *game)
{
	free_assets(game);
	free(game->win_ptr);
	free(game->mlx_ptr);
	free_map(game->map);
}
