/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:37:25 by sark              #+#    #+#             */
/*   Updated: 2023/04/10 22:32:23 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    walk_left(void)
{
    
    if (mlx_map()->p_x - PLAYER_SIZE < PLAYER_SIZE)
        return ;
    mlx_map()->p_x -= PLAYER_SIZE;
}
void    walk_right(void)
{
    if (mlx_map()->p_x + PLAYER_SIZE >= mlx_win()->width - PLAYER_SIZE)
        return ;
    mlx_map()->p_x += PLAYER_SIZE;
}

void    walk_up(void)
{
    if (mlx_map()->p_y - PLAYER_SIZE < PLAYER_SIZE)
        return ;
    mlx_map()->p_y -= PLAYER_SIZE;
}

void    walk_down(void)
{
    if (mlx_map()->p_y + PLAYER_SIZE >= mlx_win()->height - PLAYER_SIZE)
        return ;
    mlx_map()->p_y += PLAYER_SIZE;
}

int eventos(int keycode)
{
    if (keycode == 97 || keycode == 65361 || keycode == 100 
    || keycode == 65363 || keycode == 119 || keycode == 65362 || keycode == 115 || keycode == 65364)
    {
        if (keycode == 97 || keycode == 65361)
            walk_left();
        if (keycode == 100 || keycode == 65363)
            walk_right();
        if (keycode == 119 || keycode == 65362)
            walk_up();
        if (keycode == 115 || keycode == 65364)
            walk_down();
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