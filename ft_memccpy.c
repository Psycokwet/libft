/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/12 15:50:08 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int value, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)dst)[i] = (unsigned char)((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == (unsigned char)value)
		{
			return (void *)&(((unsigned char*)dst)[i + 1]);
		}
		i++;
	}
	return (NULL);
}
