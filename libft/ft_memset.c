/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:55:07 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 01:51:22 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)dest;
	while (i < n)
	{
		ptr[i++] = (unsigned char)c;
	}
	return (dest);
}

/*
#include <string.h>
#include <assert.h>
int main(void)
{
	char buf1[10], buf2[10];
	memset(buf1, 'a', sizeof(buf1));
	ft_memset(buf2, 'a', sizeof(buf2));
	assert(memcmp(buf1, buf2, sizeof(buf1)) == 0);
	char b3[5] = "hoge";
	char b4[5] = "hoge";
	memset(b3, 'a', (size_t)0);
	ft_memset(b4, 'a', (size_t)0);
	assert(memcmp(b3, b4, sizeof(b3)) == 0);
	memset(NULL, 'a', (size_t)0);
	ft_memset(NULL, 'a', (size_t)0);
	//segmentation fauld except size equal 0
	//memset(NULL, 'a', 1);
	//ft_memset(NULL, 'a', 1);
}
*/
