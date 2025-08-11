/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:28 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:59:33 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

mlx_texture_t	*cardinal_texture(t_mlx *mlx)
{
	norm_angle(&mlx->ray->ray_angle);
	if (mlx->ray->inter_v_bigger == false)
	{
		if (mlx->ray->ray_angle > M_PI / 2
			&& mlx->ray->ray_angle < 3 * M_PI / 2)
			return (mlx->dt->tex.path_we);
		else
			return (mlx->dt->tex.path_ea);
	}
	else
	{
		if (mlx->ray->ray_angle > 0 && mlx->ray->ray_angle < M_PI)
			return (mlx->dt->tex.path_so);
		else if (mlx->ray->ray_angle > M_PI && mlx->ray->ray_angle < 2 * M_PI)
			return (mlx->dt->tex.path_no);
	}
	return (NULL);
}
