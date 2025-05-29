/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:52:53 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 23:35:45 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*extract_line(char *backup)
{
	size_t	i;
	char	*line;

	if (backup == NULL || backup[0] == '\0')
		return (NULL);
	i = 0;
	while (backup[i] != '\n' && backup[i])
		i++;
	line = ft_substr(backup, 0, i);
	return (line);
}

static char	*make_new_backup(char *backup)
{
	size_t	i;
	size_t	len;
	char	*new_backup;

	if (backup == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(backup);
	while (backup[i] && backup[i] != '\n')
		i++;
	if (backup[i] == '\n')
		i++;
	new_backup = ft_substr(backup, i, len - i);
	free(backup);
	return (new_backup);
}

static char	*read_file(int fd, char *backup)
{
	int		read_rtn;
	char	*buf;

	read_rtn = 1;
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(backup);
		return (NULL);
	}
	while (read_rtn != 0 && !ft_strchr(backup, '\n'))
	{
		read_rtn = read(fd, buf, BUFFER_SIZE);
		if (read_rtn == -1)
		{
			free(backup);
			free(buf);
			return (NULL);
		}
		buf[read_rtn] = '\0';
		backup = ft_strjoin(backup, buf);
	}
	free(buf);
	return (backup);
}

static void	remove_fd_node(t_fd_node **head, int fd)
{
	t_fd_node	*current;
	t_fd_node	*prev;

	current = *head;
	prev = NULL;
	while (current)
	{
		if (current->fd == fd)
		{
			if (prev)
				prev->next = current->next;
			else
				*head = current->next;
			free(current->backup);
			current->backup = NULL;
			free(current);
			return ;
		}
		prev = current;
		current = current->next;
	}
}

char	*get_next_line(int fd)
{
	static t_fd_node	*head;
	t_fd_node			*current;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	current = get_fd_node(&head, fd);
	if (current == NULL)
		return (NULL);
	current->backup = read_file(fd, current->backup);
	line = extract_line(current->backup);
	if (line == NULL || line[0] == '\0')
	{
		free(line);
		remove_fd_node(&head, fd);
		return (NULL);
	}
	current->backup = make_new_backup(current->backup);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>
// #include <stdlib.h>
// #include <unistd.h>

// #define FILE_COUNT 3

// int	main(void)
// {
// 	const char	*files[FILE_COUNT] = {"test.txt", "test2.txt", "test3.txt"};
// 	int			fds[FILE_COUNT];
// 	char		*line;
// 	int			i = 0;
// 	int			j = 0;

// 	while (i < FILE_COUNT)
// 	{
// 		fds[i] = open(files[i], O_RDONLY);
// 		if (fds[i] < 0)
// 		{
// 			perror("open");
// 			return (1);
// 		}
// 		i++;
// 	}
// 	while (j < 100)
// 	{
// 		i = 0;
// 		while (i < FILE_COUNT)
// 		{
// 			line = get_next_line(fds[i]);
// 			if (line)
// 			{
// 				printf("fd%d (%s): %s", fds[i], files[i], line);
// 				free(line);
// 			}
// 			i++;
// 		}
// 		j++;
// 	}
// 	i = 0;
// 	while (i < FILE_COUNT)
// 	{
// 		close(fds[i]);
// 		i++;
// 	}

// 	return (0);
// }
