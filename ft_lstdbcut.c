/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/14 19:09:06 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list_double	*ft_lstdbcut(t_list_double *lst)
{
	t_list_double *cut;

	if (!lst)
		return NULL;
	cut = lst;
	if (lst->prev && lst->next)
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;
	}
	else if (!lst->prev && lst->next)
		lst->next->prev = NULL;
	else if (lst->prev && !lst->next)
		lst->prev->next = NULL;
	cut->next = NULL;
	cut->prev = NULL;
	return cut;
}
