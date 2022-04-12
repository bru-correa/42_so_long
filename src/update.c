/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:21:21 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/12 19:36:40 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_direction(t_data *data);

// int	update(t_data *data)
// {
// 	static int	frame_counter = 0;

// 	if (data->player.position.x <= WINDOW_WIDTH - SPRITE_SIZE
// 		&& data->player.position.y <= WINDOW_HEIGHT - SPRITE_SIZE)
// 	{
// 		if (frame_counter == FRAME_DELAY)
// 		{
// 			data->player.position.x += data->input.direction.x;
// 			data->player.position.y += data->input.direction.y;
// 			ft_printf("Player Moved");
// 			frame_counter = 0;
// 			render(data);
// 		}
// 		else
// 			frame_counter++;
// 	}
// 	return (0);
// }

int	update(t_data *data)
{
	static int	frame_counter = 0;

	if (frame_counter == FRAME_DELAY)
	{
		update_player_direction(data);
		data->player.position.x += data->input.direction.x * 2;
		data->player.position.y += data->input.direction.y * 2;
		render(data);
		frame_counter = 0;
	}
	frame_counter++;
	return (0);
}

static void	update_player_direction(t_data *data)
{
	if (data->input.right == 1)
		data->input.direction.x = 1;
	else if (data->input.left == 1)
		data->input.direction.x = -1;
	else
		data->input.direction.x = 0;
	if (data->input.down == 1)
		data->input.direction.y = 1;
	else if (data->input.up == 1)
		data->input.direction.y = -1;
	else
		data->input.direction.y = 0;
}
