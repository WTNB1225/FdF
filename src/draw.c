/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 09:25:28 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/02 21:09:20 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= WINDOW_WIDTH || y >= WINDOW_HEIGHT || x < 0 || y < 0)
		return ;
	dst = data->addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw(t_data *data, t_map *map, int color)
{
	size_t	i;
	size_t	j;
	size_t	idx;

	j = 0;
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			idx = map->height * j + i;
			ft_printf("[x: %d, y: %d]\n", map->coord_x[idx], map->coord_y[idx]);
			my_mlx_pixel_put(data, map->coord_x[idx], map->coord_y[idx], color);
			i++;
		}
		j++;
	}
}


void	init_mlx(t_map *map)
{
	void	*mlx_win;
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_WIDTH, "fdf");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.size_line,
			&img.endian);
	draw(&img, map, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
