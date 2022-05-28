/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_animation_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 00:01:56 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/29 00:09:21 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	increase_anim_counter(t_game *game);

void	set_animation(t_game *game)
{
	static int	anim_delay = 0;

	if (anim_delay < ANIM_DELAY)
	{
		anim_delay++;
		return ;
	}
	else if (anim_delay == ANIM_DELAY)
	{
		increase_anim_counter(game);
		anim_delay = 0;
	}
}

static void	increase_anim_counter(t_game *game)
{
	if (game->anim_counter < 2)
		game->anim_counter++;
	else
		game->anim_counter = 0;
}
