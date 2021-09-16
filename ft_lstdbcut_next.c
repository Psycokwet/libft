/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbcut_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2021/08/31 15:42:03 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list_double	*ft_lstdbcut_next(t_list_double *lst)
{
	t_list_double *cut;

	if (!lst || !lst->next)
		return NULL;
	cut = lst->next;
	lst->next = cut->next;
	cut->next = NULL;
	return cut;
}
