#include "../../includes/so_long.h"

void	close_fds(int i)
{
	i = 3;
	while (i < FOPEN_MAX)
	{
		close(i);
		i++;
	}
}

void	free_arr(char **arr, int height)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < height && arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
	arr = NULL;
}

void	free_temp_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	free_animations(t_data *data)
{
	if (!data)
		return ;
	free_animation_frames(data->mlx_ptr, &data->player.walk_right);
	free_animation_frames(data->mlx_ptr, &data->player.walk_left);
}

/* void	*my_malloc(size_t size)
{
	int malloc_fail_counter = 0; // Número de chamadas antes de falhar
	if (--malloc_fail_counter <= 0)
	{
		return (NULL); // Força falha de alocação
	}
	return (malloc(size));
}*/
