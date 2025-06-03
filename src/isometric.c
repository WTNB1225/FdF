/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:00 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/04 00:26:33 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_tile_size(t_map *map, int min_width, int max_width, int min_height, int max_height)
{
	int		width_size;
	int		height_size;

	width_size = max_width - min_width;
	height_size = max_height - min_height;

	if (height_size >= WINDOW_HEIGHT)
		return (WINDOW_HEIGHT / map->height);
	else if (width_size >= WINDOW_WIDTH)
		return (WINDOW_WIDTH / map->width);
	else if (width_size < height_size)
		return (height_size / map->height);
	else
		return (width_size / map->width);
}

void	isometric(t_map *map, int *min_width, int *max_width, int *min_height,
			   int *max_height)
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
			idx = map->height * j + i;
			coord_x[idx] =  WINDOW_WIDTH / 2 + (((i - j) * cos(get_rad(30)))) * 7;
			coord_y[idx] =  WINDOW_HEIGHT / 2 + ((i + j) * sin(get_rad(30)) - map->alt[idx]) * 7;
			if (*max_width < coord_x[idx])
				*max_width = coord_x[idx];
			if (*min_width > coord_x[idx])
				*min_width = coord_x[idx];
			if (*min_height > coord_y[idx])
				*min_height = coord_y[idx];
			if (*max_height < coord_y[idx])
				*max_height = coord_x[idx];
			i++;
		}
		j++;
	}
	map->coord_x = coord_x;
	map->coord_y = coord_y;
}
