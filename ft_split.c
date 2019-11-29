/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/29 14:25:17 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	set_jump_and_fragment_size(char const *s, char c, size_t *jump,
size_t *size_fragment)
{
	int i;

	i = 0;
	*jump = 0;
	*size_fragment = 0;
	while (s[i] == c && s[i] != '\0')
	{
		i++;
		(*jump)++;
	}
	if (s[i] == '\0')
		return (-1);
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		(*size_fragment)++;
	}
	return (0);
}

static char	*ft_strdup_int(const char *src, size_t len)
{
	char	*dst;

	dst = malloc(len * sizeof(char));
	if (dst)
		ft_strlcpy(dst, src, len);
	return (dst);
}

static int	get_split_datas(const char *s, char c, size_t size_s)
{
	int		n_of_split;
	size_t	i_n;
	size_t	size_fragment_n;
	size_t	jump_n;

	n_of_split = 0;
	if (set_jump_and_fragment_size(s, c, &jump_n, &size_fragment_n))
		return (0);
	i_n = jump_n + size_fragment_n;
	if (size_fragment_n > 0)
		n_of_split++;
	while (i_n < size_s)
	{
		if (set_jump_and_fragment_size(s + i_n, c, &jump_n, &size_fragment_n))
			return (n_of_split);
		i_n += jump_n + size_fragment_n;
		n_of_split++;
	}
	return (n_of_split);
}

char		**fill_split_datas(const char *s, char c, size_t size_s,
int n_of_split)
{
	size_t	j;
	char	**splitted;
	size_t	i_n;
	size_t	size_fragment_n;
	size_t	jump_n;

	j = 0;
	if (set_jump_and_fragment_size(s, c, &jump_n, &size_fragment_n))
		return (NULL);
	splitted = (char**)malloc(sizeof(char*) * (n_of_split + 1));
	if (!splitted)
		return (NULL);
	splitted[j++] = ft_strdup_int(&s[jump_n], size_fragment_n + 1);
	i_n = jump_n + size_fragment_n;
	while (i_n < size_s)
	{
		if (set_jump_and_fragment_size(s + i_n, c, &jump_n, &size_fragment_n))
			return (splitted);
		splitted[j++] = ft_strdup_int(&s[i_n + jump_n], size_fragment_n + 1);
		i_n += jump_n + size_fragment_n + 1;
	}
	splitted[j] = NULL;
	return (splitted);
}

char		**ft_split(char const *s, char c)
{
	int		n_of_split;
	int		i;
	size_t	size_s;
	char	**splitted;

	if (!s)
		return (NULL);
	i = 0;
	size_s = ft_strlen(s);
	n_of_split = get_split_datas(s, c, size_s);
	if (n_of_split == 0)
	{
		splitted = (char**)malloc(sizeof(char*));
		if (splitted)
			splitted[0] = (NULL);
		return (splitted);
	}
	splitted = fill_split_datas(s, c, size_s, n_of_split);
	return (splitted);
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
