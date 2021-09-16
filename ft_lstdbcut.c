/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbcut.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/31 15:26:54 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list_double	*ft_lstdbcut(t_list_double *lst)
{
	t_list_double *cut;

	if (!lst)
		return NULL;
	cut = lst;

	printf("BEF CUT %p:%p:%d:%p\n", (void*)cut->prev,  (void*)cut,  *(int*)cut->content, (void*)cut->next);
	if (lst->prev && lst->next)
	{
		lst->prev->next = lst->next;
		lst->next->prev = lst->prev;

	printf("PREV %p:%p:%p\n", (void*)lst->prev->prev,  (void*)lst->prev, (void*)lst->prev->next);
	printf("NEXT %p:%p:%p\n", (void*)lst->next->prev,  (void*)lst->next, (void*)lst->next->next);
	}
	else if (!lst->prev && lst->next){
		lst->next->prev = NULL;

	printf("NEXT %p:%p:%p\n", (void*)lst->next->prev,  (void*)lst->next, (void*)lst->next->next);
		}
	else if (lst->prev && !lst->next){
		lst->prev->next = NULL;
	printf("PREV %p:%p:%p\n", (void*)lst->prev->prev,  (void*)lst->prev, (void*)lst->prev->next);
		}
	cut->next = NULL;
	cut->prev = NULL;
	printf("CUT %p:%p:%p\n", (void*)cut->prev,  (void*)cut, (void*)cut->next);
	return cut;
}
