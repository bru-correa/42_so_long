/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_tile.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:51:13 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/11 15:52:07 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TILE_H
# define RENDER_TILE_H

# include "so_long.h"

void	render_floor(t_game *game, t_vector2d position);
void	render_wall(t_game *game, t_vector2d position);
void	render_player(t_game *game, t_vector2d position);
void	render_collectible(t_game *game, t_vector2d position);
void	render_exit(t_game *game, t_vector2d position);

#endif
