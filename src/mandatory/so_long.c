/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:12:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/05 18:14:08 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

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
	int		i;
	int		j;

	i = 0;
	ft_check_args(ac, av);
	ft_init_struct(&game);
	ft_validate_map(av, &game);
	while (game.map[i] < game.map_y)
	{
		ft_printf("%s\n", game.map[i]);
		i++;
	}
}
