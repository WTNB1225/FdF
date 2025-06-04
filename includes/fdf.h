/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:36:27 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/04 16:21:23 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080

typedef struct s_map
{
	size_t	height;
	size_t	width;
	float		*coord_x;
	float		*coord_y;
	int		*alt;
	int		min_width;
	int		max_width;
	int		min_height;
	int		max_height;
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

float	get_rad(int degree);

void	set_coord(t_map *map);
void	set_max(t_map *map);
void	isometric(t_map *map);
int		get_tile_size(t_map *map);

void	exit_error(char *msg, bool is_syscall);
void	init_mlx(t_map *map);
#endif
