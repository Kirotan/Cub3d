/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:31 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/16 13:26:20 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	display_ceiling(t_mlx *mlx, double top_of_wall, int i)
{
	int		j;

	j = top_of_wall;
	while (j > 0)
	{
		mlx_security(mlx, i, j, mlx->dt->color_c);
		j--;
	}
}

static void	display_floor(t_mlx *mlx, double bot_of_wall, int i)
{
	int		j;

	j = bot_of_wall;
	while (j < S_H)
	{
		mlx_security(mlx, i, j, mlx->dt->color_f);
		j++;
	}
}

static void	display_wall(t_mlx *mlx, double top_of_wall,
	double bot_of_wall, int i)
{
	mlx_texture_t	*texture;
	double			offset;
	double			verti_tex;
	uint32_t		*pixel_tab;
	uint32_t		pixel_color;

	texture = cardinal_texture(mlx);
	if (texture == NULL)
		return ;
	pixel_tab = (uint32_t *)texture->pixels;
	offset = texture->height / (mlx->ray->prjc_wall_hei);
	verti_tex = (top_of_wall - (S_H / 2)
			+ ((mlx->ray->prjc_wall_hei) / 2)) * offset;
	if (verti_tex < 0)
		verti_tex = 0;
	while (top_of_wall < bot_of_wall)
	{
		if (verti_tex >= texture->height)
			return ;
		pixel_color = reverse_bytes(pixel_tab[(int)verti_tex
				* texture->width + (int)get_horiz_tex(mlx, texture)]);
		mlx_security(mlx, i, (int)top_of_wall, pixel_color);
		verti_tex += offset;
		top_of_wall++;
	}
}

void	display_image(t_mlx *mlx, int i)
{
	double	top_of_wall;
	double	bot_of_wall;

	norm_angle(&mlx->ray->ray_angle);
	norm_angle(&mlx->gmr->angle);
	mlx->ray->distance *= cos(mlx->ray->ray_angle
			- mlx->gmr->angle);
	mlx->ray->dist_prjc_plane = (S_W / 2) / tan(mlx->gmr->fov_rd / 2);
	mlx->ray->prjc_wall_hei = (TILE_SIZE / mlx->ray->distance)
		* mlx->ray->dist_prjc_plane;
	top_of_wall = S_H / 2 - mlx->ray->prjc_wall_hei / 2;
	bot_of_wall = S_H / 2 + mlx->ray->prjc_wall_hei / 2;
	if (top_of_wall < 0)
		top_of_wall = 0;
	if (bot_of_wall > S_H)
		bot_of_wall = S_H;
	display_wall(mlx, top_of_wall, bot_of_wall, i);
	display_floor(mlx, bot_of_wall, i);
	display_ceiling(mlx, top_of_wall, i);
}
