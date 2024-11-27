#include "../../includes/so_long.h"

void	exit_error(t_data *data, char *str)
{
	if (str)
		ft_putstr_fd(str, 2);
	else
		ft_putstr_fd("Error\n", 2);
	free_animations(data);
	free_images(data);
	free_player(data);
	if (data)
	{
		if (data->map.map)
		{
			free_arr(data->map.map, data->map.height);
			data->map.map = NULL;
		}
		if (data->window_ptr)
		{
			mlx_destroy_window(data->mlx_ptr, data->window_ptr);
			data->window_ptr = NULL;
		}
		if (data->mlx_ptr)
		{
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
			data->mlx_ptr = NULL;
		}
		data = NULL;
	}
	close_fds(0);
	check_open_fds();
	exit(1);
}

void	free_images(t_data *data)
{
	if (!data)
		return ;
	else
	{
		if (data->sprites.wall.img)
			mlx_destroy_image(data->mlx_ptr, data->sprites.wall.img);
		if (data->sprites.floor.img)
			mlx_destroy_image(data->mlx_ptr, data->sprites.floor.img);
		if (data->sprites.exit.img)
			mlx_destroy_image(data->mlx_ptr, data->sprites.exit.img);
		if (data->sprites.exit_2.img)
			mlx_destroy_image(data->mlx_ptr, data->sprites.exit_2.img);
		if (data->sprites.collectibles.img)
			mlx_destroy_image(data->mlx_ptr, data->sprites.collectibles.img);
	}
}

void	free_player(t_data *data)
{
	if (!data)
		return ;
	if (data->player.front.img)
		mlx_destroy_image(data->mlx_ptr, data->player.front.img);
	if (data->player.back.img)
		mlx_destroy_image(data->mlx_ptr, data->player.back.img);
	if (data->player.left.img)
		mlx_destroy_image(data->mlx_ptr, data->player.left.img);
	if (data->player.right.img)
		mlx_destroy_image(data->mlx_ptr, data->player.right.img);
	if (data->player.idle.img)
		mlx_destroy_image(data->mlx_ptr, data->player.idle.img);
}

void	free_animations(t_data *data)
{
	int	i;

	if (!data)
		return ;
	i = 0;
	while (i < data->player.walk_right.total_frames)
	{
		if (data->player.walk_right.frames[i].img)
		{
			mlx_destroy_image(data->mlx_ptr,
				data->player.walk_right.frames[i].img);
			data->player.walk_right.frames[i].img = NULL;
		}
		i++;
	}
	i = 0;
	while (i < data->player.walk_left.total_frames)
	{
		if (data->player.walk_left.frames[i].img)
		{
			mlx_destroy_image(data->mlx_ptr,
				data->player.walk_left.frames[i].img);
			data->player.walk_left.frames[i].img = NULL;
		}
		i++;
	}
}
