/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:49:54 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/14 18:46:26 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"


void	ft_put_limits(t_game	*game)
{
	game->file = mlx_xpm_file_to_image(game->mlx, "./img/tree.xpm",
			&game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->file,
		(game->pxl * game->x), (game->pxl * game->y));
}

void	ft_put_floor(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/floor.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->file, game->pxl * game->x, game->pxl * game->y);
}

void	ft_put_collect(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			"./img/pokeball.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->file, game->pxl * game->x, game->pxl * game->y);
	game->collect++;
}

void	ft_put_exit(t_game *game)
{
	if (game->collect == 0)
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./img/exit_open.xpm", &game->pxl, &game->pxl);
	else
		game->file = mlx_xpm_file_to_image(game->mlx,
				"./img/exit_closed.xpm", &game->pxl, &game->pxl);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->file, game->pxl * game->x, game->pxl * game->y);
}

/* come gestire il player?? */
void	ft_put_player(t_game *game)
{
	game->file = mlx_xpm_file_to_image(game->mlx,
			game->player_dir, &game->pxl, &game->pxl);
	game->player_y = game->y;
	game->player_x = game->x;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->file, game->pxl * game->x, game->pxl * game->y);
}