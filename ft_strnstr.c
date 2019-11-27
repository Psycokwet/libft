/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/27 15:57:13 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	while (++i < len && haystack[i] != '\0')
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
