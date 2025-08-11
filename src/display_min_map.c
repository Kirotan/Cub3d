/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_min_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:38 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:39 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw_min_wall_square(t_mlx *mlx, int y, int x, int color)
{
	int	i;
	int	j;
	int	h_tile;
	int	w_tile;

	h_tile = ((15 * S_H) / 100) / mlx->dt->h_map;
	w_tile = ((15 * S_W) / 100) / mlx->dt->w_map;
	i = 0;
	while (i < h_tile)
	{
		j = 0;
		while (j < w_tile)
		{
			mlx_put_pixel(mlx->img, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	display_min_map(t_mlx *mlx)
{
	int		x;
	int		y;
	int		h_tile;
	int		w_tile;

	y = 0;
	h_tile = ((15 * S_H) / 100) / mlx->dt->h_map;
	w_tile = ((15 * S_W) / 100) / mlx->dt->w_map;
	while (y < mlx->dt->h_map)
	{
		x = 0;
		while (x < mlx->dt->w_map)
		{
			if (mlx->dt->map2d[y][x] == '1')
				draw_min_wall_square(mlx, y * h_tile, x * w_tile, ORANGE);
			else if (mlx->dt->map2d[y][x] == '0'
					|| ft_isalpha(mlx->dt->map2d[y][x]))
				draw_min_wall_square(mlx, y * h_tile, x * w_tile, PURPLE);
			x++;
		}
		y++;
	}
}
