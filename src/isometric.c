/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:00 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/04 02:47:03 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_coord(t_map *map)
{
	int	j;
	int	i;
	int	*coord_x;
	int	*coord_y;
	int	idx;

	coord_x = (int *)malloc(sizeof(int) * (map->width * map->height));
	coord_y = (int *)malloc(sizeof(int) * (map->width * map->height));
	if (!coord_x || !coord_y)
		exit_error("Failed to allocate memory", false);
	j = 0;
	while (j < (int)map->height)
	{
		i = 0;
		while (i < (int)map->width)
		{
			idx = map->width * j + i;
			coord_x[idx] = (i - j) * cos(get_rad(30));
			coord_y[idx] = (i + j) * sin(get_rad(30)) - map->alt[idx];
			//ft_printf("[x: %d, y: %d]\n", coord_x[idx], coord_y[idx]);
			i++;
		}
		j++;
	}
	map->coord_x = coord_x;
	map->coord_y = coord_y;
}

void	isometric(t_map *map)
{
	int		tile;
	size_t	i;
	size_t	j;
	long long int		offset_x;
	long long int		offset_y;
	size_t	idx;

	j = 0;
	ft_printf("min_width: %d, max_width: %d\n", map->min_width, map->max_width);
	ft_printf("min_height: %d, max_height: %d\n", map->min_height, map->max_height);
	offset_x = (WINDOW_WIDTH / 2) - (map->max_width + map->min_width) / 2;
	offset_y = (WINDOW_HEIGHT / 2) - (map->max_height + map->min_height) / 2;
	tile = get_tile_size(map);
	ft_printf("offset_x: %d, offset_y: %d, tile: %d\n", offset_x, offset_y, tile);
	set_coord(map);
	set_max(map);
	while (j < map->height)
	{
		i = 0;
		while (i < map->width)
		{
			idx = map->width * j + i;
			//ft_printf("[x: %d, y: %d]\n", map->coord_x[idx], map->coord_y[idx]);
			map->coord_x[idx] = map->coord_x[idx] + tile + offset_x;
			map->coord_y[idx] = map->coord_y[idx] + tile + offset_y;
			//ft_printf("[x: %d, y: %d]\n", map->coord_x[idx], map->coord_y[idx]);
			i++;
		}
		j++;
	}
}
