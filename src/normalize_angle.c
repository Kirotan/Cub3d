/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:17 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:59:18 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	norm_angle(double *angle)
{
	if (*angle < 0)
		*angle += 2 * M_PI;
	else if (*angle > 2 * M_PI)
		*angle -= 2 * M_PI;
}

void	normalize_angle(t_mlx *mlx)
{
	if (mlx->gmr->angle < 0)
		mlx->gmr->angle += 2 * M_PI;
	else if (mlx->gmr->angle > 2 * M_PI)
		mlx->gmr->angle -= 2 * M_PI;
}
