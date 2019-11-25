/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/25 16:40:35 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int		pow(int value, int pow)
{
	int result;

	result = 1;
	while (--pow > 0)
	{
		result *= 10;
	}
	return (result * value);
}

static size_t	strlen_from_int(int value)
{
	size_t result;

	result = 1;
	if (value < 0)
		result++;
	else if (value == 0)
		return (2);
	while (value != 0)
	{
		value = value / 10;
		result++;
	}
	return (result);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	int		sign;
	int		pow_value;
	size_t	len;

	pow_value = 0;
	i = 0;
	sign = 1;
	len = strlen_from_int(n);
	str = (char*)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		sign = -1;
		str[i++] = '-';
	}
	while (i < len)
	{
		pow_value = pow(1, len - i);
		str[i++] = '0' + (sign * (((n % pow_value) / (pow_value / 10))));
	}
	str[i] = '\0';
	return (str);
}
