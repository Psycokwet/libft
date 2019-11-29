/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/29 14:49:31 by scarboni         ###   ########.fr       */
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

int test_putnbr_fd(int i_expect, int i)
{
	printf("test_putnbr_fd visual No [%d], expected [%d]\n", i, i_expect);
	ft_putnbr_fd(i_expect, 1);
	printf("\n");
	//if(strcmp(result, s_expect))
	// {
	// 	printf("test_itoa No [%d] KO for [%s], expected [%s]\n", i, result, s_expect);
	// 	return -1;
	// }
	return 0;
}

int test_putnbr_fd_int(void)
{
	int i = 0;

	const int MAX = 10;
	int i_expected[10] =
	{
		0,
		9,
		-9,
		10,
		-10,
		8124,
		-9874,
		543000,
		-2147483648LL,
		2147483647,
	};
	int r = 0;
	while (i < MAX)
	{
		r += test_putnbr_fd(i_expected[i], i);
		i++;
	}
	return r;
}
int test_itoa(char* s_expect, int i_expect, int i)
{
	char* result = ft_itoa(i_expect);
	if(strcmp(result, s_expect))
	{
		printf("test_itoa No [%d] KO for [%s], expected [%s]\n", i, result, s_expect);
		return -1;
	}
	return 0;
}

int test_itoa_int(void)
{
	int i = 0;

	const int MAX = 10;
	char *s_expected[10] =
	{
		"0",
		"9",
		"-9",
		"10",
		"-10",
		"8124",
		"-9874",
		"543000",
		"-2147483648",
		"2147483647"
	};
	int i_expected[10] =
	{
		0,
		9,
		-9,
		10,
		-10,
		8124,
		-9874,
		543000,
		-2147483648LL,
		2147483647,
	};
	int r = 0;
	while (i < MAX)
	{
		r += test_itoa(s_expected[i],i_expected[i], i);
		i++;
	}
	return r;
}

int test_substr(s_substr_test_datas sample_data, int i)
{
	char *res = ft_substr(sample_data->s, sample_data->start, sample_data->len);
	if(res == sample_data->s_good && !res)
		return 0;
	else if(!res || !sample_data->s_good)
	{
		printf("atest_substr No [%d] KO for [%s][%d][%d], expected [%s], got [%s]\n", i, sample_data->s, sample_data->start, sample_data->len, sample_data->s_good, res);
		return -1;
	}
	if(strcmp(res, sample_data->s_good))
	{
		printf("test_substr No [%d] KO for [%s][%d][%d], expected [%s], got [%s]\n", i, sample_data->s, sample_data->start, sample_data->len, sample_data->s_good, res);
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
		NULL,
		NULL,
		NULL,
		"",
		NULL,
		NULL,
		NULL,
		"",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		"",
		"c",
		"ct",
		"ct fr",
		"",
		NULL,
		NULL,
		NULL,
		"",
		"a",
		"ab",
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		"",
		"a",
		"ab",
		"abcde",
		"",
		"e",
		"ef",
		NULL,
		"",
		NULL,
		NULL,
		NULL,
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
			20,
			5,
			ft_strlen(str[1])
		},
		{
			0,
			4,
			19
		},
		{
			0,
			4,
			ft_strlen(str[3])
		}
	};
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


int test_strjoin(char *s1, char *s2, char *s_finale, int i)
{
	if(strcmp(ft_strjoin(s1, s2), s_finale))
	{
		printf("test_strjoin No [%d] KO for [%s][%s], expected [%s]\n", i, s1, s2, s_finale);
		return -1;
	}
	return 0;
}

int test_strjoin_int(void)
{
	int i = 0;

	const int MAX = 5;
	char *s_finales[5] =
	{
		"",
		"2",
		"1",
		"12",
		"Hey  Ho !",
	};

	char *s1[5] =
	{
		"",
		"",
		"1",
		"1",
		"Hey ",
	};
	char *s2[5] =
	{
		"",
		"2",
		"",
		"2",
		" Ho !",
	};

	int r = 0;
	while (i < MAX)
	{
		r = test_strjoin(s1[i], s2[i], s_finales[i], i) + r;
		i++;
	}
	return r;
}


int test_split(char *s, char sep, char *s_finale, int i)
{
	char **result = ft_split(s, sep);
	int k = 0;
	int kk = 0;
	int j = 0;

	while(result[k] != NULL)
	{
		while(result[k][kk] != '\0')
		{
			if(result[k][kk] != s_finale[j])
			{
				printf("test_split No [%d] KO for [%s][%c], expected [%c], got [%c]\n", i, s, sep, s_finale[j], result[k][kk]);
				
				printf("[");
				k  = 0;
				while(result[k] != NULL)
				{
					printf("\t[%s]\n", result[k]);
					k++;
				}
				printf("\t[%s]\n", result[k]);
				printf("]\n");
				return -1;
			}
			j++;
			kk++;
		}
		kk = 0;
		k++;
	}
	return 0;
}

int test_split_int(void)
{
	int i = 0;

	const int MAX = 5;
	char *s_finales[5] =
	{
		"MAKELIBFTGREATAGAIN!",
		"",
		"MAKELIBFTGREATAGAIN!",
		"MAKELIBFTGREATAGAIN!",
		"MAKELIBFTGREATAGAIN!",
	};

	char *s[5] =
	{
		"M-A-K-E-L-I-B-F-T-G-R-E-A-T-A-G-A-I-N-!-",
		"",
		"M-----A-K-E-L-I-B-F-T-G------R-E-A-T-A-G-A-I------N-!-",
		"------M-A-K-E-L-I-B------F-T-G-R-E-A-----T-A-G-A-I-N-!------",
		"MAKELIBFTGREATAGAIN!",
	};
	int r = 0;
	while (i < MAX)
	{
		r = test_split(s[i], '-', s_finales[i], i) + r;
		i++;
	}
	r = test_split("      split       this for   me  !       ", ' ', "splitthisforme!", i) + r;
	return r;
}

int test_strtrim(char *s, char *set, char *s_finale, int i)
{
	char *result = ft_strtrim(s, set);
	if(strcmp(result, s_finale))
	{
		printf("test_strjoin No [%d] KO for [%s][%s], expected [%s], got [%s]\n", i, s, set, s_finale, result);
		return -1;
	}
	return 0;
}

int test_strtrim_int(void)
{
	int i = 0;

	const int MAX = 8;
	char *s_finales[8] =
	{
		"Hello \t  Please\n Trim me !",
		"",
		"Hello \t  Please\n Trim me !",
		"Hello \t ça va ?",
		"Ah que coucou bob !",
		"lolilol\n\n\n!",
		"Hmmmm",
		"Hey ",
	};

	char *s[8] =
	{
		"   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ",
		"  \t \t \n   \n\n\n\t",
		"   \t  \n\n \t\t  \n\n\nHello \t  Please\n Trim me !\n   \n \n \t\t\n  ",
		"Hello \t ça va ?",
		"Ah que coucou bob !",
		"\n\n\n\t\t\r       lolilol\n\n\n!",
		"Hmmmm",
		"Hey ",
	};
	char *set[8] =
	{
		" \n\t",
		" \n\t",
		" \n\t",
		"\t",
		" ",
		"\n\t\r ",
		"",
		NULL,
	};

	int r = 0;
	while (i < MAX)
	{
		r = test_strtrim(s[i], set[i], s_finales[i], i) + r;
		i++;
	}
	return r;
}

void print_errors(char * function_name, int n_errors)
{
	printf("%s... \t[%d] errors detected\n", function_name, -n_errors);
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	print_errors("ft_substr", test_substr_int());
	print_errors("ft_strjoin", test_strjoin_int());
	print_errors("ft_strtrim", test_strtrim_int());
	print_errors("ft_itoa", test_itoa_int());
	print_errors("ft_putnbr_fd", test_putnbr_fd_int());
	print_errors("test_split_int", test_split_int());
	return (0);
}
