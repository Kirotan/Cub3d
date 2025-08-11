/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_check_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:00 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:59:01 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

double	wall_or_not(t_mlx *mlx, double coord_x, double coord_y)
{
	int	x_on_map;
	int	y_on_map;

	if (coord_x < 0 || coord_y < 0)
		return (0);
	x_on_map = floor(coord_x / TILE_SIZE);
	y_on_map = floor(coord_y / TILE_SIZE);
	if (y_on_map >= mlx->dt->h_map || x_on_map >= mlx->dt->w_map
		|| y_on_map < 0 || x_on_map < 0)
		return (0);
	if (mlx->dt->map2d[y_on_map][x_on_map] == '1')
		return (0);
	return (1);
}

int	inter_check(double angle, double *inter, double *dist, int horizon)
{
	if (horizon)
	{
		if (angle > 0 && angle < M_PI)
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*dist *= -1;
	}
	else
	{
		if (!(angle > M_PI / 2 && angle < 3 * M_PI / 2))
		{
			*inter += TILE_SIZE;
			return (-1);
		}
		*dist *= -1;
	}
	return (1);
}

int	circle(double angle, char c)
{
	if (c == 'x')
	{
		if (angle > 0 && angle < M_PI)
			return (1);
	}
	else if (c == 'y')
	{
		if (angle > (M_PI / 2) && angle < (3 * M_PI) / 2)
			return (1);
	}
	return (0);
}
