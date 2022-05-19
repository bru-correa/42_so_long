/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_objs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:00:35 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/17 21:42:39 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid_map.h"

static int	is_map_char_valid(char c);
static int	get_char_count(char **map, char c, t_vector2d map_size);

int	is_map_chars_valid(char **map, t_vector2d map_size)
{
	t_vector2d	position;
	char		current_char;

	position.y = 0;
	while (position.y < map_size.y)
	{
		position.x = 0;
		while (position.x < map_size.x)
		{
			current_char = map[position.y][position.x];
			if (is_map_char_valid(current_char) == FALSE)
				return (FALSE);
			position.x++;
		}
		position.y++;
	}
	return (TRUE);
}

int	is_map_objs_count_valid(char **map, t_vector2d map_size)
{
	if (get_char_count(map, 'P', map_size) != 1)
	{
		ft_printf("Error\nThe map must have one player!\n");
		return (FALSE);
	}
	else if (get_char_count(map, 'C', map_size) <= 0)
	{
		ft_printf("Error\nThe map must have at least one collectible!\n");
		return (FALSE);
	}
	else if (get_char_count(map, 'E', map_size) != 1)
	{
		ft_printf("Error\nThe map must have one exit!\n");
		return (FALSE);
	}
	return (TRUE);
}

static int	is_map_char_valid(char c)
{
	if (ft_is_char_valid(c, "PEC10") == FALSE)
	{
		ft_printf("Error\nThe map has an invalid character\n");
		return (FALSE);
	}
	return (TRUE);
}

static int	get_char_count(char **map, char c, t_vector2d map_size)
{
	t_vector2d	position;
	char		current_char;
	int			counter;

	position.y = 0;
	counter = 0;
	while (position.y < map_size.y)
	{
		position.x = 0;
		while (position.x < map_size.x)
		{
			current_char = map[position.y][position.x];
			if (current_char == c)
				counter++;
			position.x++;
		}
		position.y++;
	}
	return (counter);
}
