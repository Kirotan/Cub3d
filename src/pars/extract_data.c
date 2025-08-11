/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:43 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:57:44 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	fill_texture(t_data *data, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strdup(str + 3);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	tmp[i] = '\0';
	if (ft_strncmp(str, "NO ", 3) == 0)
		data->tex.path_no = mlx_load_png(tmp);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		data->tex.path_so = mlx_load_png(tmp);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		data->tex.path_we = mlx_load_png(tmp);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		data->tex.path_ea = mlx_load_png(tmp);
	ft_del_alloc(tmp);
	return ;
}

char	*pars_color(char *str, int *i, int *k, int *color_int)
{
	int		j;
	char	*color;

	color = ft_alloc(sizeof(char), ft_strlen(str) + 1);
	while (str[*i] && *k < 3)
	{
		j = 0;
		if (str[*i] != ',' && !ft_isdigit(str[*i]))
		{
			ft_del_all();
			exit(ft_error(COLOR_ERR));
		}
		if (str[*i] && !ft_isdigit(str[*i]))
			(*i)++;
		while (str[*i] && ft_isdigit(str[*i]))
			color[j++] = str[(*i)++];
		color[j] = '\0';
		if (ft_atoi(color) < 0 || ft_atoi(color) > 255)
		{
			ft_del_all();
			exit(ft_error(COLOR_ERR));
		}
		color_int[(*k)++] = ft_atoi(color);
	}
	return (color);
}

void	fill_color(t_data *data, char *str)
{
	int		i;
	int		k;
	char	*color;
	int		*color_int;

	i = 2;
	k = 0;
	color_int = ft_alloc(sizeof(int), 3);
	color = pars_color(str, &i, &k, color_int);
	if (str[i + 1] != '\0')
	{
		ft_del_all();
		exit(ft_error(COLOR_ERR));
	}
	if (str[0] == 'C')
		data->color_c = convert_color(color_int);
	else if (str[0] == 'F')
		data->color_f = convert_color(color_int);
	ft_del_alloc(color);
}

void	wall_case(char *str, int *i, t_data *data, int fd)
{
	if (wall_text(str) == 1)
	{
		while (*i < 4 && wall_text(str) == 1)
		{
			fill_texture(data, str);
			(*i)++;
			ft_del_alloc(str);
			str = get_next_line(fd);
		}
		if (*i != 4)
		{
			ft_del_all();
			exit(ft_error(TEXTURE_ERR));
		}
	}
}

void	extract_data(char *str, t_data *data, int fd)
{
	int	i;

	i = 0;
	if ((ft_strncmp(str, "C ", 2) == 0
			|| ft_strncmp(str, "F ", 2) == 0) && ft_isdigit(str[2]))
	{
		fill_color(data, str);
		ft_del_alloc(str);
		str = get_next_line(fd);
		if (!str)
		{
			ft_del_all();
			exit(ft_error(COLOR_ERR));
		}
		else if ((ft_strncmp(str, "C ", 2) == 0
				|| ft_strncmp(str, "F ", 2) == 0) && ft_isdigit(str[2]))
			fill_color(data, str);
		else
		{
			ft_del_all();
			exit(ft_error(COLOR_ERR));
		}
	}
	wall_case(str, &i, data, fd);
}
