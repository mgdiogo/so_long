/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 18:06:05 by sark              #+#    #+#             */
/*   Updated: 2023/06/13 15:30:18 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	mlx_map()->map = (char **)malloc(sizeof(char *) * (mlx_win()->y + 1));
	if (!mlx_map()->map)
		return (0);
	return (1);
}

int	map_x(char *filename)
{
	int	fd;
	int	i;
	int	j;

	fd = open(filename, O_RDONLY);
	i = 0;
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

int	count_items(void)
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
			else if (mlx_map()->map[i][j] == 'E')
				mlx_map()->b_e++;
			else if (mlx_map()->map[i][j] == 'P')
				mlx_map()->b_p++;
			j++;
		}
		i++;
	}
	if (mlx_map()->b_e != 1 || mlx_map()->b_p != 1)
		return (0);
	return (1);
}

int	verify_walls(void)
{
	int	i;
	int	j;
	int	s_len;

	i = 0;
	s_len = ft_strlen(mlx_map()->map[0]);
	while (mlx_map()->map && mlx_map()->map[i])
	{
		j = 0;
		while (mlx_map()->map && mlx_map()->map[i][j] && j < s_len - 1)
		{
			if (mlx_map()->map[0][j] != '1'
			|| mlx_map()->map[mlx_win()->y - 1][j] != '1')
				return (0);
			else if (mlx_map()->map[i][0] != '1'
			|| mlx_map()->map[i][mlx_win()->x - 1] != '1')
				return (0);
			j++;
		}
		i++;
	}
	set_player_pos();
	return (1);
}

void	set_player_pos(void)
{
	int	i;
	int	j;

	i = 0;
	while (mlx_map()->map && mlx_map()->map[i])
	{
		j = 0;
		while (mlx_map()->map && mlx_map()->map[i][j])
		{
			if (mlx_map()->map[i][j] == 'P')
			{
				mlx_map()->p_x = j;
				mlx_map()->p_y = i;
			}
			j++;
		}
		i++;
	}
}
