/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:50 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:57:51 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	fill_map_param(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] == 'N' || data->map2d[i][j] == 'S'
				|| data->map2d[i][j] == 'E' || data->map2d[i][j] == 'W')
			{
				if (data->p_x != -1 || data->p_y != -1)
				{
					ft_del_all();
					exit(ft_error(MAP_ERR));
				}
				data->p_x = j;
				data->p_y = i;
			}
			j++;
		}
		i++;
	}
}
