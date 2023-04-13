/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:17 by sark              #+#    #+#             */
/*   Updated: 2023/04/13 19:36:48 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb / 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + '0');
}

void	flood_fill(int i, int j)
{
	if (mlx_map()->map[i][j] == 'E' || mlx_map()->map[i][j] == 'P'
		|| mlx_map()->map[i][j] == 'C' || mlx_map()->map[i][j] == '0')
	{
		if (mlx_map()->map[i][j] == 'C')
		{
			mlx_map()->c_c++;
			mlx_map()->map[i][j] = 'c';
		}
		else if (mlx_map()->map[i][j] == 'P')
			mlx_map()->map[i][j] = 'o';
		else if (mlx_map()->map[i][j] == 'E')
		{
			mlx_map()->s_e++;
			mlx_map()->map[i][j] = 'e';
		}
		else if (mlx_map()->map[i][j] == '0')
			mlx_map()->map[i][j] = 'o';
		flood_fill(i + 1, j);
		flood_fill(i - 1, j);
		flood_fill(i, j + 1);
		flood_fill(i, j - 1);
	}
}

int	flood_check(void)
{
	flood_fill(mlx_map()->p_y, mlx_map()->p_x);
	if (mlx_map()->c_c != mlx_map()->c_count
		|| mlx_map()->s_e != mlx_map()->b_e)
		return (0);
	return (1);
}
