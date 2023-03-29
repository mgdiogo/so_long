/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sark <sark@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:37:25 by sark              #+#    #+#             */
/*   Updated: 2023/03/29 17:53:48 by sark             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int eventos(int keycode)
{
    if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
    {
        printf("%i\n", keycode);
    }

    if (keycode == 65307)
    {
        mlx_destroy_window(mlx_win()->mlx, mlx_win()->mlx_win);
        exit(0);
    }
    return (0);
}