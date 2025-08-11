/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:51 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:52 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	horiz_check_up_or_down(t_mlx *mlx, double *dist_y, double *coord_y)
{
	if (mlx->gmr->angle > 0 && mlx->gmr->angle < M_PI)
	{
		*dist_y = TILE_SIZE;
		*coord_y = floor(mlx->gmr->gmr_y / TILE_SIZE) * TILE_SIZE;
		if (*dist_y < 0)
			*coord_y += TILE_SIZE;
	}
	else
	{
		*dist_y = TILE_SIZE;
		*coord_y = floor(mlx->gmr->gmr_y / TILE_SIZE) * TILE_SIZE;
	}
	if (*dist_y < 0)
		*coord_y += -1;
}

double	inter_horiz(t_mlx *mlx)
{
	double	coord_y;
	double	coord_x;
	double	dist_x;
	double	dist_y;
	double	pixel;

	dist_y = 0;
	coord_y = 0;
	horiz_check_up_or_down(mlx, &dist_y, &coord_y);
	pixel = inter_check(mlx->ray->ray_angle, &coord_y, &dist_y, 1);
	coord_x = mlx->gmr->gmr_x + (coord_y - mlx->gmr->gmr_y)
		/ tan(mlx->ray->ray_angle);
	dist_x = TILE_SIZE / tan(mlx->ray->ray_angle);
	if ((circle(mlx->ray->ray_angle, 'y') && dist_x > 0)
		|| (!circle(mlx->ray->ray_angle, 'y') && dist_x < 0))
		dist_x *= -1;
	while (wall_or_not(mlx, coord_x, coord_y - pixel))
	{
		coord_x += dist_x;
		coord_y += dist_y;
	}
	mlx->ray->horiz_x = coord_x;
	mlx->ray->horiz_y = coord_y;
	return (sqrt(pow(coord_x - mlx->gmr->gmr_x, 2)
			+ pow(coord_y - mlx->gmr->gmr_y, 2)));
}

static void	verti_check_l_or_r(t_mlx *mlx, double *dist_x, double *coord_x)
{
	if (mlx->gmr->angle > 0 && mlx->gmr->angle < M_PI)
	{
		*dist_x = TILE_SIZE;
		*coord_x = floor(mlx->gmr->gmr_x / TILE_SIZE) * TILE_SIZE ;
		if (*dist_x < 0)
			*coord_x += -1;
	}
	else
	{
		*dist_x = TILE_SIZE;
		*coord_x = floor(mlx->gmr->gmr_x / TILE_SIZE) * TILE_SIZE;
		if (*dist_x < 0)
			*coord_x -= TILE_SIZE;
	}
}

double	inter_verti(t_mlx *mlx)
{
	double	coord_y;
	double	coord_x;
	double	dist_x;
	double	dist_y;
	double	pixel;

	dist_x = 0;
	dist_y = TILE_SIZE * tan(mlx->ray->ray_angle);
	coord_x = 0;
	verti_check_l_or_r(mlx, &dist_x, &coord_x);
	pixel = inter_check(mlx->ray->ray_angle, &coord_x, &dist_x, 0);
	coord_y = mlx->gmr->gmr_y + (coord_x - mlx->gmr->gmr_x)
		* tan(mlx->ray->ray_angle);
	if ((circle(mlx->ray->ray_angle, 'x') && dist_y < 0)
		|| (!circle(mlx->ray->ray_angle, 'x') && dist_y > 0))
		dist_y *= -1;
	while (wall_or_not(mlx, coord_x - pixel, coord_y))
	{
		coord_x += dist_x;
		coord_y += dist_y;
	}
	mlx->ray->vert_x = coord_x;
	mlx->ray->vert_y = coord_y;
	return (sqrt(pow(coord_x - mlx->gmr->gmr_x, 2)
			+ pow(coord_y - mlx->gmr->gmr_y, 2)));
}
