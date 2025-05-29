/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:46:39 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 03:33:20 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	bytes = nmemb * size;
	if (size != 0 && !(bytes / size == nmemb))
		return (NULL);
	ptr = malloc(bytes);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}

/*
#include <assert.h>
#include <string.h>
#include <stdint.h>
#include <limits.h>
int main(void)
{
	printf("%zu\n", SIZE_MAX);
	printf("%zu\n", SIZE_MAX * SIZE_MAX);
	printf("%p\n", calloc(-5, -5));
	printf("%p\n", ft_calloc(-5, -5));
	printf("%p\n", calloc(0, 0));
	printf("%p\n", ft_calloc(0, 0));
	printf("%p\n", calloc(0, INT_MAX));
	printf("%p\n", ft_calloc(0, INT_MAX));
	printf("%p\n", calloc(INT_MIN, INT_MIN));
	printf("%p\n", ft_calloc(INT_MIN, INT_MIN));
	printf("%p\n", calloc(SIZE_MAX, SIZE_MAX));
	printf("%p\n", ft_calloc(SIZE_MAX, SIZE_MAX));
	int	*arr = (int *)ft_calloc(4, sizeof(int));
	int zero_array[4] = {0};
	assert(memcmp(arr, zero_array, 4 * sizeof(int)) == 0);
	free(arr);
}
*/
