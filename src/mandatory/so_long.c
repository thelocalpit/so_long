/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:12:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/03 12:18:18 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* questo file conterrà il main e la chiamata a tutte le funzioni esterne 
	in cui il programma verrà suddiviso. 
	1. main
	2. controllo degli input
	3. inizializzazione delle variabili della struttura
	4. controlli della mappa.
	5. definizione della fienstra di apertura del gioco.
	 */
#include "../../inc/so_long.h"

void	ft_limits_error(void)
{
	ft_printf("Error\nlimiti della mappa non corretti.\n");
	ft_printf("hai controllato che ci siano '1' nei bordi della mappa?");
	exit(1);
}

void	ft_check_map(char *buffer, t_game *game)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			game->map_y++;
		i++;
	}
	game->map_area = ft_strlen(buffer) - game->map_y;
	if (game->map_area != game->map_x * game->map_y)
	{
		ft_printf("errror\nLa mappa ha un layout errato\n");
		exit(1);
	}
	// game->x = game->map_x - 1;
	game->y = game->map_y - 1;
	game->x = 0;
	while (game->x < game->map_x)
	{
		if (game->map[0][game->x] != '1')
			ft_limits_error();
		if (game->map[game->y][game->x] != '1')
			ft_limits_error();
		game->x++;
	}
	game->x = game->map_x - 1;
	game->y = 0;
	while(game->y < game->map_y)
	{
		if (game->map[game->y][0] != '1')
			ft_limits_error();
		if (game->map[game->y][game->x] != '1')
			ft_limits_error();
		game->y++;
	}
}
ft_check_pce(char *buffer, t_game *game)
{
	int i;

	i = 0;
	while(buffer[i])
	{
		if (buffer[i] == 'P')
			game->player++;
		if (buffer[i] == 'C')
			game->collect++;
		if (buffer[i] == 'E')
			game->exit++;
		/* conto anche le righe? */
	}
	if (game->player != 1 || game->collect < 1 || game != 1)
	{
		ft_printf("Error\nNumero di giocatori, collectibles o uscite sbagliato!!");
		exit(1);
	}
}
char	*ft_join(char *line, char c)
{
	int i;
	char *str;

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
/* questa funzione è necessaria per controllare che la linea sia sempre chiusa 
	correttamente con lo '\0'  */
int	ft_check(char *line)
{
	int i;

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


	/* questa funzione faccio uso di gnl per ottenere la mappa. Quindi, n. di righe
		e controllo la lunghezza della [0]. deve corrispondere la medesima
		lunghezza per tutte quante.
		 */
char *ft_get_map(int fd)
{
	char character;
	char *line;
	int rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
	{
		line = NULL;
		/* non sono siuro di dover ritornare line */
		return (line);
	}
	line = malloc(1);
	line[0] = '\0';
	while (!ft_check(line))

		/* questo ciclo mi serve per leggere ogni carattere del file della mappa.
			alloco la malloc a 1, come se leggessi carattere per carattere e poi
			aggiungessi a una stringa successivamente.  */
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
}
/* per validare la mappa devo controllare che i contorni siano tutti 1.
	devo controllare che esistano gli elementi designati per funzionare:
	collectible, protagonista, uscita. 
	rettangolo.
	 */

void	ft_validate_map(char **av, t_game *game)
{
	int		i;
	int		fd;
	char 	*buffer;

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

/* qua inizializziamo le variabili della struct */

void	ft_init_struct(t_game *game)
{
	game->map_x = 0;
	game->map_y = 0;
	game->map_area = 0;
	game->x = 0;
	game->y = 0;
}
/* devo controllare che gli argomenti non siano due e che il formato della mappa
	valido.
	utilizzo la funzione strnstr che mi controlla se una str è presente 
	allínterno di unáltra str  */

void	ft_check_args(int ac, char **av);
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
}