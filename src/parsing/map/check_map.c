#include "../../../includes/so_long.h"

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

int	check_start_pos(t_map *map)
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
			if (map->map[i][j] && map->map[i][j] == START_POS)
				++(map->start_pos);
			j++;
		}
		i++;
	}
	if (map->start_pos != 1)
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

int	check_format(t_map *map)
{
	int	i;
	int	j;

	if (!map)
		return (-1);
	i = 0;
	j = 0;
	while (i < map->height)
	{
		while (map->map[i][j])
			j++;
		if ((j - 1) != map->width)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

static char **copy_map(char **map, int height)
{
	char **temp;
	int i;

	if (!map)
		return (NULL);
	temp = (char **)malloc(sizeof(char *) * (height + 1));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < height)
	{
		temp[i] = ft_strdup(map[i]);
		if (!temp)
		{
			free_arr(map);
		}
		i++;
	}
	return (temp);
}

int check_valid_path(t_map *map)
{
	char **temp;
	temp = copy_map(map->map, map->height);
	printf("MAPA: \n\n");
	for (int j = 0; j < map->height; j++)
	{
		write(1, temp[j], ft_strlen(temp[j]));
	}
	printf("\n\nFIM");
	free_arr(temp);
	return 1;
}
