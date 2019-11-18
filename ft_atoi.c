/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/08 14:16:02 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	pow(int value, int pow)
{
	int result;

	result = 1;
	while (--pow > 0)
	{
		result *= 10;
	}
	return (result * value);
}
int			ft_atoi(const char *str)
{
	int value;
	int i;
	size_t size;
	int sign;

	sign = 1;
	value = 0;
	i = 0;
	size = ft_strlen(str);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		value = pow((str[i] - '0'), size - i) + value;
		i++;
	}
	return (value * sign) / (pow(1, size - --i));
}
