/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:33 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:57:34 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_text(t_data data)
{
	if (!data.tex.path_no)
	{
		ft_del_all();
		exit(ft_error(TEXTURE_ERR));
	}
	if (!data.tex.path_so)
	{
		ft_del_all();
		exit(ft_error(TEXTURE_ERR));
	}
	if (!data.tex.path_we)
	{
		ft_del_all();
		exit(ft_error(TEXTURE_ERR));
	}
	if (!data.tex.path_ea)
	{
		ft_del_all();
		exit(ft_error(TEXTURE_ERR));
	}
}

void	check_tile(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != ' ' && map[i][j] != '1'
			&& map[i][j] != '0' && map[i][j] != 'N'
			&& map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
		{
			ft_del_all();
			exit(ft_error(MAP_ERR));
		}
		j++;
	}
}

void	flood_fill(char **tab, t_point size)
{
	while (is_0_again(tab) == true)
		fill(tab, size, next_0(tab), '0');
}

void	check_map(char **map, t_data *data)
{
	int	i;

	i = 0;
	data->w_map = 0;
	while (map[i])
	{
		check_tile(map, i);
		if (i == 0 || (int)ft_strlen(map[i]) > data->w_map)
			data->w_map = ft_strlen(map[i]);
		i++;
	}
	flood_fill(map, (t_point){data->w_map, i});
	if (data->p_x == -1 || data->p_y == -1)
	{
		ft_del_all();
		exit(ft_error(PLAYER_ERR));
	}
	data->h_map = i;
}

int	longest_line(char **map)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) > length)
			length = ft_strlen(map[i]);
		i++;
	}
	return (length);
}
