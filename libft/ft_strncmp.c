/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:12:59 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:13:01 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while (i < length && *first != '\0' && *second != '\0')
	{
		if ((unsigned char)*first != (unsigned char)*second)
			return ((unsigned char)*first - (unsigned char)*second);
		second++;
		first++;
		i++;
	}
	if (i == length)
		return (0);
	return ((unsigned char)*first - (unsigned char)*second);
}
