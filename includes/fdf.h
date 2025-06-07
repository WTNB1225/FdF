/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 03:36:27 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/06 19:15:19 by wyuki            ###   ########.fr       */
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
	float	*coord_x;
	float	*coord_y;
	int		*alt;
	int		min_width;
	int		max_width;
	int		min_height;
	int		max_height;
	unsigned int	*color;
}	t_map;

typedef struct s_data
{
	void	*img;
	void	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

size_t	get_height(const char *filename);
size_t	get_width(const char *filename);
int		*get_altitude(const char *filename, t_map *map);
void	read_file(const char *filename, t_map *map);
unsigned int		*get_color(const char *filename, t_map *map);

float	get_rad(int degree);

void	set_coord(t_map *map);
void	set_max(t_map *map);
void	isometric(t_map *map);
int		get_tile_size(t_map *map);
int		on_esc(int keycode, t_vars *vars);

void	exit_error(char *msg, bool is_syscall);
void	init_mlx(t_vars *vars);

void	draw(t_data *data, t_map *map);
#endif
