/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_temp_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:13:17 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:18 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/so_long.h"

char	**copy_map(char **map, int height)
{
	char		**temp;
	int			i;

	if (!map || height <= 0)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (height + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < height)
	{
		temp[i] = ft_strdup(map[i]);
		if (!temp[i])
		{
			free_arr(temp, i);
			return (NULL);
		}
		i++;
	}
	temp[i] = NULL;
	return (temp);
}

int	flood_fill_map(char **map, int y, int x, t_data *data)
{
	if (!map || x < 1 || y < 1 || !data)
		return (-1);
	if (map[y][x] == WALLS || map[y][x] == '2')
		return (1);
	if (map[y][x] == COLLECTIBLE)
		data->map.check_coll--;
	if (map[y][x] == EXIT)
	{
		data->map.check_exit = 1;
		return (1);
	}
	if (map[y][x] == ENEMY)
		return (1);
	map[y][x] = '2';
	flood_fill_map(map, y - 1, x, data);
	flood_fill_map(map, y + 1, x, data);
	flood_fill_map(map, y, x + 1, data);
	flood_fill_map(map, y, x - 1, data);
	return (1);
}

int	check_flood_fill(char **map, t_data *data)
{
	if (!map || !data || data->map.check_coll != 0 || data->map.check_exit != 1)
		return (-1);
	free_temp_map(map);
	return (1);
}

int	check_valid_path(t_map *map, t_data *data)
{
	char	**temp;

	if (!map || !data)
		return (-1);
	temp = copy_map(map->map, map->height);
	if (!temp)
		return (-1);
	map->check_coll = map->collectibles;
	if (flood_fill_map(temp, data->player.y, data->player.x, data) != 1)
	{
		free_temp_map(temp);
		exit_error(data, "ERROR:\nFLOOD_FILL ERROR\n");
	}
	if (check_flood_fill(temp, data) != 1)
	{
		free_temp_map(temp);
		exit_error(data, "ERROR:\nCHECK_FLOOD_FILL ERROR\n");
	}
	return (1);
}
