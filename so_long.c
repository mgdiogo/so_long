/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:11:45 by sark              #+#    #+#             */
/*   Updated: 2023/04/12 16:35:38 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr("Argumentos invalidos\n");
		return (0);
	}
	mlx_win()->mlx = mlx_init();
	if (!map_y(argv[1]) || !map_x(argv[1]) || !verify_walls())
	{
		ft_putstr("Mapa invalido\n");
		return (0);
	}
	
	mlx_win()->height = mlx_win()->y * PLAYER_SIZE;
	mlx_win()->width = mlx_win()->x * PLAYER_SIZE;
	mlx_win()->mlx_win = mlx_new_window(mlx_win()->mlx, mlx_win()->width,
			mlx_win()->height, "so_long");
	mlx_map()->wall = mlx_xpm_file_to_image(mlx_win()->mlx, "./assets/wall.xpm",
			&mlx_win()->x, &mlx_win()->y);
	mlx_map()->background = mlx_xpm_file_to_image(mlx_win()->mlx,
			"./assets/background.xpm", &mlx_win()->x, &mlx_win()->y);
	mlx_map()->player = mlx_xpm_file_to_image(mlx_win()->mlx,
			"./assets/player.xpm", &mlx_win()->x, &mlx_win()->y);
	mlx_map()->c_img = mlx_xpm_file_to_image(mlx_win()->mlx,
			"./assets/collectible.xpm", &mlx_win()->x, &mlx_win()->y);
	mlx_map()->exit = mlx_xpm_file_to_image(mlx_win()->mlx,
			"./assets/exit.xpm", &mlx_win()->x, &mlx_win()->y);
	count_collectibles();
	build_map();
	set_player();
	mlx_hook(mlx_win()->mlx_win, 2, 1L << 0, eventos, mlx_win());
	mlx_loop(mlx_win()->mlx);
}