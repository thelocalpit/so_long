/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalasch <pfalasch@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:12:30 by pfalasch          #+#    #+#             */
/*   Updated: 2023/04/16 18:08:46 by pfalasch         ###   ########.fr       */
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
	int		map_x;
	int		map_y;
	int		map_area;
	int		x;
	int		y;
	int		player;
	int		player_x;
	int		player_y;
	int		player_mov;
	char	*player_dir;
	int		collect;
	int		exit;
	void	*mlx;
	void	*mlx_win;
	int		pxl;
	int		count_collectible;
	char 	*file;

}				t_game;


//MAP VALIDATION
char	*ft_get_map(int fd);
void	ft_check_map(char *buffer, t_game *game);
void	ft_check_pce(char *buffer, t_game *game);
int		ft_check(char *line);
char	*ft_join(char *line, char c);

//SO_LONG
void	ft_validate_map(char **av, t_game *game);
void	ft_check_args(int ac, char **av);
void	ft_init_struct(t_game *game);
void	ft_window(t_game *game);

//CHECK LIMITS
void	ft_limits_error(void);
void	ft_check_y_limits(t_game *game);
void	ft_check_x_limits(t_game *game);
void	ft_exit_check(t_game *game);

// WINDOW
int		ft_close_window(t_game *game);
void	ft_fill_floor(t_game *game);
int		ft_count_collectible(char *buffer);
void	ft_fill_window(t_game *game);

// WINDOW FILL
void	ft_put_limits(t_game *game);
void	ft_put_floor(t_game *game);
void	ft_put_collect(t_game *game);
void	ft_put_exit(t_game *game);
void	ft_put_player(t_game *game);

// KEYHOOK
void	ft_move_up(t_game *game);
void	ft_move_down(t_game *game);
void	ft_move_left(t_game *game);
void	ft_move_right(t_game *game);
int		ft_keyboard(int keyhook, t_game *game);

#endif
