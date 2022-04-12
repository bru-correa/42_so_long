/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:23:55 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/07 17:46:43 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_d)
		data->input.right = 1;
	if (keysym == XK_a)
		data->input.left = 1;
	if (keysym == XK_s)
		data->input.down = 1;
	if (keysym == XK_w)
		data->input.up = 1;
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_d)
		data->input.right = 0;
	if (keysym == XK_a)
		data->input.left = 0;
	if (keysym == XK_s)
		data->input.down = 0;
	if (keysym == XK_w)
		data->input.up = 0;
	return (0);
}
