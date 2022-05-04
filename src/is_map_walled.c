/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_walled.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 15:20:11 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/04 15:38:43 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_horizontal_wall(char *tilemap_row);
static int	check_vertical_walls(t_map map);

int	is_map_walled(t_map map)
{
	if (map.height < 3)
	{
		ft_printf("Error\nThe map must have at least 3 lines!\n");
		return (FALSE);
	}
	else if (check_horizontal_wall(map.tilemap[0]) == FALSE)
		return (FALSE);
	else if (check_horizontal_wall(map.tilemap[map.height - 1]) == FALSE)
		return (FALSE);
	else if (check_vertical_walls(map) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	check_horizontal_wall(char *tilemap_row)
{
	int	i;

	i = 0;
	while (tilemap_row[i] != '\n' && tilemap_row[i] != '\0')
	{
		if (tilemap_row[i] != '1')
		{
			ft_printf("Error\nThe map must be surrounded by walls!\n");
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

static int	check_vertical_walls(t_map map)
{
	int	row;

	row = 1;
	while (row < map.height)
	{
		if (map.tilemap[row][0] != '1' ||
			map.tilemap[row][map.width - 1] != '1')
		{
			ft_printf("Error\nThe map must be surrounded by walls!\n");
			return (FALSE);
		}
		row++;
	}
	return (TRUE);
}
