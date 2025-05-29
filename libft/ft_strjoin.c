/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 13:27:45 by wyuki             #+#    #+#             */
/*   Updated: 2025/04/30 03:49:35 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	ptr = (char *)malloc(sizeof(char) * (s1_len + ft_strlen(s2) + 1));
	i = -1;
	j = 0;
	if (ptr == NULL)
		return (NULL);
	while (s1[++i])
		ptr[i] = s1[i];
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*
int main(void)
{
	char *ptr = ft_strjoin("hoge", "hoge");
	printf("%s\n", ptr);
	free(ptr);
}
*/
