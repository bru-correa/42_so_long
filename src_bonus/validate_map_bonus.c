/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:33:17 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 02:31:19 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map_bonus.h"

static int	is_map_shape_valid(char **map, int map_width);

int	is_map_valid(char **map, t_vector2d map_size)
{
	if (is_map_shape_valid(map, map_size.x) == FALSE)
		return (FALSE);
	else if (is_map_chars_valid(map, map_size) == FALSE)
		return (FALSE);
	else if (is_map_objs_count_valid(map, map_size) == FALSE)
		return (FALSE);
	else if (is_map_walled(map, map_size) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	is_map_shape_valid(char **map, int map_width)
{
	int	current_row_width;
	int	row;

	row = 0;
	while (map[row] != NULL)
	{
		current_row_width = ft_strlen(map[row]) - 1;
		if (current_row_width != map_width)
		{
			ft_printf("Error\nThe map must be rectangular!\n");
			return (FALSE);
		}
		row++;
	}
	return (TRUE);
}
