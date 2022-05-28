/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:39:04 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 01:25:56 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_BONUS_H
# define VALID_MAP_BONUS_H

# include "so_long_bonus.h"

int	is_map_valid(char **map, t_vector2d map_size);
int	is_map_chars_valid(char **map, t_vector2d map_size);
int	is_map_objs_count_valid(char **map, t_vector2d map_size);
int	is_map_walled(char **map, t_vector2d map_size);

#endif
