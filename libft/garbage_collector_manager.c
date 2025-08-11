/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector_manager.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:13:04 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:13:06 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_alloc(int size, unsigned long type)
{
	return (malloc_factory(size, NEW, NULL, type));
}

void	*ft_del_alloc(void *var)
{
	return (malloc_factory(0, DELETE, var, 0));
}

void	*ft_del_all(void)
{
	return (malloc_factory(0, CLEAR, NULL, 0));
}
