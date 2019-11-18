/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/08 16:27:57 by scarboni         ###   ########.fr       */
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

char *ft_strjoin(char const *s, unsigned int start, size_t len)
{
	return (ft_strdup_int( s + start, len));
}


/*Alloue (avec malloc(3)) et retourne une chaine de
caractères issue de la chaine donnée en argument
Cette nouvelle chaine commence à l’index ’start’ et
a pour taille maximale ’len’
*/
