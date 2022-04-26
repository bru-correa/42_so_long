/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:07:50 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/26 14:53:19 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "so_long.h"
#include <stdio.h>

void	test_map_validation(char *map_name);
void	test_count_file_lines(char *map_name);
char	*create_map_path(char *map_name);

int	main(void)
{
	test_count_file_lines("wrong/wrong_shape.ber");
	test_count_file_lines("default.ber");
	// test_map_validation("default.ber");
	// test_map_validation("wrong/wrong_shape.ber");
	return (0);
}

char	*create_map_path(char *map_name)
{
	char	*map_dir;
	char	*map_path;

	map_dir = ft_strdup("./resources/maps/");
	map_path = ft_strjoin(map_dir, map_name);
	free(map_dir);
	return (map_path);
}

void	test_count_file_lines(char *map_name)
{
	char	*map_path;
	int		line_count;

	map_path = create_map_path(map_name);
	line_count = count_file_lines(map_path);
	ft_printf("Lines: %d\n", line_count);
	free(map_path);
}

void	test_map_validation(char *map_name)
{
	char	*map_path;
	char	**map;

	map_path = create_map_path(map_name);
	map = create_map(map_path);
	free(map_path);
	free(map);
}
