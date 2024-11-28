#include "../../includes/so_long.h"

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

void	free_enemy(t_data *data)
{
	if (!data)
		return ;
	if (data->enemy.front.img)
		mlx_destroy_image(data->mlx_ptr, data->enemy.front.img);
	if (data->enemy.back.img)
		mlx_destroy_image(data->mlx_ptr, data->enemy.back.img);
	if (data->enemy.left.img)
		mlx_destroy_image(data->mlx_ptr, data->enemy.left.img);
	if (data->enemy.right.img)
		mlx_destroy_image(data->mlx_ptr, data->enemy.right.img);
	if (data->enemy.idle.img)
		mlx_destroy_image(data->mlx_ptr, data->enemy.idle.img);
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
		}
		i++;
	}
}
