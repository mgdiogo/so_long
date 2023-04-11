/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:45:22 by sark              #+#    #+#             */
/*   Updated: 2023/04/11 15:58:00 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	build_map(void)
{
	int	i;
	int	j;

	i = 0;
	while (mlx_map()->map && mlx_map()->map[i])
	{
		j = 0;
		while (mlx_map()->map && mlx_map()->map[i][j])
		{
			if (mlx_map()->map[i][j] == '1')
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->wall, j * PLAYER_SIZE, i * PLAYER_SIZE);
			else if (mlx_map()->map[i][j] == 'C')
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->c_img, j * PLAYER_SIZE, i * PLAYER_SIZE);
			else
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->background, j * PLAYER_SIZE, i
					* PLAYER_SIZE);
			j++;
		}
		i++;
	}
}

void	set_player(void)
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
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->player, j * PLAYER_SIZE, i * PLAYER_SIZE);
				mlx_map()->p_x = j;
				mlx_map()->p_y = i;
			}
			j++;
		}
		i++;
	}
}