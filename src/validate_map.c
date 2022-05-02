/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:33:17 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/02 17:35:10 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_map_shape_valid(t_map map);
static int	is_map_chars_valid(t_map map);
static int	is_map_objs_count_valid(t_map map);
int			is_character_valid(char c, char *valid_chars);

int	is_map_valid(t_map map)
{
	if (is_map_shape_valid(map) == FALSE)
		return (FALSE);
	else if (is_map_chars_valid(map) == FALSE)
		return (FALSE);
	else if (is_map_objs_count_valid(map) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	is_map_shape_valid(t_map map)
{
	int	current_row_width;
	int	map_width;
	int	row;

	row = 0;
	map_width = ft_strlen(map.tilemap[row]);
	while (map.tilemap[row] != NULL)
	{
		current_row_width = ft_strlen(map.tilemap[row]);
		if (current_row_width != map_width)
		{
			ft_printf("Error\nThe map must be rectangular!\n");
			return (FALSE);
		}
		row++;
	}
	return (TRUE);
}

int	is_character_valid(char c, char *valid_chars)
{
	int	i;

	i = 0;
	while (valid_chars[i] != 0)
	{
		if (c == valid_chars[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	is_tilemap_char_valid(char c)
{
	if (is_character_valid(c, "PEC10") == FALSE)
	{
		ft_printf("Error\nThe map has an invalid character\n");
		return (FALSE);
	}
	return (TRUE);
}

static int	is_map_objs_count_valid(t_map map)
{
	if (map.player_count != 1)
	{
		ft_printf("Error\nThe map must have one player spawn point\n");
		return (FALSE);
	}
	else if (map.exit_count != 1)
	{
		ft_printf("Error\nThe map must have one exit\n");
		return (FALSE);
	}
	else if (map.collectible_count == 0)
	{
		ft_printf("Error\nThe map must have at least one collectible\n");
		return (FALSE);
	}
	return (TRUE);
}

static int	is_map_chars_valid(t_map map)
{
	int	row;
	int	collumn;

	row = 0;
	while (map.tilemap[row] != NULL)
	{
		collumn = 0;
		while (map.tilemap[row][collumn] != '\n')
		{
			if (map.tilemap[row][collumn] == 'P')
				map.player_count++;
			else if (map.tilemap[row][collumn] == 'E')
				map.exit_count++;
			else if (map.tilemap[row][collumn] == 'C')
				map.collectible_count++;
			else if (is_tilemap_char_valid(map.tilemap[row][collumn]) == FALSE)
				return (FALSE);
			collumn++;
		}
		row++;
	}
	return (TRUE);
}
