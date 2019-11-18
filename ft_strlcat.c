/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/18 12:36:23 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <libc.h>

// size_t	ft_strlcat(char *dst, const char *src, size_t dst_len_mx)
// {
// 	int		i;
// 	size_t	dstsize;
// 	size_t	srcsize;

// 	dstsize = ft_strlen(dst);
// 	srcsize = ft_strlen(src);
// 	if (dst_len_mx == 0)
// 		return (srcsize);
// 	i = -1;
// 	while (++i < (int)srcsize && (((int)dstsize) + i) < ((int)dst_len_mx))
// 	{
// 		dst[dstsize + i] = src[i];
// 	}
// 	dst[dstsize + i] = '\0';
// 	return (dstsize + srcsize);
// }


/*
size_t	ft_strlcat(char *restrict dest, const char *restrict src, size_t size)
{
	size_t	j;
	size_t	i;

	i = 0;
	while (dest[i] && i < size)
		i++;
	if (i < size)
	{
		j = 0;
		while (src[j] && j + i < size - 1)
		{
			dest[i + j] = src[j];
			j++;
		}
		dest[j + i] = '\0';
	}
	else
		return (ft_strlen(src) + size);
	return (ft_strlen(src) + i);
}


size_t	ft_strlcat(char *dst, const char *src, size_t dst_len_mx)
{
	int		i;
	size_t	dstsize;
	size_t	srcsize;

	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	if (dst_len_mx == 0)
		return (srcsize);
	i = -1;
	while (++i < (int)srcsize && (((int)dstsize) + i) < ((int)dst_len_mx))
	{
		//printf("A que coucou bob %lu:%d[%s] [%s]\n", dstsize, i, dst, src);
		dst[dstsize + i] = src[i];
	}
	dst[dstsize + i] = '\0';
	//printf("FIIIIN %lu:%d[%s] [%s] %d:%d\n", srcsize, i, dst, src, ((int)dstsize) + i,  (int)dst_len_mx);
	return (dstsize + srcsize);

	

	
	size_t	dst_len;
	size_t	src_len;
	int		i;
	int		j;

	dst_len = ft_strlen(dst);
	i = dst_len - 1;
	j = -1;
	src_len = ft_strlen(src);
	while (++i < (int)dst_len_mx && ++j < (int)src_len)
	{
		dst[i] = src[j];
	}
	return (dst_len + src_len);
}8/

*/
size_t	ft_strlcat(char *dst, const char *src, size_t dst_len_mx)
{
	size_t dst_len;
	int out;

	dst_len = ft_strlen(dst);
	out = (int)dst_len_mx - (int)dst_len;
	if(out <= 0){
		return (dst_len_mx + ft_strlen(src));
	}
	return (ft_strlcpy(&dst[dst_len], src, (int)dst_len_mx - (int)dst_len) + dst_len);
}

// size_t	test_i_strlcat(char *dst1, char *dst2, int len, const char *src)
// {
// 	size_t r1;
// 	size_t r2;

// 	r1 = strlcat(dst1, src, len);
// 	r2 = ft_strlcat_true(dst2, src, len);
// 	if (r1 == r2)
// 	{
// 		printf("\nstrlcat OK\n");
// 	}
// 	else
// 	{
// 		printf("\nstrlcat KO\n");
// 	}

// 	dprintf(1, "[%s](%lu)\n[%s](%lu)\n[%s]\n\n", dst1, r1, dst2, r2, src);
// 	return (r2);
// }

// size_t	ft_strlcat(char *dst1, const char *src, size_t dst_len_mx)
// {
// 	size_t	dstsize;
// 	char*	dst2;

// 	dstsize = ft_strlen(dst1);
// 	dst2 = malloc(sizeof(char) * dstsize);
// 	size_t r2 = ft_strlcpy(dst2, dst1, dstsize);

// 	test_i_strlcat(dst1, dst2, dst_len_mx, src);
// 	dprintf(1,"PWETTTTTT %lu\n", dst_len_mx);

// 	free(dst2);
// 	return (r2);
// }
