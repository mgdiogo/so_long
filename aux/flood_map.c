/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:45:22 by sark              #+#    #+#             */
/*   Updated: 2023/04/10 22:05:23 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    build_map(void)
{
    int i;
    int j;

    i = 0;
    while (mlx_map()->map && mlx_map()->map[i])
    {
        j = 0;
        while (mlx_map()->map && mlx_map()->map[i][j])
        {
            if (mlx_map()->map[i][j] == '1')
                mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->wall, j * PLAYER_SIZE, i * PLAYER_SIZE);
            else
                mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->background, j * PLAYER_SIZE, i * PLAYER_SIZE);
            j++;
        }
        i++;
    }
}

void    set_player(void)
{
    int i;
    int j;

    i = 0;
    while (mlx_map()->map && mlx_map()->map[i])
    {
        j = 0;
        while (mlx_map()->map && mlx_map()->map[i][j])
        {
           
            if (mlx_map()->map[i][j] == 'P')
            {
                mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->player, j * PLAYER_SIZE, i * PLAYER_SIZE);
                mlx_map()->p_x = j * PLAYER_SIZE;
                mlx_map()->p_y = i * PLAYER_SIZE;
            }
            j++;
        }
        i++;
    }
}