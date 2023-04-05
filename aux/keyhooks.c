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

/*
W = 119
S = 115
A = 97
D = 100

LEMBRAR DE DAR REPLACE DE 44 POR PLAYER_SIZE

*/

int eventos(int keycode)
{
    
    if (keycode == 97)
        mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->player, mlx_map()->p_x - 44, mlx_map()->p_y);
    if (keycode == 100)
        mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->player, mlx_map()->p_x + 44, mlx_map()->p_y);
    if (keycode == 119)
        mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->player, mlx_map()->p_x, mlx_map()->p_y - 44);
    if (keycode == 115)
        mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win, mlx_map()->player, mlx_map()->p_x, mlx_map()->p_y + 44);
    if (keycode == 65307)
    {
        mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
        exit(0);
    }
    return (0);
}