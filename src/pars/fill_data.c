/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:46 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:57:48 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	is_0_again(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '0')
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	fill(char **tab, t_point size, t_point cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || tab[cur.y][cur.x] == ' ')
	{
		ft_del_all();
		exit (ft_error(UNCLOSED_MAP));
	}
	if (tab[cur.y][cur.x] != to_fill && tab[cur.y][cur.x] != ' ')
		return ;
	if (tab[cur.y][cur.x] == '0' || tab[cur.y][cur.x] == ' ')
		tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, to_fill);
}

t_point	next_0(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '0')
				return ((t_point){j, i});
			j++;
		}
		i++;
	}
	return ((t_point){0, 0});
}

void	plug_holes(char **map)
{
	int	i;
	int	line_length;

	line_length = longest_line(map);
	i = 0;
	while (map[i])
	{
		while ((int)ft_strlen(map[i]) < line_length)
		{
			map[i] = ft_strjoin(map[i], " ");
		}
		i++;
	}
}

t_data	fill_data(char *filename)
{
	t_data	data;
	int		fd;
	char	*str;

	data = init_data();
	check_filename(filename);
	fd = open_map(filename);
	str = get_next_line(fd);
	check_gnl(str, fd);
	while (str && (data.color_c == -1 || data.color_f == -1 || !data.tex.path_no
			|| !data.tex.path_so || !data.tex.path_we || !data.tex.path_ea))
	{
		extract_data(str, &data, fd);
		str = get_next_line(fd);
		while (str && str[0] == '\n')
			str = get_next_line(fd);
	}
	check_text(data);
	data.map2d = fill_tab(str, fd);
	plug_holes(data.map2d);
	fill_map_param(&data);
	check_map(data.map2d, &data);
	refill_map(&data);
	close(fd);
	return (data);
}
