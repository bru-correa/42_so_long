/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:20:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/11 21:10:42 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "fcntl.h"

static t_vector2d	send_map_not_found(void);

t_vector2d	get_map_size(char *map_path)
{
	t_vector2d	size;
	int			fd;
	char		*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (send_map_not_found());
	line = ft_get_next_line(fd);
	size.x = ft_strlen(line) - 1;
	size.y = 0;
	while (line != NULL)
	{
		size.y++;
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
	if (size.y == 0)
		ft_printf("Error\nThe map is empty!\n");
	return (size);
}

static t_vector2d	send_map_not_found(void)
{
	t_vector2d	size;

	size.x = -1;
	size.y = -1;
	ft_printf("Error\nMap file not found!\n");
	return (size);
}
