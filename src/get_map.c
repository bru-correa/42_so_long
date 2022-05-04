/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:05:48 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/04 16:26:49 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static char	**get_tilemap(char *tilemap_path, int tilemap_height);
static int	get_tilemap_height(char *tilemap_path);
static int	count_file_lines(char *map_path);

t_map	get_map(char *tilemap_path)
{
	t_map	map;

	map.height = get_tilemap_height(tilemap_path);
	map.tilemap = get_tilemap(tilemap_path, map.height);
	if (map.tilemap == NULL)
		return (map);
	map.width = ft_strlen(map.tilemap[0]) - 1;
	map.collectible_count = 0;
	map.exit_count = 0;
	map.player_count = 0;
	if (is_map_valid(map) == FALSE)
	{
		free_tilemap(map.tilemap);
		map.tilemap = NULL;
	}
	return (map);
}

void	free_tilemap(char **tilemap)
{
	int	row;

	row = 0;
	while (tilemap[row] != NULL)
	{
		free(tilemap[row]);
		row++;
	}
	free(tilemap);
}

static int	count_file_lines(char *tilemap_path)
{
	int		counter;
	int		fd;
	char	*line;

	fd = open(tilemap_path, O_RDONLY);
	if (fd < 0)
		return (-1);
	counter = 0;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = ft_get_next_line(fd);
		counter++;
	}
	close(fd);
	return (counter);
}

static int	get_tilemap_height(char *tilemap_path)
{
	int	tilemap_height;

	tilemap_height = count_file_lines(tilemap_path);
	if (tilemap_height <= 0)
	{
		ft_printf("Error\nMap file not found or the map is empty!\n");
		return (0);
	}
	return (tilemap_height);
}

/* The last tilemap row will be NULL */
static char	**get_tilemap(char *tilemap_path, int tilemap_height)
{
	int		fd;
	char	**tilemap;
	int		row;

	if (tilemap_height == 0)
		return (NULL);
	tilemap = malloc((tilemap_height + 1) * sizeof(char *));
	if (tilemap == NULL)
		return (NULL);
	fd = open(tilemap_path, O_RDONLY);
	row = 0;
	while (row <= tilemap_height)
	{
		tilemap[row] = ft_get_next_line(fd);
		row++;
	}
	close(fd);
	return (tilemap);
}
