/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_limits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:36:14 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/16 17:56:26 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_check_x_limits(t_game *game)
{
	while ((game->x) < (game->map_x))
	{
		if (game->map[0][game->x] != '1')
			ft_limits_error();
		game->x++;
	}
	game->y = game->map_y - 1;
	game->x = 0;
	while ((game->x) < (game->map_x))
	{
		if (game->map[game->y][game->x] != '1')
			ft_limits_error();
		game->x++;
	}
}

void	ft_check_y_limits(t_game *game)
{
	game->x = 0;
	game->y = 0;
	while ((game->y) < (game->map_y))
	{
		if (game->map[game->y][0] != '1')
			ft_limits_error();
		game->y++;
	}
	game->y = 0;
	game->x = game->map_x - 1;
	while ((game->y) < (game->map_y))
	{
		if (game->map[game->y][game->x] != '1')
			ft_limits_error();
		game->y++;
	}
}

void	ft_limits_error(void)
{
	ft_printf("Error\nlimiti della mappa non corretti.\n");
	ft_printf("hai controllato che ci siano '1' nei bordi della mappa?");
	exit(1);
}
