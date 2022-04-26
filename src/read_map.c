/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:05:48 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/26 14:11:49 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

int	count_file_lines(char *map_path)
{
	int		counter;
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	counter = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		counter++;
	}
	close(fd);
	return (counter);
}

static char	**get_map_from_file(int fd, int map_height)
{
	char	**map;
	int		row;

	map = malloc((map_height + 1) * sizeof(char *));
	if (map == NULL)
		return (NULL);
	row = 0;
	while (row < map_height)
	{
		map[row] = get_next_line(fd);
		row++;
	}
	map[row] = NULL;
	return (map);
}

static int	validate_map_shape(char **map)
{
	int	current_row_width;
	int	map_width;
	int	row;

	row = 0;
	map_width = ft_strlen(map[row]);
	while (map[row] != NULL)
	{
		current_row_width = ft_strlen(map[row]);
		if (current_row_width != map_width)
		{
			ft_printf("ERROR: The map must be rectangular!");
			return (-1);
		}
		row++;
	}
	return (0);
}

static int	validate_map(char **map)
{
	if (!validate_map_shape(map))
	{
		ft_printf("ERROR: The map must be rectangular!");
		return (-1);
	}
	return (0);
}

char	**create_map(char *map_path)
{
	int		fd;
	char	**map;
	int		map_height;

	map_height = count_file_lines(map_path);
	if (map_height <= 0)
	{
		ft_printf("ERROR: Map file not found!");
		return (NULL);
	}
	fd = open(map_path, O_RDONLY);
	map = get_map_from_file(fd, map_height);
	close(fd);
	if (map == NULL)
		return (NULL);
	if (!validate_map(map))
		return (NULL);
	return (map);
}
