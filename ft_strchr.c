/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/12/04 16:54:37 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strchr(const char *s, int c)
// {
// 	size_t			i;
// 	unsigned char	*uc_s;
// 	unsigned char	uc_c;

// 	i = 0;
// 	uc_c = (unsigned char)c;
// 	uc_s = (unsigned char*)s;
// 	while (uc_s[i] != '\0' && uc_s[i] != uc_c)
// 		i++;
// 	if (uc_s[i] == uc_c)
// 		return (void *)&(uc_s[i]);
// 	return (NULL);
// }

char	*ft_strchr(const char *s, int c)
{
	return (ft_memchr(s, c, ft_strlen(s) + 1));
}
