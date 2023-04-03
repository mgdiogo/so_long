/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:06:05 by sark              #+#    #+#             */
/*   Updated: 2023/04/03 19:00:22 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int read_map(char *filename)
{
    int     fd;
    int     i;
    int     j;
    char    *gnl;
    
    i = 0;
    j = -1;
    fd = open(filename, O_RDONLY);
    gnl = get_next_line(fd);
    while (gnl)
    {
        i++;
        free(gnl);
        gnl = get_next_line(fd);
    }
    mlx_win()->y = i;
    if (mlx_win()->y < 3)
        return (0);
    if (mlx_win()->y > 0)
    {
        mlx_win()->map = (char **)malloc(sizeof(char *) * (mlx_win()->y + 1));
        if (!mlx_win()->map)
            return (0);
    }
    return (1);
}

int check_map(char *filename)
{
    int     fd;
    int     i;
    int     j;
    
    fd = open(filename, O_RDONLY);
    i = 0;
    j = 0;
    while (1)
    {
        mlx_win()->map[i] = get_next_line(fd);
        if (!mlx_win()->map[i])
            break ;
        i++;
    }
    i = 0;
    j = ft_strlen(mlx_win()->map[i]);
    while (mlx_win()->map && mlx_win()->map[++i])
    {
        if (!mlx_win()->map[i + 1])
            j--;
        if (ft_strlen(mlx_win()->map[i]) != j)
            return (0);
    }
    mlx_win()->x = j;
    return (1);
}