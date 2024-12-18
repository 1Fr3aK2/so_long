/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:13:06 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:07 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long.h"

int	check_format(t_map *map)
{
	int	i;
	int	line_len;

	if (!map)
		return (-1);
	i = 0;
	while (i < map->height)
	{
		line_len = ft_strlen(map->map[i]);
		if (line_len > 0 && map->map[i][line_len - 1] == '\n')
			line_len--;
		if (line_len != map->width)
			return (0);
		i++;
	}
	return (1);
}

int	valid_chars(t_map *map)
{
	int	i;
	int	j;
	int	k;

	if (!map || !map->map)
		return (-1);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j] && j < map->width)
		{
			k = 0;
			while (VALID_CHARS[k] && map->map[i][j] != VALID_CHARS[k])
				k++;
			if (!VALID_CHARS[k])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	i;
	int	j;

	if (!map || !map->map)
		return (-1);
	j = 0;
	while (j < map->width)
	{
		if (map->map[0][j] != WALLS || map->map[map->height - 1][j] != WALLS)
			return (0);
		j++;
	}
	i = 1;
	while (i < map->height - 1)
	{
		if (map->map[i][0] != WALLS || map->map[i][map->width - 1] != WALLS)
			return (0);
		i++;
	}
	return (1);
}

int	check_collectibles(t_map *map)
{
	int	i;
	int	j;

	if (!map)
		return (-1);
	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] && map->map[i][j] == COLLECTIBLE)
				++map->collectibles;
			j++;
		}
		i++;
	}
	if (map->collectibles < 1)
		return (0);
	return (1);
}

int	check_exit(t_map *map)
{
	int	i;
	int	j;

	if (!map)
		return (-1);
	i = 1;
	while (i < map->height - 1)
	{
		j = 1;
		while (j < map->width - 1)
		{
			if (map->map[i][j] && map->map[i][j] == EXIT)
				++(map->exit);
			j++;
		}
		i++;
	}
	if (map->exit != 1)
		return (0);
	return (1);
}
