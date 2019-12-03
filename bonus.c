/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/30 10:20:48 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void	*tg(void *param)
{
	(void)param;
	return (NULL);
}
void	tg2(void *param)
{
	(void)param;
}
int		main(int argc, char **argv)
{
	t_list *test1;
	t_list *test2;

	test1 = ft_lstnew(NULL);
	test2 = ft_lstnew(NULL);

	test1->next = test2;
	test2->next = test1;
	ft_lstmap(test1, &tg, &tg2);
	(void)argc;
	(void)argv;
	return (0);
}
