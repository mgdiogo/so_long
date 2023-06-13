/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:16:40 by mpedroso          #+#    #+#             */
/*   Updated: 2023/06/12 16:36:13 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	free_memory(void)
{
	mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
	if (mlx_map()->wall)
		mlx_destroy_image(mlx_win()->mlx, mlx_map()->wall);
	if (mlx_map()->background)
		mlx_destroy_image(mlx_win()->mlx, mlx_map()->background);
	if (mlx_map()->player)
		mlx_destroy_image(mlx_win()->mlx, mlx_map()->player);
	if (mlx_map()->c_img)
		mlx_destroy_image(mlx_win()->mlx, mlx_map()->c_img);
	if (mlx_map()->exit)
		mlx_destroy_image(mlx_win()->mlx, mlx_map()->exit);
	free_map();
}

int	close_win(int keycode)
{
	(void)keycode;
	free_memory();
	return (0);
}

void	free_map(void)
{
	int	i;

	i = -1;
	while (mlx_map()->map && mlx_map()->map[++i])
		free(mlx_map()->map[i]);
	if (mlx_map()->map)
		free(mlx_map()->map);
	mlx_destroy_display(mlx_win()->mlx);
	free(mlx_win()->mlx);
	exit (0);
}
