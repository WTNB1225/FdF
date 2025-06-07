/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyuki <wyuki@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 01:49:25 by wyuki             #+#    #+#             */
/*   Updated: 2025/06/06 19:35:46 by wyuki            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

static unsigned int	hex_to_int(char *hex)
{
	char	*hex_table;
	int		sum;
	unsigned int		i;

	hex_table = "0123456789ABCDEF";
	sum = 0;
	while (ft_isspace(*hex))
		hex++;
	hex += 2;
	while (*hex)
	{
		i = 0;
		while (hex_table[i])
		{
			if (hex_table[i] == *hex)
				break ;
			i++;
		}
		sum = (sum * 16) + i;
		hex++;
	}
	return (sum);
}

static unsigned int	*read_color(char *line, unsigned int *color)
{
	size_t	i;
	char	**split;
	char	*ptr;

	split = ft_split(line, ' ');
	if (!split)
		exit_error("Failed to read the map", false);
	i = 0;
	while (split[i])
	{
		ptr = ft_strchr(split[i], ',');
		if (!ptr)
			color[i] = 0XFFFFFFFF;
		else
			color[i] = hex_to_int(ptr);
		i++;
	}
	free(split);
	return (color);
}

unsigned int	*get_color(const char *filename, t_map *map)
{
	int		fd;
	unsigned int	*color;
	unsigned int	*color_line;
	char	*line;
	size_t	i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error(NULL, true);
	color = (unsigned int *)malloc(sizeof(unsigned int) * (map->width * map->height));
	i = 0;
	if (!color)
		exit_error("Failed to read the map", false);
	line = get_next_line(fd);
	while (line)
	{
		color_line = read_color(line, color);
		ft_memcpy((color + (i * map->width)), color_line, sizeof(unsigned int) * map->width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	if (close(fd) == -1)
		exit_error(NULL, true);
	return (color);
}
