/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/18 12:35:56 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	srcsize;

	if (!dst)
		return (0);
	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	i = -1;
	while (++i < (int)srcsize && i < ((int)dstsize) - 1)
	{
		dst[i] = src[i];
	}
	dst[i] = '\0';
	return (srcsize);
}
