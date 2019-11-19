/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/19 13:23:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	if(!s1 || !s2)
		return NULL;
	char	*dst;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);

	dst = malloc((size_s1 + size_s2)* sizeof(char));
	if (dst == NULL)
		return NULL;
	ft_strlcpy(dst, s1, size_s1 + 1);
	ft_strlcat(dst, s2, size_s1 + size_s2 + 1);
	return (dst);
}


/* 
Alloue (avec malloc(3)) et retourne une nouvelle
chaine, résultat de la concaténation de s1 et s2.

La nouvelle chaine de caractères. NULL si
l’allocation échoue.
*/
