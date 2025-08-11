/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_gamer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:23 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:04:02 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	display_gamer(t_mlx *mlx)
{
	double	x;
	double	y;
	int		i;
	double	rad;

	x = ((mlx->gmr->gmr_x / TILE_SIZE * minmap_w(mlx->dt->w_map)));
	y = ((mlx->gmr->gmr_y / TILE_SIZE * minmap_h(mlx->dt->h_map)));
	i = 0;
	while (i < 360)
	{
		rad = (i * M_PI) / 180;
		mlx_put_pixel(mlx->img, x + ((minmap_w(mlx->dt->w_map) / 4) * cos(rad)),
			y + ((minmap_h(mlx->dt->h_map) / 4) * sin(rad)), GREEN);
		i++;
	}
}
