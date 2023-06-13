/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:45:22 by sark              #+#    #+#             */
/*   Updated: 2023/06/13 13:42:30 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	build_map(void)
{
	int	i;
	int	j;

	i = -1;
	while (mlx_map()->map && mlx_map()->map[++i])
	{
		j = -1;
		while (mlx_map()->map && mlx_map()->map[i][++j])
		{
			if (mlx_map()->map[i][j] == '1')
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->wall, j * PLAYER_SIZE, i * PLAYER_SIZE);
			else if (mlx_map()->map[i][j] == 'c')
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->c_img, j * PLAYER_SIZE, i * PLAYER_SIZE);
			else if (mlx_map()->c_count == 0 && mlx_map()->map[i][j] == 'e')
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->exit, j * PLAYER_SIZE, i * PLAYER_SIZE);
			else
				mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
					mlx_map()->background, j * PLAYER_SIZE, i
					* PLAYER_SIZE);
		}
	}
}

void	set_player(void)
{
	mlx_put_image_to_window(mlx_win()->mlx, mlx_win()->mlx_win,
		mlx_map()->player, mlx_map()->p_x * PLAYER_SIZE,
		mlx_map()->p_y * PLAYER_SIZE);
}
