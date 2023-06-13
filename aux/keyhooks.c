/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:37:25 by sark              #+#    #+#             */
/*   Updated: 2023/06/13 14:08:52 by mpedroso         ###   ########.fr       */
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
		free_memory();
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
		free_memory();
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
		free_memory();
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
		free_memory();
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
		set_player();
	}
	if (keycode == 65307)
		free_memory();
	return (0);
}
