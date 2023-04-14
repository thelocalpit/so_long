/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:12:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/14 17:04:34 by pfalasch         ###   ########.fr       */
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
	int		i;
	int		fd;
	char	*buffer;

	i = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nNon posso leggere la mappa.\n");
		exit(1);
	}
	buffer = ft_get_map(fd);
	ft_check_pce(buffer, game);
	game->count_collectible = ft_count_collectible(buffer);
	// ft_printf("sono qui1");
	game->map = ft_split(buffer, '\n');
	while (game->map[0][i] != '\0')
	{
		game->map_x++;
		i++;
	}
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
	game->player = 0;
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
/* 	int		i;
	int		j;

	i = 0;
	j = 0; */
	ft_check_args(ac, av);
	// ft_printf("sono qui1");
	ft_init_struct(&game);
	// ft_printf("sono qui2");
	ft_validate_map(av, &game);
	ft_window(&game);
	// ft_printf("sono qui3");
	// write(1, &game.map[0][0], 1);
	exit(0);
	return (0);
	/* while (game.map[i] < game.map[game.map_y - 1])
	{
		j = 0;
		while (game.map[i][j])
		{
			printf("%s", &game.map[i][j]);
			j++;
		}
		i++;
	} */
	/* 	for (int i = 0; i < game.map_y; i++)
		{
			for (int j = 0; j < game.map_x; j++)
			{
				printf("%c", game.map[i][j]);
			}
			printf("\n");
		} */
}
