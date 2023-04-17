/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:14:46 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/17 17:40:05 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_close_window(t_game	*game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
	return (0);
}

void	ft_fill_floor(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			game->file = mlx_xpm_file_to_image(game->mlx, "./img/floor.xpm",
					&game->pxl, &game->pxl);
			mlx_put_image_to_window (game->mlx, game->mlx_win, game->file,
				(game->pxl * game->x), (game->pxl * game->y));
			game->x++;
		}
		game->y++;
	}
}

int	ft_count_collectible(char *buffer)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'C')
			count++;
		i++;
	}
	return (count);
}

void	ft_exit_check(t_game *game)
{
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			if (game->map[game->y][game->x] == 'E')
				ft_put_exit(game);
			game->x++;
		}
		game->y++;
	}
}

void	ft_fill_window(t_game *game)
{
	ft_fill_floor(game);
	game->collect = 0;
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		game->x = 0;
		while ((game->x) < (game->map_x))
		{
			if (game->map[game->y][game->x] == '1')
				ft_put_limits(game);
			if (game->map[game->y][game->x] == 'C')
				ft_put_collect(game);
			if (game->map[game->y][game->x] == 'P')
				ft_put_player(game);
			game->x++;
		}
		game->y++;
	}
	ft_exit_check(game);
	ft_printf("Movements: %d\n", game->player_mov);
}
