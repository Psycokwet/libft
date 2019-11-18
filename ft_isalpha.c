/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/06 15:01:14 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isbetween(int c, int min, int max)
{
	return (c >= min && c <= max ? 1 : 0);
}

static int	ft_islower(int c)
{
	return (ft_isbetween(c, 'a', 'z'));
}

static int	ft_isupper(int c)
{
	return (ft_isbetween(c, 'A', 'Z'));
}

int			ft_isalpha(int c)
{
	return (ft_islower(c) == 1 || ft_isupper(c) == 1 ? 1 : 0);
}
