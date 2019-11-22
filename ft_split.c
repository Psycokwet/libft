/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/22 14:56:57 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int		get_jump(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	return (i);
}

static int		get_size_fragment(char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strdup_int(const char *src, size_t len)
{
	char	*dst;

	dst = malloc(len * sizeof(char));
	if (dst)
		ft_strlcpy(dst, src, len);
	return (dst);
}

static char	*ft_strldup(const char *src, size_t len)
{
	return (ft_strdup_int(src, len));
}

typedef struct node 
{
	size_t start;
	size_t size_fragment;
	struct node *next;
} *s_p_substr, s_substr;

s_p_substr append_substr_datas(s_p_substr head, s_p_substr queue)
{
	if(!head)
		return NULL;
	head->next = queue;
	return queue;
}


s_p_substr init_substr_datas(size_t start, size_t size_fragment)
{
	s_p_substr new_sub;
	new_sub = (s_p_substr)malloc(sizeof(s_substr));
	if(!new_sub)
		return (new_sub);
	new_sub->start = start;
	new_sub->size_fragment = size_fragment;
	new_sub->next = NULL;
	return (new_sub);
}

void free_list(s_p_substr list)
{
	if(list->next)
		free_list(list->next);
	free(list);
}
// void print_list(s_p_substr list)
// {
// 	printf("List_elem [%lu][%lu][%p]\n", list->start, list->size_fragment, (void*)list->next);
// 	if(list->next)
// 		print_list(list->next);		
// }

s_p_substr get_split_datas(int *n_of_split, const char *s, char c, size_t size_s)
{
	s_p_substr list_substr;
	s_p_substr last_sub;
	size_t i, size_fragment, jump;
	
	size_fragment = 0;
	jump = get_jump(s, c);
	i = jump;
	if(i == size_s)
		return NULL;
	if(i < size_s)
	{
		size_fragment = get_size_fragment(s + i, c);
		last_sub = init_substr_datas(i, size_fragment);
		list_substr = last_sub;
		(*n_of_split)++;
	}
	i = i + size_fragment;
	while (i < size_s)
	{
		jump = get_jump(s + i, c);
		i += jump;
		if (i == size_s)
			return (list_substr);
		size_fragment = get_size_fragment(s + i, c);
		last_sub = append_substr_datas(last_sub, init_substr_datas(i, size_fragment));
		(*n_of_split)++;
		i = i + size_fragment +1;
	}
	return (list_substr);
}

char		**fill_splitted(s_p_substr list_substr, const char* s, int n_of_split)
{
	char **splitted;
	int i;
	
	i = 0;
	splitted = (char**)malloc(sizeof(char*) * n_of_split);
	if(!splitted)
		return (NULL);
	while (list_substr)
	{
		splitted[i] = ft_strldup(&s[list_substr->start], list_substr->size_fragment + 1);
		list_substr = list_substr->next;
		i++;
	}
	splitted[i] = NULL;
	return (splitted);
}

// void print_splitted(char **splitted)
// {
// 	int i;
// 	i=-1;
// 	printf("print splited\n");

// 	while (splitted[++i] != NULL)
// 		printf("print [%d][%s]\n", i, splitted[i]);
// }

char		**ft_split(char const *s, char c)
{
	int n_of_split, i;
	size_t size_s;
	char **splitted;
	s_p_substr list_substr;

	if(!s)
		return NULL;
	n_of_split = 0;
	i = 0;
	size_s = ft_strlen(s);
	list_substr = get_split_datas(&n_of_split, s, c, size_s);
	if(!list_substr)
	{
		char **splitted;
		splitted = (char**)malloc(sizeof(char*));
		if(splitted)
			splitted[0] = NULL;
		return (splitted);
	}
	splitted = fill_splitted(list_substr, s, n_of_split);
	free_list(list_substr);
	return splitted;
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
