/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:04 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:05 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	refill_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map2d[i])
	{
		j = 0;
		while (data->map2d[i][j])
		{
			if (data->map2d[i][j] == 'F')
				data->map2d[i][j] = '0';
			j++;
		}
		i++;
	}
}
