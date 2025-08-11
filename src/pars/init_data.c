/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:57:55 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:57:57 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

t_data	init_data(void)
{
	t_data	data;

	data.p_x = -1;
	data.p_y = -1;
	data.color_c = -1;
	data.color_f = -1;
	data.tex.path_ea = NULL;
	data.tex.path_no = NULL;
	data.tex.path_so = NULL;
	data.tex.path_we = NULL;
	return (data);
}
