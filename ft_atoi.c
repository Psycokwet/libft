/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/27 14:26:56 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_blanks(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
	{
		i++;
	}
	return (i);
}

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

static int	set_sign(int *i, const char *str)
{
	if (str[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	else if (str[*i] == '+')
		(*i)++;
	return (1);
}

int			ft_atoi(const char *str)
{
	int		value;
	int		i;
	size_t	size;
	int		sign;

	value = 0;
	i = skip_blanks(str);
	sign = set_sign(&i, str);
	size = ft_strlen(str);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		value = (pow((str[i] - '0'), size - i) * sign) + value;
		if ((sign < 0 && value > 0))
			return (0);
		else if ((sign > 0 && value < 0))
			return (-1);
		i++;
	}
	return (value) / (pow(1, size - --i));
}
