/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/01/07 17:07:59 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init(size_t *j, int *start_pattern, size_t *i)
{
	*j = 0;
	if (*start_pattern != -1)
		*i = (size_t)(*start_pattern + 1);
	*start_pattern = -1;
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		start_pattern;

	if (needle[0] == '\0')
		return ((char*)haystack);
	j = 0;
	start_pattern = -1;
	i = -1;
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
			init(&j, &start_pattern, &i);
	}
	return (NULL);
}
