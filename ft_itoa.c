/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/22 15:45:19 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	strlen_from_int(int value)
{
	size_t result;

	result = 1;
	if(value < 0)
		result++;
	else if(value == 0)
		return 2;
	while (value != 0)
	{
		value = value / 10;
		result++;
	}
	return (result);
}


char	*ft_itoa(int n)
{
	char *str;
	int i;
	int pow;
	(void)n;
	size_t len;

	i = 0;
	len = strlen_from_int(n);
	printf("ITOA [%d][%d]\n", n, strlen_from_int(n));
	str = (char*)malloc(sizeof(char) * len);
	if(!str)
		return NULL;
	if(n < 0)
	{
		str[i] = '-';
		i++;
	}
	while(i < len)
	{
		str[len - po] = '-';
		
	}

	str[i] = '\0';
	printf("RESULT [%s]\n", str);
	return str;
}
