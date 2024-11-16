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

void	flood_fill_map(char **map, int y, int x, t_data *data)
{

	if (!map || x < 1 || y < 1 || !data)
		return ;
	if (map[y][x] == WALLS || map[y][x] == '2')
		return ;
	if (map[y][x] == COLLECTIBLE)
		data->map.check_coll--;
	if (map[y][x] == EXIT)
	{
		data->map.check_exit = 1;
		return ;
	}
	map[y][x] = '2';
	flood_fill_map(map, y - 1, x, data);
	flood_fill_map(map, y + 1, x, data);
	flood_fill_map(map, y, x + 1, data);
	flood_fill_map(map, y, x - 1, data);
}

void	check_flood_fill(char **map, t_data *data)
{
	if (!map || data->map.check_coll != 0 || data->map.check_exit != 1)
	{
		free_temp_map(map);
		exit_error(data, "CHECK_FLOOD_FILL : elements inacessible 2 the player\n");
	}
	/* free_temp_map(map); */ //DESCOMENTAR !!!!
	printf("check_flood_fill passed\n");
}

int	check_valid_path(t_map *map, t_data *data)
{
	char	**temp;

	if (!map || !data)
		return (-1);
	temp = copy_map(map->map, map->height);
	if (!temp)
		return (-1);
	printf("MAPA: \n\n");
	map->check_coll = map->collectibles;
	flood_fill_map(temp, data->player.y, data->player.x, data);
	check_flood_fill(temp, data); //MELHORAR
	int j = 0;
	while (j < map->height)
	{
		if (temp[j])
			write(1, temp[j], ft_strlen(temp[j]));
		j++;
	}
	temp[j] = NULL;
	printf("\n\nFIM!\n");
	free_arr(temp, map->height); //COMENTAR !!!! ->comentar porque liberta-se em check_flood_fill
	return (1);
}
