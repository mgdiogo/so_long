/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:11:45 by sark              #+#    #+#             */
/*   Updated: 2023/04/03 19:20:31 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "Argumentos invalidos\n", 22);
		return (0);
	}
	mlx_win()->mlx = mlx_init();
	if (!read_map(argv[1]) || !check_map(argv[1]))
	{
		write(1, "Mapa invalido\n", 14);
		return (0);
	}
	mlx_win()->mlx_win = mlx_new_window(mlx_win()->mlx, 32 * mlx_win()->x, 32 * mlx_win()->y, "tifu");
	mlx_hook(mlx_win()->mlx_win, 2, 1L<<0, eventos, mlx_win());

	/*printf("Quantidade de linhas: %i\n", mlx_win()->y);
	printf("Quantidade de colunas: %i\n", mlx_win()->x);*/
	
	mlx_loop(mlx_win()->mlx);
}
