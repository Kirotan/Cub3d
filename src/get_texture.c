/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:54 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/15 15:07:35 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

double	get_horiz_tex(t_mlx *mlx, mlx_texture_t *texture)
{
	double			horiz_tex;

	if (mlx->ray->inter_v_bigger == true)
		horiz_tex = (int)fmod(mlx->ray->horiz_x, texture->width);
	else
		horiz_tex = (int)fmod(mlx->ray->vert_y, texture->width);
	if (horiz_tex < 0 || horiz_tex >= texture->width)
		return (0);
	return (horiz_tex);
}
