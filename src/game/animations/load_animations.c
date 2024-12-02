#include "../../../includes/so_long.h"

int	load_player_animations_right(t_data *data)
{
	char	*paths[7];

	paths[0] = "assets/player/animations/right/right_0.xpm";
	paths[1] = "assets/player/animations/right/right_1.xpm";
	paths[2] = "assets/player/animations/right/right_2.xpm";
	paths[3] = "assets/player/animations/right/right_3.xpm";
	paths[4] = "assets/player/animations/right/right_4.xpm";
	paths[5] = "assets/player/animations/right/right_5.xpm";
	paths[6] = "assets/player/animations/right/right_6.xpm";
	if (!data)
		return (-1);
	while (data->player.walk_right.total_frames < 7)
	{
		if (load_img(data,
				&data->player.walk_right.frames
				[data->player.walk_right.total_frames],
				paths[data->player.walk_right.total_frames]) != 1)
			return (-1);
		data->player.walk_right.total_frames++;
	}
	data->player.walk_right.speed = 300;
	return (1);
}

int	load_player_animations_left(t_data *data)
{
	char	*paths[7];

	paths[0] = "assets/player/animations/left/left_0.xpm";
	paths[1] = "assets/player/animations/left/left_1.xpm";
	paths[2] = "assets/player/animations/left/left_2.xpm";
	paths[3] = "assets/player/animations/left/left_3.xpm";
	paths[4] = "assets/player/animations/left/left_4.xpm";
	paths[5] = "assets/player/animations/left/left_5.xpm";
	paths[6] = "assets/player/animations/left/left_6.xpm";
	if (!data)
		return (-1);
	while (data->player.walk_left.total_frames < 7)
	{
		if (load_img(data,
				&data->player.walk_left.frames
				[data->player.walk_left.total_frames],
				paths[data->player.walk_left.total_frames]) != 1)
			return (-1);
		data->player.walk_left.total_frames++;
	}
	data->player.walk_left.speed = 300;
	return (1);
}

int	load_enemy_animations_left(t_data *data)
{
	char	*paths[7];

	paths[0] = "assets/enemy/animations/left/left_0.xpm";
	paths[1] = "assets/enemy/animations/left/left_1.xpm";
	paths[2] = "assets/enemy/animations/left/left_2.xpm";
	paths[3] = "assets/enemy/animations/left/left_3.xpm";
	paths[4] = "assets/enemy/animations/left/left_4.xpm";
	paths[5] = "assets/enemy/animations/left/left_5.xpm";
	paths[6] = "assets/enemy/animations/left/left_6.xpm";
	if (!data)
		return (-1);
	while (data->enemy.walk_left.total_frames < 7)
	{
		if (load_img(data,
				&data->enemy.walk_left.frames
				[data->enemy.walk_left.total_frames],
				paths[data->enemy.walk_left.total_frames]) != 1)
			return (-1);
		data->enemy.walk_left.total_frames++;
	}
	data->enemy.walk_left.speed = 300;
	return (1);
}
/* static int	load_enemy_animations_right(t_data *data)
{
	char	*paths[7];

	paths[0] = "assets/enemy/animations/right/right_0.xpm";
	paths[1] = "assets/enemy/animations/right/right_1.xpm";
	paths[2] = "assets/enemy/animations/right/right_2.xpm";
	paths[3] = "assets/enemy/animations/right/right_3.xpm";
	paths[4] = "assets/enemy/animations/right/right_4.xpm";
	paths[5] = "assets/enemy/animations/right/right_5.xpm";
	paths[6] = "assets/enemy/animations/right/right_6.xpm";
	if (!data)
		return (-1);
	while (data->enemy.walk_right.total_frames < 7)
	{
		if (load_img(data,
				&data->enemy.walk_right.frames
				[data->enemy.walk_right.total_frames],
				paths[data->enemy.walk_right.total_frames]) != 1)
			return (-1);
		data->enemy.walk_right.total_frames++;
	}
	data->enemy.walk_right.speed = 75;
	return (1);
}
 */