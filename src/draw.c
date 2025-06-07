/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:27:55 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/06 19:35:57 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(int x0, int y0, int x1, int y1, t_data *data, unsigned int color)
{
	int	sx;
	int	sy;
	int	dx;
	int	dy;
	int	err;

	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	sx = -1;
	sy = -1;
	err = dx - dy;
	if (x0 < x1)
		sx = 1;
	if (y0 < y1)
		sy = 1;
	while (1)
	{
		pixel_put(data, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break;
		int err2 = err * 2;
		if (err2 > -dy)
		{
			err -= dy;
			x0 += sx;
		}
		if (err2 < dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	draw(t_data *data, t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	idx;
	size_t	down;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			idx = map->width * j + i;
			down = map->width * (j + 1) + i;
			if (i < map->width - 1)
			{
				draw_line(map->coord_x[idx], map->coord_y[idx],
			  	map->coord_x[idx + 1], map->coord_y[idx + 1], data, map->color[idx]);
			}
			if (j < map->height - 1)
			{
				draw_line(map->coord_x[idx], map->coord_y[idx],
			  	map->coord_x[down], map->coord_y[down], data, map->color[idx]);
			}
			i++;
		}
		j++;
	}
}

void	init_mlx(t_vars *vars)
{
	void	*mlx_win;
	void	*mlx;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	vars->mlx = mlx;
	vars->win = mlx_win;
}
