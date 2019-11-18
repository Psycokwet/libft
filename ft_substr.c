/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/08 16:29:20 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strdup_int(const char *src, size_t len)
{
	char	*dst;

	dst = malloc(len * sizeof(char));
	if (dst != NULL)
	{
		ft_strlcpy(dst, src, len);
	}
	return (dst);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	return (ft_strdup_int(s + start, len));
}
