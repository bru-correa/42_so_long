/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_blend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:05:58 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/23 22:40:34 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include "render_tile.h"

static void	test_blend_imgs(t_game *game);
static void	print_image_xpm(void *img_ptr);

int	test_blend(void)
{
	t_game	game;
	int		status;

	status = create_game_data(&game, "resources/maps/default.ber");
	if (status == ERROR)
	{
		ft_printf("ERROR: Could not create game data!\n");
		return (ERROR);
	}
	test_blend_imgs(&game);
	free_game_data(&game);
	return (0);
}

static void	test_blend_imgs(t_game *game)
{
	void		*result_img;
	t_vector2d	position;

	result_img = blend_imgs(game->assets.player_img, game->assets.floor_img);
	position.x = 0;
	position.y = 0;
	render_img(game, result_img, position);
	print_image_xpm(result_img);
}

static void	print_image_xpm(void *img_ptr)
{
	t_img_data	img_data;

	img_data.pixels = mlx_get_data_addr(img_ptr, &img_data.bits_per_pixel,
			&img_data.line_size, &img_data.endian);
	ft_printf("%s\n", img_data.pixels);
}
