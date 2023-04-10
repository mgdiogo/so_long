/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:37:25 by sark              #+#    #+#             */
/*   Updated: 2023/04/05 22:17:12 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int eventos(int keycode)
{
    if (keycode == 97 || keycode == 65361 || keycode == 100 || keycode == 65363 || keycode == 119 || keycode == 65362 || keycode == 115 || keycode == 65364)
    {
        if (keycode == 97 || keycode == 65361 && (mlx_map()->p_x - 1 > PLAYER_SIZE))
            mlx_map()->p_x -= PLAYER_SIZE;
        if (keycode == 100 || keycode == 65363 && (mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x + 1] != '1'))
            mlx_map()->p_x += PLAYER_SIZE;
        if (keycode == 119 || keycode == 65362 && (mlx_map()->map[mlx_map()->p_y - 1][mlx_map()->p_x] != '1'))
            mlx_map()->p_y -= PLAYER_SIZE;
        if (keycode == 115 || keycode == 65364 && (mlx_map()->map[mlx_map()->p_y + 1][mlx_map()->p_x] != '1'))
            mlx_map()->p_y += PLAYER_SIZE;
        build_map();
        mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->player, mlx_map()->p_x, mlx_map()->p_y);
    }
    if (keycode == 65307)
    {
        mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
        exit(0);
    }
    return (0);
}