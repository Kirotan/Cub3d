/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gamer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:56 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:58 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	get_angle(t_mlx *mlx)
{
	char	c;

	c = mlx->dt->map2d[mlx->dt->p_y][mlx->dt->p_x];
	if (c == 'N')
		mlx->gmr->angle = 3 * M_PI_2;
	if (c == 'S')
		mlx->gmr->angle = M_PI_2;
	if (c == 'E')
		mlx->gmr->angle = 0;
	if (c == 'W')
		mlx->gmr->angle = M_PI;
}

void	init_gamer(t_mlx *mlx)
{
	mlx->gmr->gmr_x = mlx->dt->p_x * TILE_SIZE + TILE_SIZE / 2;
	mlx->gmr->gmr_y = mlx->dt->p_y * TILE_SIZE + TILE_SIZE / 2;
	get_angle(mlx);
	mlx->gmr->fov_rd = (FOV * M_PI) / 180;
}
