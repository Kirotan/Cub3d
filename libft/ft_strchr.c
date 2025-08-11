/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:12:49 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:12:50 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *string, int searched_char)
{
	if (!string)
		return (NULL);
	while (*string != '\0')
	{
		if (*string == (char)searched_char)
			return ((char *)string);
		string++;
	}
	if ((char)searched_char == '\0')
		return ((char *)string);
	return (NULL);
}
