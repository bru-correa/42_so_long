/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii_art_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 02:02:42 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/31 03:46:27 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "so_long_bonus.h"
#include "assets_bonus.h"

static void	print_ascii_art(char *relative_path);

void	print_win_msg(void)
{
	ft_printf("\033[32;5m");
	print_ascii_art(WIN_MSG);
	ft_printf("\033[0m");
}

void	print_game_over_msg(void)
{
	ft_printf("\033[31;5m");
	print_ascii_art(GAME_OVER_MSG);
	ft_printf("\033[0m");
}

static void	print_ascii_art(char *relative_path)
{
	int		fd;
	char	*line;

	fd = open(relative_path, O_RDONLY);
	if (fd < 0)
		return ;
	line = ft_get_next_line(fd);
	while (line != NULL)
	{
		ft_printf("%s", line);
		free(line);
		line = ft_get_next_line(fd);
	}
	close(fd);
}
