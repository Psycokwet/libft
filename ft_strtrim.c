/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/22 12:47:39 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int		is_equal_to(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		get_start_trimmed(char const *s1, char const *set)
{
	int i;

	i = 0;
	while (is_equal_to(s1[i], set) && s1[i] != '\0')
		i++;
	return (i);
}

static int		get_end_trimmed(char const *s1, char const *set, size_t len)
{
	size_t i;

	i = 1;
	while (is_equal_to(s1[len - i], set) && i < len)
		i++;
	return (i-1);
}

static char	*ft_strtrim_int(char const *s1, char const *set)
{
	int size_new_s, j;
	size_t len, end, start;
	char *trimed;
	
	len = ft_strlen(s1);
	
	start = get_start_trimmed(s1, set);
	if(start == len)
	{
		trimed = (char*) malloc(sizeof(char));
		trimed[0] = '\0';
		return (trimed);
	}
	end = get_end_trimmed(s1, set, len);
	size_new_s = ((int)len) - start - end;
	j = 0;
	trimed = (char*) malloc((1 + size_new_s) * sizeof(char));
	if(!trimed)
		return (NULL);

	while (start < len - end && s1[start])
	{
		trimed[j] = s1[start];
		start++;
		j++;
	}
	trimed[j] = '\0';
	return trimed;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	if (!s1)
		return (NULL);
	if(!set)
		return ft_strdup(s1);
	return ft_strtrim_int(s1, set);
}

/*
** Alloue (avec malloc(3)) et retourne une copie de la
** chaine de caractères donnée en argument, sans les
** caractères spécifiés dans le set donné en argument
** au début et à la fin de la chaine de caractères.
*/
