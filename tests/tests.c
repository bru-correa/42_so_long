/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:07:50 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/02 17:02:07 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <stdio.h>
#include <fcntl.h>

void	test_map_validation(char *map_name);
char	*get_tilemap_path(char *map_name);

int	main(void)
{
	test_map_validation("default.ber");
	test_map_validation("wrong/wrong_shape.ber");
	test_map_validation("wrong/invalid_char_01.ber");
	test_map_validation("wrong/invalid_char_02.ber");
	test_map_validation("wrong/invalid_collectible.ber");
	test_map_validation("wrong/invalid_exit.ber");
	test_map_validation("wrong/invalid_player.ber");
	test_map_validation("wrong/empty_map.ber");
	return (0);
}

char	*get_tilemap_path(char *map_name)
{
	char	*tilemap_dir;
	char	*tilemap_path;

	tilemap_dir = ft_strdup("./resources/maps/");
	tilemap_path = ft_strjoin(tilemap_dir, map_name);
	free(tilemap_dir);
	return (tilemap_path);
}

void	test_map_validation(char *map_name)
{
	char	*tilemap_path;
	t_map	map;

	tilemap_path = get_tilemap_path(map_name);
	map = get_map(tilemap_path);
	if (map.tilemap != NULL)
	{
		ft_printf("The map is valid! (%s)\n", map_name);
		free_tilemap(map.tilemap);
	}
	else
		ft_printf("MAP: %s\n", map_name);
	free(tilemap_path);
}
