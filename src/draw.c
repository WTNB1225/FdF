/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:25:28 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/31 09:25:28 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_draw_line(t_data *data, t_map *map, int y, int color)
{
	size_t x = 0;
	size_t dx = 1;

	while (1)
	{
		if (x >= map->width * 50)
			return ;
		my_mlx_pixel_put(data, x, y, color);
		x += dx;
	}
}

void	my_draw_line2(t_data *data, t_map *map, int x, int color)
{
	size_t y = 0;
	size_t dy = 1;

	while (1)
	{
		if (y >= map->height * 50)
			return ;
		my_mlx_pixel_put(data, x, y, color);
		y += dy;
	}
}


void	init_mlx(t_map *map)
{
	void	*mlx_win;
	void	*mlx;
	t_data	img;
	size_t	i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "fdf");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
			&img.endian);
	i = 0;
	while (i <= map->height)
	{
		my_draw_line(&img, map, i * 50, 0x00FF0000);
		i++;
	}
	i = 0;
	while (i <= map->width)
	{
		my_draw_line2(&img, map, i * 50, 0x00FF0000);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
