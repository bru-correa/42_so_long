/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_char_count_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 01:37:30 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 02:29:44 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_char_count(char **map, char c, t_vector2d map_size)
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
