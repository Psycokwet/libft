/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/27 14:30:24 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_substr_int(const char *src, size_t len)
{
	char	*dst;

	dst = (char*)malloc(len * sizeof(char));
	if (dst != NULL)
		ft_strlcpy(dst, src, len);
	return (dst);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	return (ft_substr_int(s + start, len + 1));
}
/*
** Alloue (avec malloc(3)) et retourne une chaine de
** caractères issue de la chaine donnée en argument
** Cette nouvelle chaine commence à l’index ’start’ et
** a pour taille maximale ’len’
*/
