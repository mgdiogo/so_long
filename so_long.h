/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:18:14 by sark              #+#    #+#             */
/*   Updated: 2023/04/05 22:16:54 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define PLAYER_SIZE 44
# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct  s_win
{
    void    *mlx;
    void    *mlx_win;
    int     x;
    int     y;
    int     width;
    int     height;
}   t_win;

typedef struct  s_map
{
    char    **map;
    void    *wall;
    void    *background;
    void    *player;
    int     p_x;
    int     p_y;
}   t_map;

t_win   *mlx_win(void);

t_map   *mlx_map(void);

int     eventos(int keycode);

int    read_map(char *filename);

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);

char	*ft_strjoin(char *s1, char *buf);

int	clear_ln(char *buf);

char	*free_gnl(char *gnl);

int    check_map(char *filename);

void    build_map(void);

#endif