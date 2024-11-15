#include "../../../includes/so_long.h"
void get_positions(t_map *map)
{
	t_player player;

	if (!map)
		return ;
	int i = 0;
	while (i < map->height)
	{
		int j = 0;
		while(map->map[i][j] && j < map->width)
		{
			if (map->map[i][j] == START_POS)
			{
				player.x = j;
				player.y = i;
			}
			else if (map->map[i][j] == EXIT)
			{
				map->exit_x = j;
				map->exit_y = i;
			}
			j++;
		}
		i++;
	}
	printf("\nplayer.x(linha) : %d\nplayer.y(altura) : %d\n\n", player.x, player.y);
	printf("\nexit.x(linha) : %d\nexit.y(altura) : %d\n\n", map->exit_x, map->exit_y);
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

/* static void flood_fill_map(char **map, int y, int x, int check_coll)
{	
	if (!map || x < 1 || y < 1 || check_coll < 1)
		return ;
	if (map[y][x] == WALLS || map[y][x] == '2')
		return ;
	if (map[y][x] == COLLECTIBLE)
		check_coll--;
	if (map[y][x] == EXIT)
	{
		return ;
	} 
	map[y][x] = '2';
	flood_fill_map(map, y - 1, y, check_coll);
	flood_fill_map(map, y + 1, y, check_coll);
	flood_fill_map(map, y, x + 1, check_coll);
	flood_fill_map(map, y, x - 1, check_coll);
} */

int check_valid_path(t_map *map)
{
	if (!map)
		return -1;
	char **temp;
	temp = copy_map(map->map, map->height);
	if (!temp)
		return (-1);
	printf("MAPA: \n\n");
	for (int j = 0; j < map->height; j++)
	{
		if (temp[j]) 
			write(1, temp[j], ft_strlen(temp[j]));
	}
	map->check_coll = map->collectibles;
	/* flood_fill_map(temp, map->height, map->width, map->check_coll); */
	printf("\n\nFIM!\n");
	free_arr(temp, map->height);
	return 1;
}