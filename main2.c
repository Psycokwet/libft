/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:27:38 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/13 19:02:06 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <libc.h>

int main(void)
{
	char dest1[100];
	char dest2[100];
	int ret = 0;
	int ret_1 = 0;
	int ret_2 = 0;
	char *str[4] =
	{
		"",
		"a",
		"abc",
		"abcdefef",
	};
	int size[10] =
	{
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9
	};
	for (size_t i = 0; i < 5 ; i++)
	{
		for (size_t j = 0; j < 11; j++)
		{
			bzero(dest1, 100);
			bzero(dest2, 100);
			ret_1 = ft_strlcat(dest1, str[i], size[j]);
			ret_2 = ft_strlcat(dest2, str[i], size[j]);
			if ((ret = strcmp(dest1, dest2)))
				dprintf(1, "[%s](%d) | [%s](%d) | %d\n", dest1, ret_1, dest2, ret_2, ret);
		}
		
	}
	return (0);
}
