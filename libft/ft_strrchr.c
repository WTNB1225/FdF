/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:13:42 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 02:27:31 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	while (i > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		i--;
		s--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

/*
#include <string.h>
#include <assert.h>
int main(void)
{
	const char *str = "abcde";
	char target = 'a';
	char *r1;
	char *r2;
	r1 = strrchr(str, target);
	r2 = ft_strrchr(str, target);
	assert(r1 == r2);

	target = 'c';
	r1 = strrchr(str, target);
	r2 = ft_strrchr(str, target);
	assert(r1 == r2);

	target = 'x';
	r1 = strrchr(str, target);
	r2 = ft_strrchr(str, target);
	assert(r1 == r2);

	target = '\0';
	r1 = strrchr(str, target);
	r2 = ft_strrchr(str, target);
	assert(r1 == r2);

	const char *str2 = "";
	target = 'a';
	r1 = strrchr(str2, target);
	r2 = ft_strrchr(str2, target);
	assert(r1 == r2);

	str2 = "";
	target = '\0';
	r1 = strrchr(str2, target);
	r2 = ft_strrchr(str2, target);
	assert(r1 == r2);
	strrchr(NULL, 0);
	ft_strrchr(NULL, 0);
	strrchr(NULL, 1);
	ft_strrchr(NULL, 1);
}
*/
