/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_on.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:19 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/15 16:36:52 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	power_on(t_data *data)
{
	t_mlx	mlx;

	mlx.dt = data;
	mlx.gmr = ft_calloc(1, sizeof(t_gamer));
	mlx.ray = ft_calloc(1, sizeof(t_ray));
	mlx.mlx_p = mlx_init(S_W, S_H, "cub3D", false);
	init_gamer(&mlx);
	mlx.img = mlx_new_image(mlx.mlx_p, S_W, S_H);
	mlx_loop_hook(mlx.mlx_p, game_loop, &mlx);
	mlx_key_hook(mlx.mlx_p, movement, &mlx);
	mlx_loop(mlx.mlx_p);
	ft_free_all(&mlx);
}
