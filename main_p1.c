/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scarboni <scarboni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 10:38:18 by scarboni          #+#    #+#             */
/*   Updated: 2019/11/19 10:10:34 by scarboni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "libft.h"

void mem_test();
void *ft_memset(void *b, int c, size_t len);

//
void test_is_all(char c)
{
	printf("test for %c\n", c);
	if(isalpha(c) != ft_isalpha(c)){
		printf("ft_isalpha %c: %d : %d\n", c, isalpha(c),ft_isalpha(c));
	}
	if(isdigit(c) != ft_isdigit(c)){
		printf("ft_isdigit %c: %d : %d\n", c, isdigit(c),ft_isdigit(c));
	}
	if(isalnum(c) != ft_isalnum(c)){
		printf("ft_isalnum %c: %d : %d\n", c, isalnum(c),ft_isalnum(c));
	}
	if(isascii(c) !=ft_isascii(c)){
		printf("ft_isascii %c: %d : %d\n", c, isascii(c),ft_isascii(c));
	}
	if(isprint(c) !=ft_isprint(c)){
		printf("ft_isprint %c: %d : %d\n", c, isprint(c),ft_isprint(c));
	}
	if(toupper(c) !=ft_toupper(c)){
		printf("ft_toupper %c: %c : %c\n", c, toupper(c),ft_toupper(c));
	}
	if(tolower(c) !=ft_tolower(c)){
		printf("ft_tolower %c: %c : %c\n", c, tolower(c),ft_tolower(c));
	}
} 
//
void test_c_s_all(char c, char *s)
{
	printf("test for %c;%s\n", c, s);
	char *r1;
	char *r2;
	
	r1 = strchr(s, c);
	r2 = ft_strchr(s, c);
	if (r1 == r2)
	{
		printf("ft_strchr : OK\n");
	}
	else{
		printf("ft_strchr : KO\n");
	}
	
	r1 = strrchr(s, c);
	r2 = ft_strrchr(s, c);
	if (r1 == r2)
	{
		printf("ft_strrchr : OK\n");
	}
	else{
		printf("ft_strrchr : KO\n");
	}
} 
//
void test_memcpy(void *dst1, void *dst2, void *src1, size_t len)
{
	printf("test for ft_memcpy %s;%s;%s;%lu\n", dst1, dst2, src1, len);
	
	dst1 = memcpy(dst1,src1,len);
	dst2 = ft_memcpy(dst2,src1,len);
	printf("%s:\n%s:\n", dst1, dst2);
}
//
void test_memccpy(void *dst1, void *dst2, void *src, int value, size_t len)
{
	printf("test for ft_memccpy %s;%s;%s;%c,%lu\n", dst1, dst2, src, value, len);
	
	dst1 = memccpy(dst1,src,value,len);
	dst2 = ft_memccpy(dst2,src,value,len);
	printf("%s:\n%s:\n", dst1, dst2);
}
//
void test_memset(void *dst1, void *dst2, int value, size_t len)
{
	printf("test for ft_memset %s;%s;%d;%lu\n", dst1, dst2, value, len);
	
	dst1 = memset(dst1, value, len);
	dst2 = ft_memset(dst2, value, len);

	((unsigned char* )dst1)[len] = '\0';
	((unsigned char* )dst2)[len] = '\0';
	printf("%s:\n%s:\n", dst1, dst2);
}
//
void test_bzero(unsigned char *s, size_t len)
{
	size_t i = 0;
	bzero(s, 1);
	while(i<len)
	{
		printf("-%c;", s[i]);
		i++;
	}
	printf(";\n");
	i = 0;
	
    s = ft_memset( s, 'b', len);
	ft_bzero(s, 1);
	while(i<len)
	{
		printf("-%c;", s[i]);
		i++;
	}
	printf(";\n");
}
//
void test_memchr(void *s, int c, size_t len)
{
	if(memchr(s,  c,  len) == ft_memchr(s,  c,  len))
	{
		printf("ft_memchr : OK\n");
	}else{
		printf("ft_memchr : KO\n");
	}
}
//
void test_strncmp(void *s1, void *s2, size_t len)
{
	int r1;
	int r2;

	r1 = strncmp(s1,  s2,  len);
	r2 = ft_strncmp(s1,  s2,  len);
	if (r1 == r2)
	{
		printf("ft_strncmp : OK\n");
	}else{
		printf("ft_strncmp : KO %d:%d\n", r1, r2);
	}
}

void test_memcmp(void *s1, void *s2, size_t len)
{
	if(memcmp(s1,  s2,  len) == memcmp(s1,  s2,  len))
	{
		printf("ft_memcmp : OK\n");
	}else{
		printf("ft_memcmp : KO\n");
	}
}
//
void mem_test(){
	size_t len;
	
	len = 10;
	unsigned char* tst = ft_calloc(len, sizeof(char));
	unsigned char* tstcpy = ft_calloc(len, sizeof(char));

	int ft = 'a';
	test_memset(tst, tstcpy, ft, len);
	ft = 'b';
	test_memset(tst, tstcpy, ft, len);
	test_bzero(tst, len);

	test_memcpy(tst, tstcpy, "Hello", 2);
	test_memcpy(tst, tstcpy, "Pony", 2);
	test_memccpy(tst, tstcpy, "Hello", 'e', 4);
	test_memccpy(tst, tstcpy, "Pony", 'y', 4);

	//memmove
	ft_memcpy(tstcpy, "Helo;", 4);
	memmove(tstcpy + 1 , tstcpy, 4);
	printf("memmove : %s;\n", tstcpy);
	
	ft_memcpy(tstcpy, "Pony;", 4);
	ft_memmove(tstcpy + 1, tstcpy, 4);
	printf("ft_memmove : %s;\n", tstcpy);

	ft_memcpy(tstcpy, "Helo;", 4);
	memmove(tstcpy  , tstcpy+ 1, 4);
	printf("memmove : %s;\n", tstcpy);
	
	ft_memcpy(tstcpy, "Pony;", 4);
	ft_memmove(tstcpy , tstcpy+ 1, 4);
	printf("ft_memmove : %s;\n", tstcpy);

	// /memove
	test_memchr(tstcpy,  'y',  4);
	test_memchr(tstcpy,  '\0',  4);
	test_memchr(tstcpy,  'z',  4);
	
	test_memcmp("Hello",  "Helxo",  5);
	
	printf("ft_strlen : %lu : %lu\n", strlen("Hello"),ft_strlen("Hello"));

	free(tst);
	free(tstcpy);
}

void test_int_strlcat(char* dst1, char* dst2, int len, char* src)
{
	size_t r1;
	size_t r2;

	r1 = strlcat(dst1, src, len);
	r2 = ft_strlcat(dst2, src, len);
	if(r1 == r2){
		printf("strlcat OK %lu:%lu::::%s:%s\n", r1, r2, dst1, dst2);
	} else{
		printf("strlcat KO %lu:%lu::::%s:%s\n", r1, r2, dst1, dst2);
	}
}

void test_int_strlcpy(char* dst1, char* dst2, int len, char* src)
{
	size_t r1;
	size_t r2;

	r1 = strlcpy(dst1, src, len);
	r2 = ft_strlcpy(dst2, src, len);
	if(r1 == r2){
		printf("strlcpy OK %lu:%lu::::%s:%s:\n", r1, r2, dst1, dst2);
	} else{
		printf("strlcpy KO %lu:%lu::::%s:%s:\n", r1, r2, dst1, dst2);
	}
}

void test_int_strnstr(char* hs1, int len, char* needle)
{
	char *r1;
	char *r2;

	r1 = strnstr(hs1, needle, len);
	r2 = ft_strnstr(hs1, needle, len);
	if(r1 == r2){
		printf("strnstr OK %s:%s::::%s:\n", r1, r2, hs1);
	} else{
		printf("strnstr KO %s:%s::::%s:\n", r1, r2, hs1);
	}
}

void test_strlcat()
{
	size_t len;
	
	len = 40;
	char* tst = malloc(sizeof(char) * len);
	char* tstcpy = malloc(sizeof(char) * len);



	ft_bzero((void*)tst, len);
	ft_bzero((void*)tstcpy, len);
	
	test_int_strlcpy(tst, tstcpy, len, "");
	test_int_strlcpy(tst, tstcpy, len, "i am a pony");
	test_int_strlcpy(tst, tstcpy, len, "wesh poto");
	test_int_strlcpy(tst, tstcpy, len, "cool");


	ft_bzero((void*)tst, len);
	ft_bzero((void*)tstcpy, len);
	
	test_int_strlcat(tst, tstcpy, len, "");
	test_int_strlcat(tst, tstcpy, len, "i am a pony");

	test_int_strlcat(tst, tstcpy, len, "wesh poto");
	test_int_strlcat(tst, tstcpy, len, "cool");

	ft_bzero((void*)tst, len);
	ft_bzero((void*)tstcpy, len);
	test_int_strlcpy(tst, tstcpy, len, "there is no stars in the sky");
	test_int_strlcat(tst, tstcpy,23, "the cake is a lie !");
	
	test_int_strnstr(tst, len, "");
	test_int_strnstr(tst, len, "pony");
	test_int_strnstr(tst, len, "cool");

	free(tst);
	free(tstcpy);
}

void test_atoi(char* s)
{
	printf("Atoi tests [%s]:\n", s);
	printf("%d:\n", atoi(s));
	printf("%d:\n", ft_atoi(s));
	printf("\n");
}
void test_strdup(char* s)
{
	printf("%s:\n", strdup(s));
	printf("%s:\n", ft_strdup(s));
	printf("\n");
}


void test_strlcat_2()
{
	char *dest1 = malloc(100 * sizeof(char));
	char *dest2 = malloc(100 * sizeof(char));
	int ret = 0;
	int ret_1 = 0;
	int ret_2 = 0;
	char *str[4] =
	{
		"",
		"a",
		"abc",
		"abcdefef",
	};
	int size[10] =
	{
		0,
		1,
		2,
		3,
		4,
		5,
		6,
		7,
		8,
		9
	};
	dprintf(1, "Strlcat non cumulatif\n");
	for (size_t i = 0; i < 4 ; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			bzero(dest1, 100);
			bzero(dest2, 100);
			ret_1 = strlcat(dest1, str[i], size[j]);
			ret_2 = ft_strlcat(dest2, str[i], size[j]);
			ret = strcmp(dest1, dest2);
			dprintf(1, "[%s](%d)\n[%s](%d)\n=%d:%lu:%lu\n\n", dest1, ret_1, dest2, ret_2, ret, i, j);
		}
		
	}
	bzero(dest1, 100);
	bzero(dest2, 100);
	dprintf(1, "Strlcat cumulatif\n");
	for (size_t i = 0; i < 4 ; i++)
	{
		for (size_t j = 0; j < 10; j++)
		{
			ret_1 = ft_strlcat(dest1, str[i], size[j]);
			ret_2 = ft_strlcat(dest2, str[i], size[j]);
			if ((ret = strcmp(dest1, dest2)))
				dprintf(1, "[%s](%d) | [%s](%d) | %d\n", dest1, ret_1, dest2, ret_2, ret);
		}
		
	}
}

int		main(int argc, char **argv)
{
	(void)argc ;
	(void)argv ;
	
    mem_test();

	test_is_all('@');
	test_is_all('a');
	test_is_all('b');
	test_is_all('A');
	test_is_all('B');
	test_is_all('!');
	test_is_all('1');
	test_is_all('9');
	test_is_all(-1);
	test_is_all(0);
	test_is_all(127);
	
	test_c_s_all('P', "Pony");
	test_c_s_all('\0', "Pony");
	test_c_s_all('z', "Pony");
	test_c_s_all('n', "Pony");

	test_strncmp("Hello",  "Helxo",  5);
	test_strncmp("Hello",  "Hellx",  10);
	test_strncmp("Hello",  "xellx",  2);

	test_strlcat();
	test_atoi("");
	test_atoi("1337");
	test_atoi("0");
	test_atoi("-1");
	test_atoi("asdfghj");
	test_atoi("123asdfghj");
	test_atoi("asdfghj123");
	test_atoi("100 000");
	test_atoi(" 1000");
	test_atoi("2147483647");
	test_atoi("-2147483648");
	test_atoi("99999999999999999999999999");
	test_atoi("-99999999999999999999999999");
	test_atoi("+48");
	
	test_strdup("pwett");
	test_strdup("");
	test_strdup("42312");

	//test_strlcat_2();
	return (0);
}
