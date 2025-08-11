/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:12:52 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:12:53 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *source)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!source)
		return (NULL);
	new = (char *)ft_alloc(sizeof(char), ft_strlen(source) + 1);
	if (!new)
		return (NULL);
	while (*source)
		new[i++] = *source++;
	new[i] = '\0';
	return (new);
}
