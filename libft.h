/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:14:23 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/18 12:05:09 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

void	*ft_memset(void *memory_space, int value, size_t len);

void	ft_bzero(void *memory_space, size_t len);

void	*ft_memcpy(void *dst, const void *src, size_t len);

void	*ft_memccpy(void *dst, const void *src, int c, size_t len);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memchr(const void *s, int c, size_t len);

int		ft_memcmp(const void *s1, const void *s2, size_t len);

size_t	ft_strlen(const char *s);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_isalnum(int c);

int		ft_isascii(int c);

int		ft_isprint(int c);

int		ft_toupper(int c);

int		ft_tolower(int c);

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c);

int		ft_strncmp(const char *s1, const char *s2, size_t len_mx);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

int		ft_atoi(const char *str);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *src);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
