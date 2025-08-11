/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_management.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:17 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:05:37 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	collision_management(t_mlx *mlx, double move_x, double move_y)
{
	int		i;
	double	rad;
	double	x;
	double	y;

	i = 0;
	x = ((move_x / TILE_SIZE * minmap_w(mlx->dt->w_map)));
	y = ((move_y / TILE_SIZE * minmap_h(mlx->dt->h_map)));
	if (mlx->dt->map2d[(int)(move_y / TILE_SIZE)]
		[(int)(move_x / TILE_SIZE)] == '1')
		return (1);
	while (i < 360)
	{
		rad = (i * M_PI) / 180;
		if (mlx->dt->map2d[(int)(y + (((minmap_h(mlx->dt->h_map) / 4))
					* sin(rad))) / (((15 * S_H) / 100) / mlx->dt->h_map)]
			[(int)(x + (((minmap_w(mlx->dt->w_map) / 4)
				* cos(rad)))) / (((15 * S_W) / 100) / mlx->dt->w_map)] == '1')
			return (1);
		i++;
	}
	return (0);
}
