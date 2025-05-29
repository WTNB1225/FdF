/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:45:33 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 02:57:22 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*ptr;

	if (s == NULL)
		return (NULL);
	i = 0;
	ptr = (const unsigned char *)s;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*
#include <assert.h>
#include <string.h>
void test_memchr(void) {
const char data[] = "abcdefabc";
const unsigned char bytes[] = {0x10, 0x20, 0x30, 0x40};

assert(memchr(data, 'a', sizeof(data)) == ft_memchr(data, 'a', sizeof(data)));

assert(memchr(data, 'd', sizeof(data)) == ft_memchr(data, 'd', sizeof(data)));

assert(memchr(data, 'c', sizeof(data)) == ft_memchr(data, 'c', sizeof(data)));

assert(memchr(data, 'z', sizeof(data)) == ft_memchr(data, 'z', sizeof(data)));

assert(memchr(data, 'b', 2) == ft_memchr(data, 'b', 2));

assert(memchr(data, 'a', 0) == ft_memchr(data, 'a', 0));

assert(memchr(bytes, 0x30, 4) == ft_memchr(bytes, 0x30, 4));

assert(memchr(bytes, 0x99, 4) == ft_memchr(bytes, 0x99, 4));
}

int main(void) {
    test_memchr();
    printf("All memchr tests passed.\n");
	ft_memchr(NULL, 'c', 0);
	memchr(NULL, 'c', 0);
	ft_memchr(NULL, 'c', 1);
	memchr(NULL, 'c', 1);
    return 0;
}
*/
