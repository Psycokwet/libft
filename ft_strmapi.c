/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/25 16:43:39 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	if (!s)
		return (NULL);
	i = -1;
	len = ft_strlen(s);
	result = (char*)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (++i < len)
		result[i] = (*f)(i, s[i]);
	result[i] = '\0';
	return (result);
}

/*
** #1. La chaine de caractères sur laquelle itérer
** #2. La fonction à appliquer à chaque caractère.
** Valeur de retour La chaine de caractères résultant des applications
** successives de f. Retourne NULL si l’allocation
** échoue.
** Fonctions externes autorisées
** malloc
** Description Applique la fonction ’f’ à chaque caractère de la
** chaine de caractères passée en argument pour créer
** une nouvelle chaine de caractères (avec malloc(3))
** résultant des applications successives de ’f’.
*/
