/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gamer_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:48 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:50 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	rotate_gamer(t_mlx *mlx)
{
	if (mlx->gmr->rot == 1)
	{
		mlx->gmr->angle += ROTATION_SPEED * mlx->mlx_p->delta_time;
		if (mlx->gmr->angle > 2 * M_PI)
			mlx->gmr->angle -= 2 * M_PI;
	}
	else if (mlx->gmr->rot == -1)
	{
		mlx->gmr->angle -= ROTATION_SPEED * mlx->mlx_p->delta_time;
		if (mlx->gmr->angle < 0)
			mlx->gmr->angle += 2 * M_PI;
	}
}

void	up_down_move(t_mlx *mlx)
{
	double	move_x;
	double	move_y;

	move_x = mlx->gmr->gmr_x;
	move_y = mlx->gmr->gmr_y;
	if (mlx->gmr->u_d == 1)
	{
		move_x += cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		move_y += sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
	else if (mlx->gmr->u_d == -1)
	{
		move_x += -cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		move_y += -sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
	if (collision_management(mlx, move_x, move_y) == 0)
	{
		mlx->gmr->gmr_x = move_x;
		mlx->gmr->gmr_y = move_y;
	}
}

void	left_right_move(t_mlx *mlx)
{
	double	move_x;
	double	move_y;

	move_x = mlx->gmr->gmr_x;
	move_y = mlx->gmr->gmr_y;
	if (mlx->gmr->l_r == -1)
	{
		move_x += sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		move_y += -cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
	else if (mlx->gmr->l_r == 1)
	{
		move_x += -sin(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
		move_y += cos(mlx->gmr->angle)
			* GAMER_SPEED * mlx->mlx_p->delta_time;
	}
	if (collision_management(mlx, move_x, move_y) == 0)
	{
		mlx->gmr->gmr_x = move_x;
		mlx->gmr->gmr_y = move_y;
	}
}

void	gamer_movement(t_mlx *mlx)
{
	rotate_gamer(mlx);
	up_down_move(mlx);
	left_right_move(mlx);
	normalize_angle(mlx);
}
