/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:35:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/04/12 19:29:58 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static t_data		create_game_data(void);
// static t_game_obj	create_game_objs(t_data data);
static t_game_obj	create_player(t_data data);
// static void			enter_game_loop(t_data data);

/* HACK Added player just for testing */
int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"so_long");
	data.player = create_player(data);
	data.input.direction.x = 0;
	data.input.direction.y = 0;
	data.input.right = 0;
	data.input.left = 0;
	data.input.up = 0;
	data.input.down = 0;
	data.input.attack = 0;
	data.steps = 0;
	// data = create_game_data();
	if (data.mlx_ptr == NULL || data.mlx_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	mlx_loop_hook(data.mlx_ptr, &update, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		&data);
	mlx_loop(data.mlx_ptr);
	// enter_game_loop(data);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}

// static t_data	create_game_data(void)
// {
// 	t_data	data;

// 	data.mlx_ptr = mlx_init();
// 	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
// 			"so_long");
// 	data.player = create_player(data);
// 	data.steps = 0;
// 	return (data);
// }

static t_game_obj	create_player(t_data data)
{
	t_game_obj	player;

	player.position.x = 0;
	player.position.y = 0;
	player.img_ptr = create_img_ptr(data, "./resources/sprites/player/hero1.xpm");
	player.tag = Player;
	return (player);
}

/* HACK Just testing with one game object */
// static t_game_obj	create_game_objs(t_data data)
// {
// 	data.player.x = 0;
// 	data.player.y = 0;
// 	data.player.img_ptr = create_img_ptr(data, "resources/sprites/player/hero1.xpm");
// }

// static void	enter_game_loop(t_data data)
// {
// 	mlx_loop_hook(data.mlx_ptr, &update, &data);
// 	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_input, &data);
// 	mlx_loop(data.mlx_ptr);
// }
