/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 00:56:15 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/26 15:25:17 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*ptr;

	len = ft_strlen(s);
	i = 0;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
#include <string.h>
#include <assert.h>
int	main(void)
{
	char	*src = "hogehoge";
	char	*ptr = strdup(src);
	char	*ptr2 = ft_strdup(src);
	assert(memcmp(ptr, ptr2, 8) == 0);
}
*/
