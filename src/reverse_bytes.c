/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 15:59:25 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 15:59:26 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	reverse_bytes(int byte)
{
	unsigned int	new_byte;

	new_byte = 0;
	new_byte |= (byte & 0xFF) << 24;
	new_byte |= (byte & 0xFF00) << 8;
	new_byte |= (byte & 0xFF0000) >> 8;
	new_byte |= (byte & 0xFF000000) >> 24;
	return (new_byte);
}
