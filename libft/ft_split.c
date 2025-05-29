/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 15:26:58 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/29 05:17:09 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (*s == '\0')
		return (0);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

static char	**free_ptr(char **ptr, size_t i)
{
	size_t	idx;

	idx = 0;
	while (idx < i)
	{
		free(ptr[idx]);
		idx++;
	}
	free(ptr);
	return (NULL);
}

static size_t	get_next_word_len(char const *s, char c)
{
	size_t	word_len;

	word_len = 0;
	while (*s != c && *s)
	{
		s++;
		word_len++;
	}
	return (word_len);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	word_len;

	if (s == NULL)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		word_len = 0;
		while (*s == c)
			s++;
		if (*s == '\0')
			break ;
		word_len = get_next_word_len(s, c);
		s += word_len;
		ptr[i] = ft_substr(s - word_len, 0, word_len);
		if (ptr[i++] == NULL)
			return (free_ptr(ptr, i - 1));
	}
	ptr[i] = NULL;
	return (ptr);
}

/*
#include <stdio.h>
int main(void)
{
	printf("%zu\n", count_words("hoge,hoge,hoge", ','));
	printf("%zu\n", count_words(",,,hoge,hoge,hoge", ','));
	printf("%zu\n", count_words(",,,hoge,hoge,hoge,,", ','));
	printf("%zu\n", count_words(",,,hoge, hoge,hoge,,", '\0'));
	char **ptr = ft_split(",,,hoge, hoge,hoge,,", '\0');
	//char **ptr = ft_split(",,,hoge, hoge,hoge,,", ',');
	size_t	i;
	i = 0;
	while (ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
	free_ptr(ptr, i);
}
*/
