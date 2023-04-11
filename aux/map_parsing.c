/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:06:05 by sark              #+#    #+#             */
/*   Updated: 2023/04/11 15:23:31 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//Talvez substituir o x e o y?

int	map_y(char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*gnl;

	i = 0;
	j = -1;
	fd = open(filename, O_RDONLY);
	gnl = get_next_line(fd);
	while (gnl)
	{
		i++;
		free(gnl);
		gnl = get_next_line(fd);
	}
	mlx_win()->y = i;
	if (mlx_win()->y < 3)
		return (0);
	if (mlx_win()->y > 0)
	{
		mlx_map()->map = (char **)malloc(sizeof(char *) * (mlx_win()->y + 1));
		if (!mlx_map()->map)
			return (0);
	}
	return (1);
}

int	map_x(char *filename)
{
	int	fd;
	int	i;
	int	j;

	fd = open(filename, O_RDONLY);
	i = 0;
	j = 0;
	while (1)
	{
		mlx_map()->map[i] = get_next_line(fd);
		if (!mlx_map()->map[i])
			break ;
		i++;
	}
	i = 0;
	j = ft_strlen(mlx_map()->map[i]);
	while (mlx_map()->map && mlx_map()->map[++i])
	{
		if (!mlx_map()->map[i + 1])
			j--;
		if (ft_strlen(mlx_map()->map[i]) != j)
			return (0);
	}
	mlx_win()->x = j;
	return (1);
}

void	count_collectibles(void)
{
	int	i;
	int	j;

	i = 0;
	while (mlx_map()->map && mlx_map()->map[i])
	{
		j = 0;
		while (mlx_map()->map && mlx_map()->map[i][j])
		{
			if (mlx_map()->map[i][j] == 'C')
				mlx_map()->c_count++;
			j++;
		}
		i++;
	}
}