/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:52:42 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/28 23:36:17 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_fd_node
{
	char				*backup;
	int					fd;
	struct s_fd_node	*next;
}	t_fd_node;

char		*get_next_line(int fd);
size_t		ft_strlen(const char *s);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);
t_fd_node	*get_fd_node(t_fd_node **head, int fd);
#endif
