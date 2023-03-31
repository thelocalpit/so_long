/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:12:58 by pfalasch          #+#    #+#             */
/*   Updated: 2023/03/31 16:32:36 by pfalasch         ###   ########.fr       */
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


int	ft_check(char *line)
{
	int i;

	if (!line)
		return (0);
	while (line[i])
	{
		if 
}

/* questa funzione faccio uso di gnl per ottenere la mappa. Quindi, n. di righe
	e controllo la lunghezza della [0]. deve corrispondere la medesima
	lunghezza per tutte quante.
	 */
char	*ft_get_map(int fd)
{
	char buffer;
	char *line;
	int rd_bytes;

	rd_bytes = 1;
	if (fd < 0)
		line = NULL;
	line = malloc(1);
	line[0] = '\0';
	/* questo ciclo mi serve per leggere ogni carattere del file della mappa.
		alloco la malloc a 1, come se leggessi carattere per carattere e poi
		aggiungessi a una stringa successivamente.  */
	while ()
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