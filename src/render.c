/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:37:51 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/12 15:22:12 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player.img_ptr,
		data->player.position.x, data->player.position.y);
	return (0);
}

/* TODO Document this function */
void	*create_img_ptr(t_data data, char *relative_path)
{
	void	*img;
	// char	*file_path;
	int		width;
	int		height;

	width = SPRITE_SIZE;
	height = SPRITE_SIZE;
	// file_path = ft_strjoin("resources/sprites/", relative_path);
	img = mlx_xpm_file_to_image(data.mlx_ptr, relative_path, &width, &height);
	// free(file_path);
	if (img == NULL)
		ft_printf("Image file not found: %s\n", relative_path);
	return (img);
}
