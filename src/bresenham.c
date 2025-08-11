/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:10 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:12 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	increment(int *err, int *x0, int sx, int dy)
{
	*err -= dy;
	*x0 += sx;
}

void	bresenham(int x0, int y0, int e2, t_mlx *mlx)
{
	int	err;
	int	sx;
	int	sy;
	int	dy;
	int	dx;

	sx = calc_sx(mlx, x0);
	sy = calc_sy(mlx, y0);
	dy = abs((calc_y1(mlx)) - y0);
	dx = abs((calc_x1(mlx)) - x0);
	err = abs((calc_x1(mlx)) - x0) - abs((calc_y1(mlx)) - y0);
	while (1)
	{
		if (stop(x0, y0, mlx) == 1)
			break ;
		e2 = 2 * err;
		if (e2 > -dy)
			increment(&err, &x0, sx, dy);
		if (e2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
