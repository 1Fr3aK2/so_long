#include "../../../includes/so_long.h"

int	load_player_animations_right(t_data *data)
{
	if (!data)
		return (-1);
	data->player.walk_right.frames[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/right/right_0.xpm",
			&data->player.walk_right.frames[0].width,
			&data->player.walk_right.frames[0].height);
	data->player.walk_right.frames[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/right/right_1.xpm",
			&data->player.walk_right.frames[1].width,
			&data->player.walk_right.frames[1].height);
	data->player.walk_right.frames[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/right/right_2.xpm",
			&data->player.walk_right.frames[2].width,
			&data->player.walk_right.frames[2].height);
	data->player.walk_right.frames[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/right/right_3.xpm",
			&data->player.walk_right.frames[3].width,
			&data->player.walk_right.frames[3].height);
	data->player.walk_right.frames[4].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/right/right_4.xpm",
			&data->player.walk_right.frames[4].width,
			&data->player.walk_right.frames[4].height);
	data->player.walk_right.frames[5].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/right/right_5.xpm",
			&data->player.walk_right.frames[5].width,
			&data->player.walk_right.frames[5].height);
	data->player.walk_right.frames[6].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/right/right_6.xpm",
			&data->player.walk_right.frames[6].width,
			&data->player.walk_right.frames[6].height);
	data->player.walk_right.total_frames = 7;
	data->player.walk_right.speed = 75;
	if (!data->player.walk_right.frames[0].img
		|| !data->player.walk_right.frames[1].img
		|| !data->player.walk_right.frames[2].img
		|| !data->player.walk_right.frames[3].img
		|| !data->player.walk_right.frames[4].img
		|| !data->player.walk_right.frames[5].img
		|| !data->player.walk_right.frames[6].img)
		return (-1);
	return (1);
}

int	load_player_animations_left(t_data *data)
{
	if (!data)
		return (-1);
	data->player.walk_left.frames[0].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/left/left_0.xpm",
			&data->player.walk_left.frames[0].width,
			&data->player.walk_left.frames[0].height);
	data->player.walk_left.frames[1].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/left/left_1.xpm",
			&data->player.walk_left.frames[1].width,
			&data->player.walk_left.frames[1].height);
	data->player.walk_left.frames[2].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/left/left_2.xpm",
			&data->player.walk_left.frames[2].width,
			&data->player.walk_left.frames[2].height);
	data->player.walk_left.frames[3].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/left/left_3.xpm",
			&data->player.walk_left.frames[3].width,
			&data->player.walk_left.frames[3].height);
	data->player.walk_left.frames[4].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/left/left_4.xpm",
			&data->player.walk_left.frames[4].width,
			&data->player.walk_left.frames[4].height);
	data->player.walk_left.frames[5].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/left/left_5.xpm",
			&data->player.walk_left.frames[5].width,
			&data->player.walk_left.frames[5].height);
	data->player.walk_left.frames[6].img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/animations/left/left_6.xpm",
			&data->player.walk_left.frames[6].width,
			&data->player.walk_left.frames[6].height);
	data->player.walk_left.total_frames = 7;
	data->player.walk_left.speed = 75;
	if (!data->player.walk_left.frames[0].img
		|| !data->player.walk_left.frames[1].img
		|| !data->player.walk_left.frames[2].img
		|| !data->player.walk_left.frames[3].img
		|| !data->player.walk_left.frames[4].img
		|| !data->player.walk_left.frames[5].img
		|| !data->player.walk_left.frames[6].img)
		return (-1);
	return (1);
}
