/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:35:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/05 20:06:33 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int			create_game_data(t_game *game, char *tilemap_path);
// static t_game_obj	create_game_objs(t_game game);
static t_game_obj	create_player(t_game *game);
static void			enter_game_loop(t_game *game);

/* HACK Added player just for testing */
int	main(int argc, char *argv[])
{
	t_game	game;
	int		error_code;

	if (argc != 2)
	{
		ft_printf("Error\nYou must pass the map path as argument");
		return (ERROR);
	}
	error_code = create_game_data(&game, argv[1]);
	if (error_code == ERROR)
		return (ERROR);
	enter_game_loop(&game);
	return (0);
}

/* HACK Just freeing tilemap here to not leak memory for testing */
static int	create_game_data(t_game *game, char *tilemap_path)
{
	t_map	map;

	map = get_map(tilemap_path);
	if (map.tilemap == NULL)
		return (ERROR);
	free_tilemap(map.tilemap);
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (ERROR);
	game->win_ptr = mlx_new_window(game->mlx_ptr, map.width * SPRITE_SIZE,
			map.height * SPRITE_SIZE, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->win_ptr);
		return (ERROR);
	}
	game->player = create_player(game);
	game->steps = 0;
	game->input = init_input();
	return (0);
}

static t_game_obj	create_player(t_game *game)
{
	t_game_obj	player;

	player.position.x = 0;
	player.position.y = 0;
	player.img_ptr = create_img_ptr(game,
			"./resources/sprites/player/link_front_0.xpm");
	player.tag = Player;
	return (player);
}

/* HACK Just testing with one game object */
// static t_game_obj	create_game_objs(t_game game)
// {
// 	game.player.x = 0;
// 	game.player.y = 0;
// 	game.player.img_ptr = create_img_ptr(game,
		// "resources/sprites/player/hero1.xpm");
// }

static void	enter_game_loop(t_game *game)
{
	mlx_loop_hook(game->mlx_ptr, &update, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease,
		game);
	mlx_loop(game->mlx_ptr);
}
