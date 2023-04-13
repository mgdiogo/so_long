/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:37:25 by sark              #+#    #+#             */
/*   Updated: 2023/04/13 19:42:16 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	walk_left(void)
{
	if (mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x - 1] == '1')
		return ;
	else if (mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x - 1] == 'c')
	{
		mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x - 1] = 'o';
		mlx_map()->c_count--;
	}
	else if (mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x - 1] == 'e'
	&& mlx_map()->c_count == 0)
	{
		ft_putstr("The end\n");
		mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
		exit(0);
	}
	mlx_map()->p_x -= 1;
	mlx_map()->p_moves++;
	ft_putnbr(mlx_map()->p_moves);
	ft_putstr(" move(s)\n");
}

void	walk_right(void)
{
	if (mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x + 1] == '1')
		return ;
	else if (mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x + 1] == 'c')
	{
		mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x + 1] = 'o';
		mlx_map()->c_count--;
	}
	else if (mlx_map()->map[mlx_map()->p_y][mlx_map()->p_x + 1] == 'e'
	&& mlx_map()->c_count == 0)
	{
		ft_putstr("The end\n");
		mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
		exit(0);
	}
	mlx_map()->p_x += 1;
	mlx_map()->p_moves++;
	ft_putnbr(mlx_map()->p_moves);
	ft_putstr(" move(s)\n");
}

void	walk_up(void)
{
	if (mlx_map()->map[mlx_map()->p_y - 1][mlx_map()->p_x] == '1')
		return ;
	else if (mlx_map()->map[mlx_map()->p_y - 1][mlx_map()->p_x] == 'c')
	{
		mlx_map()->map[mlx_map()->p_y - 1][mlx_map()->p_x] = 'o';
		mlx_map()->c_count--;
	}
	else if (mlx_map()->map[mlx_map()->p_y - 1][mlx_map()->p_x] == 'e'
	&& mlx_map()->c_count == 0)
	{
		ft_putstr("The end\n");
		mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
		exit(0);
	}
	mlx_map()->p_y -= 1;
	mlx_map()->p_moves++;
	ft_putnbr(mlx_map()->p_moves);
	ft_putstr(" move(s)\n");
}

void	walk_down(void)
{
	if (mlx_map()->map[mlx_map()->p_y + 1][mlx_map()->p_x] == '1')
		return ;
	else if (mlx_map()->map[mlx_map()->p_y + 1][mlx_map()->p_x] == 'c')
	{
		mlx_map()->map[mlx_map()->p_y + 1][mlx_map()->p_x] = 'o';
		mlx_map()->c_count--;
	}
	else if (mlx_map()->map[mlx_map()->p_y + 1][mlx_map()->p_x] == 'e'
	&& mlx_map()->c_count == 0)
	{
		ft_putstr("The end\n");
		mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
		exit(0);
	}
	mlx_map()->p_y += 1;
	mlx_map()->p_moves++;
	ft_putnbr(mlx_map()->p_moves);
	ft_putstr(" move(s)\n");
}

int	eventos(int keycode)
{
	if (keycode == 97 || keycode == 65361 || keycode == 100 || keycode == 65363
		|| keycode == 119 || keycode == 65362 || keycode == 115
		|| keycode == 65364)
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
		mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
			mlx_map()->player, mlx_map()->p_x * PLAYER_SIZE, mlx_map()->p_y
			* PLAYER_SIZE);
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
		printf("Moves: %i\n", mlx_map()->p_moves);
		exit(0);
	}
	return (0);
}
