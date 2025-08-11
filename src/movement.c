/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:14 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/15 13:08:03 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	re_init_mov(mlx_key_data_t mov, t_mlx *mlx)
{
	if (mov.key == MLX_KEY_D && (mov.action == MLX_RELEASE))
		mlx->gmr->l_r = 0;
	else if (mov.key == MLX_KEY_A && (mov.action == MLX_RELEASE))
		mlx->gmr->l_r = 0;
	else if (mov.key == MLX_KEY_S && (mov.action == MLX_RELEASE))
		mlx->gmr->u_d = 0;
	else if (mov.key == MLX_KEY_W && (mov.action == MLX_RELEASE))
		mlx->gmr->u_d = 0;
	else if (mov.key == MLX_KEY_LEFT && mov.action == MLX_RELEASE)
		mlx->gmr->rot = 0;
	else if (mov.key == MLX_KEY_RIGHT && mov.action == MLX_RELEASE)
		mlx->gmr->rot = 0;
}

void	movement(mlx_key_data_t mov, void *param)
{
	t_mlx	*mlx;

	mlx = ((t_mlx *)param);
	if (mov.key == MLX_KEY_ESCAPE
		&& (mov.action == MLX_PRESS || mov.action == MLX_REPEAT))
		ft_free_all(mlx);
	else if (mov.key == MLX_KEY_W && mov.action == MLX_PRESS)
		mlx->gmr->u_d = 1;
	else if (mov.key == MLX_KEY_S && (mov.action == MLX_PRESS))
		mlx->gmr->u_d = -1;
	else if (mov.key == MLX_KEY_A && (mov.action == MLX_PRESS))
		mlx->gmr->l_r = -1;
	else if (mov.key == MLX_KEY_D && (mov.action == MLX_PRESS))
		mlx->gmr->l_r = 1;
	else if (mov.key == MLX_KEY_LEFT && mov.action == MLX_PRESS)
		mlx->gmr->rot = -1;
	else if (mov.key == MLX_KEY_RIGHT && mov.action == MLX_PRESS)
		mlx->gmr->rot = 1;
	re_init_mov(mov, mlx);
}
