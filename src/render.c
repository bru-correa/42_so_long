/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:37:51 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/05 17:20:46 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	render(t_game *game)
{
	if (game->win_ptr == NULL)
		return (ERROR);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->player.img_ptr,
		game->player.position.x, game->player.position.y);
	return (0);
}

/* TODO Document this function */
void	*create_img_ptr(t_game *game, char *relative_path)
{
	void	*img;
	// char	*file_path;
	int		width;
	int		height;

	width = SPRITE_SIZE;
	height = SPRITE_SIZE;
	// file_path = ft_strjoin("resources/sprites/", relative_path);
	img = mlx_xpm_file_to_image(game->mlx_ptr, relative_path, &width, &height);
	// free(file_path);
	if (img == NULL)
		ft_printf("Image file not found: %s\n", relative_path);
	return (img);
}
