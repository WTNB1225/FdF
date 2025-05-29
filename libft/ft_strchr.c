/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:03:27 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 02:38:44 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
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
	r1 = strchr(str, target);
	r2 = ft_strchr(str, target);
	assert(r1 == r2);

	target = 'c';
	r1 = strchr(str, target);
	r2 = ft_strchr(str, target);
	assert(r1 == r2);

	target = 'x';
	r1 = strchr(str, target);
	r2 = ft_strchr(str, target);
	assert(r1 == r2);

	target = '\0';
	r1 = strchr(str, target);
	r2 = ft_strchr(str, target);
	assert(r1 == r2);

	const char *str2 = "";
	target = 'a';
	r1 = strchr(str2, target);
	r2 = ft_strchr(str2, target);
	assert(r1 == r2);

	str2 = "";
	target = '\0';
	r1 = strchr(str2, target);
	r2 = ft_strchr(str2, target);
	assert(r1 == r2);
	strchr(NULL, 0);
	ft_strchr(NULL, 0);
	strchr(NULL, 1);
	ft_strchr(NULL, 1);
}
*/
