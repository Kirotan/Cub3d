/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:58:01 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:58:02 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_data	parser(int ac, char **av)
{
	t_data	data;

	if (ac != 2 || !av[1])
		exit(ft_error(BAD_ARG));
	data = fill_data(av[1]);
	return (data);
}
