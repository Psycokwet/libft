/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/19 16:27:18 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

int		is_equal_to(char c, char const *set)
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

int		strlen_trimed(char const *s1, char const *set)
{
	int i, j, size_new_s;

	i = 0;
	j = 0;
	size_new_s = 0;
	while (s1[i] != '\0')
	{
		if(!is_equal_to(s1[i], set))
			size_new_s++;
		i++;
	}
	return size_new_s;
}

char	*ft_strtrim_int(char const *s1, char const *set)
{
	int size_new_s, i, j;
	char *trimed;
	size_new_s = 1 + strlen_trimed(s1, set);
	
	i = 0;
	j = 0;
	trimed = (char*) malloc(size_new_s * sizeof(char));
	if(!trimed)
		return (NULL);
	while (i < size_new_s && s1[j])
	{
		if(!is_equal_to(s1[j], set)){

	//printf("WWRITE : [%d][%c][%c]\n", i, trimed[i], s1[j]);
			trimed[i] = s1[j];
	//printf("WWRoTE : [%d][%c][%c]\n", i, trimed[i], s1[j]);
			i++;
		}
		j++;
	}
	//printf("WRITE : [%d][%c][%c]\n", i, trimed[i], '\0');
	trimed[i] = '\0';
	//printf("WRoTE : [%d][%c][%c]\n", i, trimed[i], '\0');
	return trimed;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	//printf("INPUT [%s][%s]\n", s1, set);

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
