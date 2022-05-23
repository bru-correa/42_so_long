/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:16:17 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 21:28:58 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <stdio.h>
#include <fcntl.h>

static void	test_map_validation(char *map_name);
static char	*get_map_path(char *map_name);

void	test_maps(void)
{
	test_map_validation("default.ber");
	test_map_validation("wrong/wrong_shape.ber");
	test_map_validation("wrong/invalid_char_01.ber");
	test_map_validation("wrong/invalid_char_02.ber");
	test_map_validation("wrong/invalid_collectible.ber");
	test_map_validation("wrong/invalid_exit.ber");
	test_map_validation("wrong/invalid_player.ber");
	test_map_validation("wrong/empty_map.ber");
	test_map_validation("wrong/invalid_walls_01.ber");
	test_map_validation("wrong/invalid_walls_02.ber");
	test_map_validation("wrong/invalid_walls_03.ber");
	test_map_validation("wrong/invalid_walls_04.ber");
	test_map_validation("wrong/invalid_walls_05.ber");
	test_map_validation("wrong/2lines_map.ber");
}

static void	test_map_validation(char *map_name)
{
	char		*map_path;
	char		**map;
	t_vector2d	map_size;

	map_path = get_map_path(map_name);
	map_size = get_map_size(map_path);
	if (map_size.x <= 0 || map_size.y <= 0)
	{
		ft_printf("MAP: %s\n", map_name);
		free(map_path);
		return ;
	}
	map = get_map(map_path, map_size);
	if (map != NULL)
	{
		ft_printf("The map is valid! (%s)\n", map_name);
		free_map(map);
	}
	else
		ft_printf("MAP: %s\n", map_name);
	free(map_path);
}

static char	*get_map_path(char *map_name)
{
	char	*map_dir;
	char	*map_path;

	map_dir = ft_strdup("./resources/maps/");
	map_path = ft_strjoin(map_dir, map_name);
	free(map_dir);
	return (map_path);
}
