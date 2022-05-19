/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 21:39:04 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/17 21:41:05 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_MAP_H
# define VALID_MAP_H

# include "so_long.h"

int			is_map_valid(char **map, t_vector2d map_size);
int			is_map_chars_valid(char **map, t_vector2d map_size);
int			is_map_objs_count_valid(char **map, t_vector2d map_size);
int			is_map_walled(char **map, t_vector2d map_size);

#endif
