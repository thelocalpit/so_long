/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:14:06 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/16 20:11:37 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_move_up(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y - 1][game->player_x] = 'P';
	game->player_mov++;
	game->player_dir = "./img/up.xpm";
	ft_fill_window(game);
}

void	ft_move_down(t_game	*game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y + 1][game->player_x] = 'P';
	game->player_mov++;
	game->player_dir = "./img/down.xpm";
	ft_fill_window(game);
}

void	ft_move_left(t_game	*game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x - 1] = 'P';
	game->player_mov++;
	game->player_dir = "./img/left.xpm";
	ft_fill_window(game);
}

void	ft_move_right(t_game *game)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[game->player_y][game->player_x + 1] = 'P';
	game->player_mov++;
	game->player_dir = "./img/right.xpm";
	ft_fill_window(game);
}

int	ft_keyboard(int keyhook, t_game *game)
{
	if (keyhook == 53)
		ft_close_window(game);
	if ((game->count_collectible - game->collect == 0)
		&& ((keyhook == 2 && game->map[game->player_y][game->player_x + 1] == 'E')
		|| (keyhook == 1 && game->map[game->player_y + 1][game->player_x] == 'E')
		|| (keyhook == 0 && game->map[game->player_y][game->player_x - 1] == 'E')
		|| (keyhook == 13 && game->map[game->player_y - 1][game->player_x] == 'E')))
	{
		ft_printf("gioco finito!\n");
		ft_close_window(game);
	}
	if (keyhook == 13 && game->map[game->player_y - 1][game->player_x] != '1'
		&& game->map[game->player_y - 1][game->player_x] != 'E')
		ft_move_up(game);
	if (keyhook == 0 && game->map[game->player_y][game->player_x - 1] != '1'
		&& game->map[game->player_y][game->player_x - 1] != 'E')
		ft_move_left(game);
	if (keyhook == 1 && game->map[game->player_y + 1][game->player_x] != '1'
		&& game->map[game->player_y + 1][game->player_x] != 'E')
		ft_move_down(game);
	if (keyhook == 2 && game->map[game->player_y][game->player_x + 1] != '1'
		&& game->map[game->player_y][game->player_x + 1] != 'E')
		ft_move_right(game);
	return (0);
}
