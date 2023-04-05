/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:12:30 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/05 18:16:52 by pfalasch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/minilibx/mlx.h"
# include "../lib/libft/inc/ft_printf.h"
# include "../lib/libft/inc/libft.h"
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_game {
	char	**map;
	int map_x;
	int map_y;
	int map_area;
	int x;
	int y;
	int player;
	int collect;
	int	exit;
	

} t_game;

void	ft_validate_map(char **av, t_game *game);
void	ft_init_struct(t_game *game);
void	ft_check_args(int ac, char **av);
char	*ft_get_map(int fd);
void	ft_check_map(char *buffer, t_game *game);
void	ft_check_pce(char *buffer, t_game *game);
char	*ft_join(char *line, char c);
int		ft_check(char *line);
void	ft_limits_error(void);
void	t_check_y_limits(t_game *game);
void	ft_check_x_limits(t_game *game);

#endif
