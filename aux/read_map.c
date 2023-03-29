/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:06:05 by sark              #+#    #+#             */
/*   Updated: 2023/03/29 18:55:02 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    read_map(char *filename)
{
    int     fd;
    int     i;
    char    *gnl;
    
    i = 0;
    fd = open(filename, O_RDONLY);
    gnl = get_next_line(fd);
    while (gnl)
    {
        i++;
        free(gnl);
        gnl = get_next_line(fd);
    }
    mlx_win()->y = i;

    if (mlx_win()->y > 0)
    {
        mlx_win()->map = malloc(sizeof(char *) * (mlx_win()->y + 1));
        if (!mlx_win()->map)
            return ;
    }
    
}