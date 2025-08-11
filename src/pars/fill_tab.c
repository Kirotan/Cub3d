/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:52 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:57:54 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

char	**ft_realloc(char **tab, int size)
{
	char	**new_tab;
	int		i;

	i = 0;
	new_tab = ft_calloc(sizeof(char *), size + 1);
	while (tab[i])
	{
		new_tab[i] = ft_strdup(tab[i]);
		i++;
	}
	new_tab[i] = NULL;
	return (new_tab);
}

char	*fill_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(sizeof(char), ft_strlen(str) + 1);
	while (str[i])
	{
		if (i > LIMIT)
		{
			ft_del_all();
			exit(ft_error(MAP_TOO_LARGE));
		}
		if (str[i] == '\n')
			break ;
		else
			line[i] = str[i];
		i++;
	}
	return (line);
}

char	**fill_tab(char *str, int filename)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_calloc(sizeof(char *), 1 + 2);
	while (str)
	{
		if (i > LIMIT)
			exit(ft_error(MAP_TOO_LARGE));
		if (i > 0)
			tab = ft_realloc(tab, i + 1);
		tab[i++] = fill_line(str);
		str = get_next_line(filename);
	}
	return (tab);
}
