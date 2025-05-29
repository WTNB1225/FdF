/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:24:01 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 02:57:36 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <assert.h>
int main(void)
{
	char *s1 = "hogehoge";
	char *s2 = "hogahoge";
	char *s3 = "abcdefg";
	char *s4 = "abcdefghefk";
	assert(strncmp(s1, s1, 3) == ft_strncmp(s1, s1, 3));
	assert(strncmp(s1, s2, 5) == ft_strncmp(s1, s2, 5));
	assert(strncmp(s1, s1, 4) == ft_strncmp(s1, s1, 4));
	assert(strncmp(s1, s2, 7) == ft_strncmp(s1, s2, 7));
	assert(strncmp(s3, s4, 7) == ft_strncmp(s3, s4, 7));
	assert(strncmp(s3, s4, 8) == ft_strncmp(s3, s4, 8));
}
*/
