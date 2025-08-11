/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:07 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:22:08 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	calc_x1(t_mlx *mlx)
{
	return ((mlx->gmr->gmr_x + cos(mlx->ray->ray_angle)
			* (1000000)) / TILE_SIZE * minmap_w(mlx->dt->w_map));
}

int	calc_y1(t_mlx *mlx)
{
	return ((mlx->gmr->gmr_y + sin(mlx->ray->ray_angle)
			* (1000000)) / TILE_SIZE * minmap_h(mlx->dt->h_map));
}

int	calc_sx(t_mlx *mlx, int x0)
{
	if (x0 < (calc_x1(mlx)))
		return (1);
	else
		return (-1);
}

int	calc_sy(t_mlx *mlx, int y0)
{
	if (y0 < (calc_y1(mlx)))
		return (1);
	else
		return (-1);
}

int	stop(int x0, int y0, t_mlx *mlx)
{
	if (x0 < 0 || y0 < 0 || x0 >= S_W || y0 >= S_H)
		return (1);
	mlx_put_pixel(mlx->img, x0, y0, GREEN);
	if (!mlx->dt->map2d[y0 / (((15 * S_H) / 100) / mlx->dt->h_map)]
		|| !mlx->dt->map2d[y0 / (((15 * S_H) / 100) / mlx->dt->h_map)]
		[x0 / (((15 * S_W) / 100) / mlx->dt->w_map)]
		|| mlx->dt->map2d[y0 / (((15 * S_H) / 100) / mlx->dt->h_map)]
		[x0 / (((15 * S_W) / 100) / mlx->dt->w_map)] == '1'
		|| (x0 == (calc_x1(mlx)) && y0 == (calc_y1(mlx))))
		return (1);
	return (0);
}
