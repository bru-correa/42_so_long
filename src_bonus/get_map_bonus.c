/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:05:48 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 02:30:03 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map_bonus.h"
#include <fcntl.h>

static char	**get_map_from_file(char *map_path, int map_height);

char	**get_map(char *map_path, t_vector2d map_size)
{
	char	**map;

	map = get_map_from_file(map_path, map_size.y);
	if (map == NULL)
		return (map);
	if (is_map_valid(map, map_size) == FALSE)
	{
		free_map(map);
		map = NULL;
	}
	return (map);
}

/* The last map row will be NULL */
static char	**get_map_from_file(char *map_path, int map_height)
{
	int		fd;
	char	**map;
	int		row;

	if (map_height <= 0)
		return (NULL);
	map = malloc((map_height + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	fd = open(map_path, O_RDONLY);
	row = 0;
	while (row <= map_height)
	{
		map[row] = ft_get_next_line(fd);
		row++;
	}
	close(fd);
	return (map);
}
