/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/01/07 15:47:25 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	srcsize;

	if (!src)
		return (0);
	srcsize = ft_strlen(src);
	if (!dst || dstsize == 0)
		return (srcsize);
	i = -1;
	while (++i < (int)srcsize && i < ((int)dstsize) - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (srcsize);
}
