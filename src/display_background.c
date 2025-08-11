/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_background.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:20 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:22 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	display_background(t_mlx *mlx)
{
	int	x;
	int	y;

	x = 0;
	while (x < S_W)
	{
		y = 0;
		while (y < S_H)
		{
			if (x > (15 * S_W) / 100 || y > (15 * S_H) / 100)
				mlx_put_pixel(mlx->img, x, y, GREY);
			y++;
		}
		x++;
	}
}
