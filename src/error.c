/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 19:17:11 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/29 23:54:58 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_error(char *msg, bool is_syscall)
{
	if (is_syscall)
		perror(msg);
	else
		ft_putendl_fd(msg, 2);
	exit(-1);
}
