/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:35:09 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 03:34:37 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;
	size_t	loop_len;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	len = ft_strlen(dst);
	i = 0;
	loop_len = size - len - 1;
	if (len >= size)
		return (size + ft_strlen(src));
	while (i < loop_len)
	{
		if (src[i] == '\0')
			break ;
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (len + ft_strlen(src));
}

/*
#include <stdio.h>
#include <bsd/string.h>
int main(void)
{
	//ft_strlcat(NULL, "WORLD", 1);
	char dest1[100] = "hoge";
	char dest2[100] = "hoge";
	char dest3[20] = "ABCDE";
	char dest4[20] = "ABCDE";
	//char src[] = "foobar";
	//char src2[] = "1234";
	//printf("%zu\n", strlcat((void *)0,src2,3));
	//strlcat((void *)0,src2,4);
	//ft_strlcat((void *)0,src2,4);
//printf("dest1=%d,dest2=%zu\n",ft_strlcat(dest1,src,7),strlcat(dest2,src,7));
//printf("dest3=%d,dest4=%zu\n",ft_strlcat(dest1,src2,0),strlcat(dest2,src2,0));
	puts(dest1);
	puts(dest2);
	puts(dest3);
	puts(dest4);
	return (0);
}
*/
