/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/22 11:11:41 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static char	*ft_strdup_int(const char *src, size_t len)
{
	char	*dst;

	dst = malloc(len * sizeof(char));
	if (dst != NULL)
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
	struct node *next;
} *s_p_substr, s_substr;

s_p_substr append_substr_datas(s_p_substr head, s_p_substr queue)
{
	if(!head)
		return NULL;
	head->next = queue;
	return queue;
}


s_p_substr init_substr_datas(size_t start)
{
	s_p_substr new_sub;
	new_sub = (s_p_substr)malloc(sizeof(s_substr));
	new_sub->start = start;
	new_sub->next = NULL;

	return (new_sub);
}

void free_list(s_p_substr list)
{

		printf("Bye bob\n");
	if(list->next)
		free_list(list->next);
	free(list);
}
void print_list(s_p_substr list)
{
	printf("List_elem [%lu][%p]\n", list->start, (void*)list->next);
	if(list->next)
		print_list(list->next);		
}

s_p_substr get_split_datas(int *n_of_split, const char *s, char c, size_t size_s)
{
	s_p_substr list_substr;
	s_p_substr last_sub;
	size_t i;
	
	i = 0;	
	last_sub = init_substr_datas(i);
	list_substr = last_sub;
	while (i < size_s)
	{
		if (s[i] == c)
		{
			last_sub = append_substr_datas(last_sub, init_substr_datas(i));
			(*n_of_split)++;
		}
		i++;
	}
	return list_substr;
}

char		**fill_splitted(s_p_substr list_substr, const char* s, int n_of_split)
{
	char **splitted;
	size_t start;
	size_t end;

	splitted = (char**)malloc(sizeof(char*) * n_of_split);

	while (list_substr)
	{
		end = list_substr->start;
		ft_strldup(&s[start], end);

		start = list_substr->start;
		list_substr = list_substr->next;
		printf("ah que cucou bob\n");
	}
	splitted[n_of_split - 1] = NULL;
	return (splitted);
}

char		**ft_split(char const *s, char c)
{
	if(!s)
		return NULL;
	int n_of_split, i;
	size_t size_s;
	char **splitted;
	s_p_substr list_substr;
	
	n_of_split = 1;
	i = 0;
	size_s = ft_strlen(s);
	list_substr = get_split_datas(&n_of_split, s, c, size_s);
	//printf("n_of_split [%d][%s][%c]\n", n_of_split, s, c);
	//print_list(list_substr);
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
