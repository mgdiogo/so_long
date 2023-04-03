/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:18:14 by sark              #+#    #+#             */
/*   Updated: 2023/04/03 18:58:43 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./mlx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct  s_win
{
    void    *mlx;
    void    *mlx_win;
    char    **map;
    int     x;
    int     y;
}   t_win;

t_win   *mlx_win(void);

int     eventos(int keycode);

int    read_map(char *filename);

char	*get_next_line(int fd);

size_t	ft_strlen(char *s);

char	*ft_strjoin(char *s1, char *buf);

int	clear_ln(char *buf);

char	*free_gnl(char *gnl);

int    check_map(char *filename);

#endif