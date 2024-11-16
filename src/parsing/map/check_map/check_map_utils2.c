#include "../../../../includes/so_long.h"

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

void	get_positions(t_map *map, t_data *data)
{
	int				i;
	int				j;

	if (!map || !data)
		return ;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (map->map[i][j] && j < map->width)
		{
			if (map->map[i][j] == START_POS)
			{
				data->player.x = j;
				data->player.y = i;
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
}
