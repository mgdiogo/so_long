/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:11:45 by sark              #+#    #+#             */
/*   Updated: 2023/03/29 18:33:06 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	mlx_win()->mlx = mlx_init();
	mlx_win()->mlx_win = mlx_new_window(mlx_win()->mlx, 184, 184, "Hello world!");
	mlx_hook(mlx_win()->mlx_win, 2, 1L<<0, eventos, mlx_win());
	read_map("./maps/map.ber");

	/*printf("Quantidade de linhas: %i\n", mlx_win()->y);*/
	
	mlx_loop(mlx_win()->mlx);
}
