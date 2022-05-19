/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blend_imgs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 01:50:05 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/19 04:25:53 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_img_data	get_img_data(void *img_ptr);
static t_img_data	merge_pixels(t_img_data img_front, t_img_data img_back);
static void	put_pixel(t_img_data *img_front, t_img_data *img_back,
		t_vector2d position);

/* Remember, you navigate one byte at time, not one pixel */
void	*blend_imgs(void *img_front_ptr, void *img_back_ptr)
{
	t_img_data	img_front;
	t_img_data	img_back;
	t_img_data	img_new;

	img_front = get_img_data(img_front_ptr);
	img_back = get_img_data(img_back_ptr);
	img_new = merge_pixels(img_front, img_back);
	return (img_new.ptr);
}

static t_img_data	get_img_data(void *img_ptr)
{
	t_img_data	img_data;

	img_data.ptr = img_ptr;
	img_data.pixels = mlx_get_data_addr(img_data.ptr,
			&img_data.bits_per_pixel, &img_data.line_size, img_data.endian);
	return (img_data);
}

static t_img_data	merge_pixels(t_img_data img_front, t_img_data img_back)
{
	t_vector2d	position;
	char		*current_pixel_front;
	char		*current_pixel_back;

	position.y = 0;
	while (position.y < TILE_SIZE)
	{
		position.x = 0;
		while (position.x < TILE_SIZE)
		{
			put_pixel(&img_front, &img_back, position);
			position.x = (position.x + 1) * (img_front.bits_per_pixel / 8);
		}
		position.y = (position.y + 1) * img_front.line_size;
	}
	return (img_front);
}

static void	put_pixel(t_img_data *img_front, t_img_data *img_back,
		t_vector2d position)
{
	char	*current_pixel_front;
	char	*current_pixel_back;

	current_pixel_front = img_front->pixels + position.y + position.x;
	current_pixel_back = img_back->pixels + position.y + position.x;
	if (*current_pixel_front == ' ')
		*(int *)current_pixel_front = *(int *)current_pixel_back;
}
