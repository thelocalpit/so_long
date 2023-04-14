/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:24:10 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/15 00:26:19 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/so_long.h"

void	ft_check_pce(char *buffer, t_game *game)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == 'P')
			game->player++;
		if (buffer[i] == 'C')
			game->collect++;
		if (buffer[i] == 'E')
			game->exit++;
		i++;
	}
	if (game->player != 1 || game->collect < 1 || game->exit != 1)
	{
		ft_printf("Error\n");
		ft_printf("Numero di giocatori, collectibles o uscite sbagliato !!");
		exit(1);
	}
}

char	*ft_join(char *line, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i])
		i++;
	str = malloc(i + 2);
	i = 0;
	while (line[i])
	{
		str[i] = line[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(line);
	return (str);
}



void	ft_check_map(char *buffer, t_game *game)
{
	int	i;

	i = - 1;
	while (game->map[0][++i] != '\0')
		game->map_x++;
	i = -1;
	while (buffer[++i])
	{
		if (buffer[i] == '\n')
			game->map_y++;
	}
	game->map_y++;
	// ft_printf("%s\n", buffer);
	game->map_area = ft_strlen(buffer) - game->map_y + 1;
	// ft_printf("map_area: %d;\tmap_x * map_y = %d\n", game->map_area, (game->map_x * game->map_y));
	// ft_printf("map_x: %d\n", game->map_x);
	// ft_printf("map_y: %d\n", game->map_y);
	
	if (game->map_area != game->map_x * game->map_y)
	{
		ft_printf("errror\nLa mappa ha un layout errato\n");
		exit(1);
	}
	ft_check_x_limits(game);
	ft_check_y_limits(game);
}

int	ft_check(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (line[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_get_map(int fd)
{
	char	character;
	char	*line;
	int		rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
	{
		line = NULL;
		return (line);
	}
	line = malloc(1);
	line[0] = '\0';
	while (!ft_check(line) && rd_bytes > 0)
	{
		rd_bytes = read(fd, &character, 1);
		if ((rd_bytes == 0 && line[0] == '\0') || rd_bytes < 0)
		{
			free(line);
			return (NULL);
		}
		if (rd_bytes == 0 && line[0] != '\0')
			return (line);
		line = ft_join(line, character);
	}
	return (line);
}
