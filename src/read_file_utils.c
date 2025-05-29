/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 23:11:24 by wyuki             #+#    #+#             */
/*   Updated: 2025/05/30 00:08:57 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static size_t	count_width(char *line)
{
	size_t	width;
	char	**split;
	size_t	i;

	if (!line)
		exit_error("Failed to read the map", false);
	width = 0;
	split = ft_split(line, ' ');
	i = 0;
	while (split[i])
	{
		i++;
		width++;
	}
	i = 0;
	while (i < width)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (width);
}

static int	*line_to_int_array(const char *line, size_t width)
{
	int		*array;
	char	**split;
	size_t	i;

	array = (int *)malloc(sizeof(int) * width);
	if (!array)
		exit_error("Failed to read the map", false);
	i = 0;
	split = ft_split(line, ' ');
	while (i < width)
	{
		array[i] = ft_atoi(split[i]);
		i++;
	}
	i = 0;
	while (i < width)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (array);
}

size_t	get_height(const char *filename)
{
	size_t	height;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, true);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_error(NULL, true);
	return (height);
}

size_t	get_width(const char *filename)
{
	size_t	width;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, true);
	width = 0;
	line = get_next_line(fd);
	if (!line)
		exit_error("Failed to read the map", false);
	width = count_width(line);
	while (line)
	{
		if (width != count_width(line))
			exit_error("Failed to read the map", false);
		free(line);
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_error(NULL, true);
	return (width);
}

int	*get_altitude(const char *filename, t_map *map)
{
	int		fd;
	int		*alt;
	int		*array;
	char	*line;
	size_t	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, true);
	alt = (int *)malloc(sizeof(int) * (map->width * map->height));
	if (!alt)
		exit_error("Failed to read the map", false);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		array = line_to_int_array(line, map->width);
		ft_memcpy(&alt[i], array, sizeof(int) * map->width);
		i += map->width;
		(free(array), free(line));
		line = get_next_line(fd);
	}
	if (close(fd) == -1)
		exit_error(NULL, true);
	return (alt);
}
