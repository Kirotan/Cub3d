/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:58 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:00 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void	check_gnl(char *str, int fdname)
{
	if (str == NULL)
	{
		ft_del_all();
		close(fdname);
		exit (ft_error(EMPT_MAP));
	}
}

int	open_map(char *filename)
{
	int32_t	file;

	file = open(filename, O_RDONLY);
	if (file == -1)
		exit (ft_error(FD_ERR));
	else if (file == 0)
	{
		close(file);
		exit (ft_error(EMPT_MAP));
	}
	return (file);
}
