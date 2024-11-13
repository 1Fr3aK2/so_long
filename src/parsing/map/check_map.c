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
			while (VALID_CHARS[k])
			{
				if (map->map[i][j] != VALID_CHARS[k])
					k++;
				else
					break ;
				if (!VALID_CHARS[k])
					return (0);
			}
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

void	check_format(t_map *map, t_data *data)
{
	if (!map || !data)
		return ;
	if (valid_chars(map) != 1)
	{
		ft_putstr_fd("CHECK_FORMAT/CHARS : CHARS ERROR\n", 2);
		exit_error(data);
	}
	else
		ft_putstr_fd("CHECK_FORMAT/CHARS : PASSED\n", 2);
	if (check_walls(map) != 1)
	{
		ft_putstr_fd("CHECK_FORMAT/WALLS : WALL ERROR\n", 2);
		exit_error(data);
	}
	else
		ft_putstr_fd("CHECK_FORMAT/WALLS : PASSED\n", 2);
	if (check_exit(map) != 1)
	{
		ft_putstr_fd("CHECK_FORMAT/EXIT : EXIT ERROR (less/more than 1 EXIT)\n",
			2);
		exit_error(data);
	}
	else
		ft_putstr_fd("CHECK_FORMAT/EXIT : PASSED\n", 2);
	if (check_collectibles(map) != 1)
	{
		ft_putstr_fd("CHECK_FORMAT/COLLECTIBLES : COLLECTIBLES ERROR (less than 1)\n",
			2);
		exit_error(data);
	}
	else
		ft_putstr_fd("CHECK_FORMAT/COLLECTIBLES : PASSED\n", 2);
	if (check_start_pos(map) != 1)
	{
		ft_putstr_fd("CHECK_FORMAT/START_POS : START_POS ERROR (less/more than 1 start_pos)\n",
			2);
		exit_error(data);
	}
	else
		ft_putstr_fd("CHECK_FORMAT/START_POS : PASSED\n", 2);
}

