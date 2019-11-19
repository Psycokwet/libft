/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/19 13:06:53 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

typedef struct substr_test_data_struct
{
	char *s;
	int start;
	int len;
	char *s_good;
} *s_substr_test_datas, s_substr_test_data;


int test_substr(s_substr_test_datas sample_data, int i)
{
	if(strcmp(ft_substr(sample_data->s, sample_data->start, sample_data->len), sample_data->s_good))
	{
		printf("test_substr No [%d] KO for [%s][%d][%d], expected [%s]\n", i, sample_data->s, sample_data->start, sample_data->len, sample_data->s_good);
		return -1;
	}
	return 0;
}

int test_substr_int(void)
{
	int i = 0;
	int j = 0;
	int m = 0;
	int size_len = 4;
	int size_start = 3;
	int size_str = 4;
	int size_datas = size_str * size_start * size_len;
	
	s_substr_test_datas *substr_datas;
	substr_datas = (s_substr_test_datas *)(malloc(sizeof(s_substr_test_datas) * size_datas));
	
	char *s_goods[48] =
	{
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"E",
		"Ex",
		"Extra",
		"",
		"c",
		"ct",
		"ct fr",
		"",
		"",
		"",
		"",
		"",
		"a",
		"ab",
		"abc",
		"",
		"'",
		"'m",
		"'m Hi",
		"",
		"e",
		"e ",
		"e too",
		"",
		"a",
		"ab",
		"abcde",
		"",
		"f",
		"fe",
		"fef",
		"",
		"",
		"",
		"",
	};
	char *str[4] =
	{
		"",
		"Extract from me",
		"abc\0I'm Hidden ! \0Me too",
		"abcdefef",
	};
	int len[4] =
	{
		0,
		1,
		2,
		5
	};
	int start[4][3] =
	{
		{
			0,
			0,
			0
		},
		{
			0,
			5,
			ft_strlen(str[1])
		},
		{
			0,
			5,
			19
		},
		{
			0,
			5,
			ft_strlen(str[3])
		}
	};
	(void)start;
	(void)len;

	while (i < size_str)
	{
		while (j < size_start)
		{
			while (m < size_len)
			{
				int indice_datas = (i * size_start * size_len) +(j * size_len) + m;
				s_substr_test_datas sample_data = malloc(sizeof(s_substr_test_data));
				sample_data->s = str[i];
				sample_data->len = len[m];
				sample_data->start = start[i][j];
				sample_data->s_good = s_goods[indice_datas];
				substr_datas[indice_datas] = sample_data;
				//substr_datas[i + j + m] = (s_substr_test_datas)(malloc(sizeof(s_substr_test_datas) * size_datas));
				//printf("test No [%d][%d][%d]\n", i, j, m);
				m++;
			}
			m = 0;
			j++;
		}
		j = 0;
		i++;
	}
	i = 0;
	int r = 0;
	while ( i < size_datas)
	{
		r = test_substr(substr_datas[i], i) + r;
		i++;
	}
	return r;
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	printf("test_substr... [%d] errors", -test_substr_int());
	return (0);
}
