/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_walls_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:20:11 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 02:31:37 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map_bonus.h"

static int	check_horizontal_wall(char *map_row);
static int	check_vertical_walls(char **map, t_vector2d map_size);

int	is_map_walled(char **map, t_vector2d map_size)
{
	if (map_size.y < 3)
	{
		ft_printf("Error\nThe map must have at least 3 lines!\n");
		return (FALSE);
	}
	else if (check_horizontal_wall(map[0]) == FALSE)
		return (FALSE);
	else if (check_horizontal_wall(map[map_size.y - 1]) == FALSE)
		return (FALSE);
	else if (check_vertical_walls(map, map_size) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	check_horizontal_wall(char *map_row)
{
	int	i;

	i = 0;
	while (map_row[i] != '\n' && map_row[i] != '\0')
	{
		if (map_row[i] != '1')
		{
			ft_printf("Error\nThe map must be surrounded by walls!\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	check_vertical_walls(char **map, t_vector2d map_size)
{
	int	row;

	row = 1;
	while (row < map_size.y)
	{
		if (map[row][0] != '1' || map[row][map_size.x - 1] != '1')
		{
			ft_printf("Error\nThe map must be surrounded by walls!\n");
			return (FALSE);
		}
		row++;
	}
	return (TRUE);
}
