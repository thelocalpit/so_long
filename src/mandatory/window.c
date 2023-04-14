/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:14:46 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/14 22:05:09 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

int	ft_close_window(t_game	*game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(1);
	return (0);
}

/* per riempire la parte del floor dobbiamo utilizzare due funzioni della
	libreria mlx. la prima è necessaria per pasare il fil xpm (che non sono
	altro che caratteri ascii che ci permettono di raffiguare un'immagine) in
	immagine vera e propria. per fare questo diamo l'indicazione fra gli argomenti
	di dove si trova il file xpm e poi i pxl. siccome facciamo un quadrato, daremo
	pxl due volte.
	la seconda invece serve per mettere l'imamgine appena convertita nella win
	alle giuste "coordinate". il ciclo while scorre come una normale matrice.
	  */
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

void	ft_fill_window(t_game *game)
{
	ft_fill_floor(game);
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
			if (game->map[game->y][game->x] == 'E')
				ft_put_exit(game);
			game->x++;
		}
		game->y++;
	}
	ft_printf("Movements: %d\n", game->player_mov);
}
