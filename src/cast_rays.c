/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:13 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:15 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	state(t_mlx *mlx, double inter_h, double inter_v)
{
	if (inter_v <= inter_h)
		mlx->ray->distance = inter_v;
	else
	{
		mlx->ray->distance = inter_h;
		mlx->ray->inter_v_bigger = true;
	}
}

void	cast_rays(t_mlx *mlx)
{
	double	inter_h;
	double	inter_v;
	int		i;

	i = 0;
	mlx->ray->ray_angle = mlx->gmr->angle - mlx->gmr->fov_rd / 2;
	while (i < S_W)
	{
		mlx->ray->inter_v_bigger = false;
		inter_v = inter_verti(mlx);
		norm_angle(&inter_v);
		inter_h = inter_horiz(mlx);
		norm_angle(&inter_h);
		state(mlx, inter_h, inter_v);
		bresenham(mlx->gmr->gmr_x / TILE_SIZE * minmap_w(mlx->dt->w_map),
			mlx->gmr->gmr_y / TILE_SIZE * minmap_h(mlx->dt->h_map), 0, mlx);
		display_image(mlx, i);
		i++;
		mlx->ray->ray_angle += mlx->gmr->fov_rd / S_W;
		norm_angle(&mlx->ray->ray_angle);
	}
}
