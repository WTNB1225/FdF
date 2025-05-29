/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:45:57 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 03:55:09 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_set(char const *set, char c)
{
	size_t	set_len;
	size_t	i;

	set_len = ft_strlen(set);
	i = 0;
	while (i < set_len)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (is_set(set, s1[start]))
		start++;
	while (is_set(set, s1[end]) && start < end)
		end--;
	ptr = (char *)malloc(sizeof(char) * (end - start + 1 + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char *s1 = "--hogehgoe--";
	char *ret = ft_strtrim(s1, NULL);
	printf("%s\n", ret);
	free(ret);
	char *ret2 = ft_strtrim("", "");
	printf("%s\n", ret);
	free(ret2);
}
*/
