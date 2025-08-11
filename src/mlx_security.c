/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_security.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:07 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:59:08 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	mlx_security(t_mlx *mlx, int x, int y, int32_t color)
{
	if (x < 0 || y < 0)
		return ;
	else if (x >= S_W || y >= S_H)
		return ;
	if (x > (15 * S_W) / 100 || y > (15 * S_H) / 100)
		mlx_put_pixel(mlx->img, x, y, color);
}
