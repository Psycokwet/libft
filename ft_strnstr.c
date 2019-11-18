/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/18 12:58:08 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	(void)len;
	size_t i;
	size_t j;
	size_t needle_size;
	int start_pattern;

	if (needle[0] == '\0')
	{
		return ((char*)haystack);
	}
	i = 0;
	j = 0;
	start_pattern = -1;
	needle_size = ft_strlen(needle);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			j++;
			if (start_pattern == -1)
			{
				start_pattern = i;
			}
			if (j == needle_size)
			{
				return ((char*)&haystack[start_pattern]);
			}
		}
		else
		{
			j = 0;
			start_pattern = -1;
		}
		i++;
	}
	return (NULL);
}
