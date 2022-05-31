/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcorrea- <bruuh.cor@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:15:11 by bcorrea-          #+#    #+#             */
/*   Updated: 2022/05/31 20:53:32 by bcorrea-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSETS_BONUS_H
# define ASSETS_BONUS_H

# define FLOOR_PATH "resources/sprites/floor.xpm"
# define WALL_PATH "resources/sprites/wall.xpm"
# define PLAYER_FRONT_PATH "resources/sprites/link_front.xpm"
# define PLAYER_BACK_PATH "resources/sprites/link_back.xpm"
# define PLAYER_RIGHT_PATH "resources/sprites/link_right.xpm"
# define PLAYER_LEFT_PATH "resources/sprites/link_left.xpm"
# define COIN0_PATH "resources/sprites/coin0.xpm"
# define COIN1_PATH "resources/sprites/coin1.xpm"
# define COIN2_PATH "resources/sprites/coin2.xpm"
# define EXIT_CLOSED_PATH "resources/sprites/exit_closed.xpm"
# define EXIT_OPEN_PATH "resources/sprites/exit_open.xpm"
# define SCORE_PATH "resources/sprites/score.xpm"
# define ENEMY_PATH "resources/sprites/enemy.xpm"

# define WIN_MSG "resources/ascii_art/you_win.txt"
# define GAME_OVER_MSG "resources/ascii_art/game_over.txt"

# define SCORE_W 64
# define SCORE_H 32

void	*create_img_ptr(t_game *game, char *relative_path);
void	load_coin_assets(t_game *game);
void	destroy_coin_imgs(t_game *game);
int		check_coin_imgs(void **coins);

#endif
