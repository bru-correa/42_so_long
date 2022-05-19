/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:31:09 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 01:44:11 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_tile.h"

void	render_img(t_game *game, void *img_ptr, t_vector2d position)
{
	position.x = position.x * TILE_SIZE;
	position.y = position.y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, img_ptr,
			position.x, position.y);
}
