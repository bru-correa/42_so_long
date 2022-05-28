/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_coin_assets_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 23:09:12 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 23:36:50 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "assets_bonus.h"

void	load_coin_assets(t_game *game)
{
	game->assets.coin_imgs = malloc(COIN_FRAMES * sizeof(void *));
	game->assets.coin_imgs[0] = create_img_ptr(game, COIN0_PATH);
	game->assets.coin_imgs[1] = create_img_ptr(game, COIN1_PATH);
	game->assets.coin_imgs[2] = create_img_ptr(game, COIN2_PATH);
}

void	destroy_coin_imgs(t_game *game)
{
	int	i;

	i = 0;
	while (i < COIN_FRAMES)
	{
		mlx_destroy_image(game->mlx_ptr, game->assets.coin_imgs[i]);
		i++;
	}
	free(game->assets.coin_imgs);
}

int	check_coin_imgs(void **coins)
{
	int	i;

	i = 0;
	while (i < COIN_FRAMES)
	{
		if (coins[i] == NULL)
			return (ERROR);
		i++;
	}
	return (0);
}
