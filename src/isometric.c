/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 18:24:00 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/02 19:49:09 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(t_map *map)
{
	int	j;
	int	i;
	int		*coord_x;
	int		*coord_y;
	int		idx;

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
			coord_x[idx] =  WINDOW_WIDTH / 2 + (((i - j) * cos(get_rad(30)))) * 20;
			coord_y[idx] =  WINDOW_HEIGHT / 2 + ((i + j) * sin(get_rad(30)) - map->alt[idx]) * 20;
			i++;
		}
		j++;
	}
	map->coord_x = coord_x;
	map->coord_y = coord_y;
}
