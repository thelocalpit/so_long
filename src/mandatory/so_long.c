/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:12:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/16 20:05:55 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"
#include <stdio.h>

void	ft_window(t_game	*game)
{
	game->pxl = 50;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx,
			game->pxl * game->map_x,
			game->pxl * game->map_y, "Pokemon Giallo, Anno '99");
	ft_fill_window(game);
}

void	ft_validate_map(char **av, t_game *game)
{
	int		fd;
	char	*buffer;

	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nNon posso leggere la mappa.\n");
		exit(1);
	}
	buffer = ft_get_map(fd);
	ft_check_pce(buffer, game);
	game->collect = ft_count_collectible(buffer);
	game->map = ft_split(buffer, '\n');
	ft_check_map(buffer, game);
	close(fd);
}

void	ft_init_struct(t_game *game)
{
	game->map_x = 0;
	game->map_y = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
	game->pxl = 0;
	game->player = 0;
	game->player_mov = 0;
	game->player_dir = "./img/down.xpm";
	game->player_mov = 0;
	game->count_collectible = 0;
	game->exit = 0;
}

void	ft_check_args(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("error\nNumero di argomenti non valido. devono essere 2. \n");
		exit(0);
	}
	if (!ft_strnstr(av[1], ".ber", ft_strlen(av[1])))
	{
		ft_printf("Error\nArgomento della mappa non valido. √ \"<name>.ber\"\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	ft_check_args(ac, av);
	ft_init_struct(&game);
	ft_validate_map(av, &game);
	ft_window(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, ft_keyboard, &game);
	mlx_hook(game.mlx_win, 17, 1L << 5, ft_close_window, &game);
	// ft_printf("questo è il numero di collectible finale: %d\n", game.collect);
	mlx_loop(game.mlx);
	exit(0);
	return (0);
}

