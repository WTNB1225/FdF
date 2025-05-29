/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 15:20:21 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 03:18:33 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
#include <assert.h>
#include <bsd/string.h>
int	main(void)
{
	char *hoge = "hogehoge";
	//char dest[100];
	//char dest2[100];
	//printf("%zu\n",ft_strlcpy(dest, hoge, 0));
	//printf("%zu\n",strlcpy(dest2, hoge, 0));
	//printf("%s\n", dest);
	//printf("%s\n", dest2);
	ft_strlcpy(NULL, hoge, 2);
}
*/
