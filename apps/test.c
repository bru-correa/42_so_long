/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:54:22 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/05 16:56:10 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h";

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_player	player;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int height;
	int	color;
}	t_rect;

int	handle_input(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int	render_rect(t_img *img, t_rect rect)
{
	int	row;
	int	column;

	row = rect.y;
	while (row < rect.y + rect.height)
	{
		column = rect.x;
		while (column < rect.x + rect.width)
			img_pix_put(img, column++, row, rect.color);
		row++;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	row;
	int	column;
	while (row < WINDOW_HEIGHT)
	{
		column = 0;
		while (column < WINDOW_WIDTH)
			img_pix_put(img, column++, row, color);
		row++;
	}
}

void	move_player(t_player player)
{
	int	speed;

}

int	render_player(t_data *data)
{
	void		*img;
	char		*relative_path = "./resources/sprites/player/hero1.xpm";
	int			width;
	int			height;
	int			speed;

	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	width = 64;
	height = 64;
	speed = 1;
	// render_background(&data->img, WHITE_PIXEL);
	img = mlx_xpm_file_to_image(data->mlx_ptr, relative_path, &width, &height);
	if (img == NULL)
	{
		ft_printf("Image file not found: %s\n", relative_path);
		return (MLX_ERROR);
	}
	if (data->player.x < WINDOW_WIDTH - width
		&& data->player.y < WINDOW_HEIGHT - height)
	{
		data->player.x += speed;
		data->player.y += speed;
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img,
						  data->player.x, data->player.y);
	}
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (MLX_ERROR);
	// render_background(&data->img, WHITE_PIXEL);
	// render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
	// 	100, 100, GREEN_PIXEL});
	// render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img,
	// 					 0, 0);
	render_player(data);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"My First Window!");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	data.player.x = 0;
	data.player.y = 0;
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp,
	// 							   &data.img.line_len, &data.img.endian);
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
