/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:08:14 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 04:21:11 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "assets_bonus.h"

static void	*create_img_ptr(t_game *game, char *relative_path);
static int	check_assets(t_assets assets);
static void	*create_score_img(t_game *game, char *relative_path);

int	load_assets(t_game *game)
{
	game->assets.floor_img = create_img_ptr(game, FLOOR_PATH);
	game->assets.wall_img = create_img_ptr(game, WALL_PATH);
	game->assets.player_front_img = create_img_ptr(game, PLAYER_FRONT_PATH);
	game->assets.player_back_img = create_img_ptr(game, PLAYER_BACK_PATH);
	game->assets.player_right_img = create_img_ptr(game, PLAYER_RIGHT_PATH);
	game->assets.player_left_img = create_img_ptr(game, PLAYER_LEFT_PATH);
	game->assets.coin_img = create_img_ptr(game, COIN_PATH);
	game->assets.exit_img = create_img_ptr(game, EXIT_PATH);
	game->assets.score_img = create_score_img(game, SCORE_PATH);
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
	mlx_destroy_image(game->mlx_ptr, game->assets.coin_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.exit_img);
	mlx_destroy_image(game->mlx_ptr, game->assets.score_img);
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

static void	*create_score_img(t_game *game, char *relative_path)
{
	t_vector2d	size;
	void		*img;

	size.x = SCORE_W;
	size.y = SCORE_H;
	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &size.x, &size.y);
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
	if (assets.coin_img == NULL)
		return (ERROR);
	if (assets.exit_img == NULL)
		return (ERROR);
	if (assets.score_img == NULL)
		return (ERROR);
	return (0);
}
