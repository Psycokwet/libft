/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/18 13:14:46 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void	init(size_t *j, int *start_pattern)
{
	*j = 0;
	*start_pattern = -1;
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		start_pattern;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = -1;
	init(&j, &start_pattern);
	while (haystack[++i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			j++;
			if (start_pattern == -1)
				start_pattern = i;
			if (needle[j] == '\0')
				return ((char*)&haystack[start_pattern]);
		}
		else
			init(&j, &start_pattern);
	}
	return (NULL);
}
