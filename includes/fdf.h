/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:36:27 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/29 23:59:04 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_map
{
	size_t	height;
	size_t	width;
	int		*alt;
}	t_map;

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

size_t	get_height(const char *filename);
size_t	get_width(const char *filename);
int		*get_altitude(const char *filename, t_map *map);
void	read_file(const char *filename, t_map *map);
void	exit_error(char *msg, bool is_syscall);
void    init_mlx(t_map *map);
#endif
