/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/20 13:29:35 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	int n_of_split, i;

	n_of_split = 1;
	i = 0;
	
}

/*
** Alloue (avec malloc(3)) et retourne un tableau
** de chaines de caracteres obtenu en séparant s à
** l’aide du caractère c, utilisé comme délimiteur. Le
** tableau doit être terminé par NULL.
** Return : Le tableau de nouvelles chaines de caractères,
** résultant du découpage. NULL si l’allocation
** échoue.
*/
