/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_if_same.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdoumer <gdoumer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:12:20 by gdoumer           #+#    #+#             */
/*   Updated: 2024/08/14 16:12:22 by gdoumer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del_if_same(t_malloc_ptr *l_m, t_malloc_ptr *tmp, void *var)
{
	if (l_m->next && l_m->next->ptr == var)
	{
		tmp = l_m->next;
		l_m->next = tmp->next;
		free(tmp->ptr);
		tmp->ptr = NULL;
		free(tmp);
		tmp = NULL;
	}
}
