/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:54:20 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 23:35:54 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s != NULL && s[i])
		i++;
	return (i);
}

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

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		if (s1 == NULL)
			return (NULL);
		s1[0] = '\0';
	}
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	if (ptr == NULL)
		return (free((void *)s1), NULL);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	return (free((void *)s1), ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	s_len;
	size_t	i;
	size_t	s_start;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	s_start = ft_strlen(s + start);
	if (start >= s_len)
		len = 0;
	else if (s_start < len)
		len = s_start;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = (s + start)[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

t_fd_node	*get_fd_node(t_fd_node **head, int fd)
{
	t_fd_node	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = malloc(sizeof(t_fd_node));
	if (tmp == NULL)
		return (NULL);
	tmp->fd = fd;
	tmp->backup = NULL;
	tmp->next = *head;
	*head = tmp;
	return (tmp);
}
