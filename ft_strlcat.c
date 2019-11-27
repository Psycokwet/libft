/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/27 14:29:15 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_len_mx)
{
	size_t	dst_len;
	int		dst_len_mx_updated;

	dst_len = ft_strlen(dst);
	dst_len_mx_updated = (int)dst_len_mx - (int)dst_len;
	if (dst_len_mx_updated <= 0)
	{
		return (dst_len_mx + ft_strlen(src));
	}
	return (ft_strlcpy(&dst[dst_len], src, dst_len_mx_updated) + dst_len);
}
