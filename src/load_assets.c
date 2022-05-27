/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:08:14 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 00:38:45 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "assets.h"

static void	*create_img_ptr(t_game *game, char *relative_path);
static int	check_assets(t_assets assets);

int	load_assets(t_game *game)
{
	game->assets.floor_img = create_img_ptr(game, FLOOR_PATH);
	game->assets.wall_img = create_img_ptr(game, WALL_PATH);
	game->assets.player_front_img = create_img_ptr(game, PLAYER_FRONT_PATH);
	game->assets.player_back_img = create_img_ptr(game, PLAYER_BACK_PATH);
	game->assets.player_right_img = create_img_ptr(game, PLAYER_RIGHT_PATH);
	game->assets.player_left_img = create_img_ptr(game, PLAYER_LEFT_PATH);
	game->assets.collectible_img = create_img_ptr(game, COLLECTIBLE_PATH);
	game->assets.exit_img = create_img_ptr(game, EXIT_PATH);
	return (check_assets(game->assets));
}

void	free_assets(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->assets.floor_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.wall_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.player_front_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.player_back_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.player_right_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.player_left_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.collectible_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.exit_img);
}

static void	*create_img_ptr(t_game *game, char *relative_path)
{
	void	*img;
	int		width;
	int		height;

	width = TILE_SIZE;
	height = TILE_SIZE;
	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &width, &height);
	if (img == NULL)
		ft_printf("Image file not found: %s\n", relative_path);
	return (img);
}

static int	check_assets(t_assets assets)
{
	if (assets.floor_img == NULL)
		return (ERROR);
	if (assets.wall_img == NULL)
		return (ERROR);
	if (assets.player_front_img == NULL && assets.player_back_img == NULL
		&& assets.player_left_img == NULL && assets.player_right_img == NULL)
		return (ERROR);
	if (assets.collectible_img == NULL)
		return (ERROR);
	if (assets.exit_img == NULL)
		return (ERROR);
	return (0);
}
