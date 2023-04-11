/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:18:14 by sark              #+#    #+#             */
/*   Updated: 2023/04/11 15:49:42 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PLAYER_SIZE 44
# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		width;
	int		height;
}			t_win;

typedef struct s_map
{
	char	**map;
	void	*wall;
	void	*background;
	void	*player;
	void	*c_img;
	int		c_count;
	int		p_x;
	int		p_y;
}			t_map;

t_win		*mlx_win(void);

t_map		*mlx_map(void);

int			eventos(int keycode);

int			map_y(char *filename);

char		*get_next_line(int fd);

size_t		ft_strlen(char *s);

char		*ft_strjoin(char *s1, char *buf);

int			clear_ln(char *buf);

char		*free_gnl(char *gnl);

int			map_x(char *filename);

void		build_map(void);

void		set_player(void);

void		walk_right(void);

void		walk_left(void);

void		walk_up(void);

void		walk_down(void);

void		count_collectibles(void);

#endif