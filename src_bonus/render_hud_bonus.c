/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_hud_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:48:01 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/28 22:58:16 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// static char	*get_score_str(int player_steps);

void	render_hud(t_game *game)
{
	char	*score_str;

	score_str = ft_itoa(game->player.steps);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->assets.score_img, 16, 8);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 28, 0xf8c820, score_str);
	free(score_str);
}

// static char	*get_score_str(int player_steps)
// {
// 	char	*score_str;

// 	score_str = ft_itoa(player_steps);
// 	return (score_str);
// }
