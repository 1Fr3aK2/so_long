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
	free_animation_frames(data->mlx_ptr, &data->enemy.walk_left);
}

void	bomb_anim_exit(t_data *data)
{
	t_animation	*bomb_animation;
	int			delay;
	int			i;

	bomb_animation = &data->enemy.walk_left;
	while (bomb_animation->current_frame < bomb_animation->total_frames)
	{
		put_img(data, &bomb_animation->frames[bomb_animation->current_frame],
			data->enemy.x, data->enemy.y);
		bomb_animation->counter++;
		if (bomb_animation->counter >= bomb_animation->speed)
		{
			bomb_animation->current_frame++;
			bomb_animation->counter = 0;
		}
	}
	i = 0;
	delay = 500000000;
	while (i < delay)
	{
		i++;
	}
	exit_error(data, "GAME OVER: YOU GOT CAUGHT BY THE ENEMY!\n");
}
