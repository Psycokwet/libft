/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2020/08/15 20:33:54 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*result;

	if (!s || !f)
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
** #1. La chaine de caracteres sur laquelle iterer
** #2. La fonction à appliquer à chaque caractere.
** Valeur de retour La chaine de caracteres resultant des applications
** successives de f. Retourne NULL si l'allocation
** echoue.
** Fonctions externes autorisees
** malloc
** Description Applique la fonction 'f' à chaque caractere de la
** chaine de caracteres passee en argument pour creer
** une nouvelle chaine de caracteres (avec malloc(3))
** resultant des applications successives de 'f'.
*/
