#include "../../../includes/so_long.h"

int	put_img(t_data *data, t_image *img, int x, int y)
{
	if (!data || !img || !img->img)
		return (-1);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, img->img, x * 64, y
		* 64);
	return (1);
}

int	draw_element(t_data *data, int y, int x)
{
	if (!data || y < 0 || x < 0)
		return (-1);
	if (data->map.map[y][x] == WALLS)
		put_img(data, &data->sprites.wall, x, y);
	if (data->map.map[y][x] == ENEMY)
		put_img(data, &data->enemy.idle, x, y);
	if (data->map.map[y][x] == EXIT)
	{
		if (data->map.collectibles == 0 && data->sprites.exit_2.img)
			put_img(data, &data->sprites.exit_2, x, y);
		else if (data->sprites.exit.img)
			put_img(data, &data->sprites.exit, x, y);
	}
	if (data->map.map[y][x] == SPACE || data->map.map[y][x] == START_POS)
		put_img(data, &data->sprites.floor, x, y);
	if (data->map.map[y][x] == COLLECTIBLE)
	{
		if (data->toggle_collectible == 0)
			put_img(data, &data->sprites.collectibles, x, y);
		else
			put_img(data, &data->sprites.floor, x, y);
	}
	return (1);
}

void	draw_elements(t_data *data)
{
	int	y;
	int	x;

	if (!data)
		return ;
	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (draw_element(data, y, x) != 1)
				exit_error(data, "ERROR:\n DRAW_ELEMENTS ERROR\n");
			x++;
		}
		y++;
	}
}

void	draw_player(int key, t_data *data)
{
	t_animation	*current_animation;

	current_animation = NULL;
	if (key == XK_d || key == XK_Right)
	{
		current_animation = &data->player.walk_right;
		if (data->player.prev_x != data->player.x
			|| data->player.prev_y != data->player.y)
			current_animation->current_frame = 0;
	}
	else if (key == XK_a || key == XK_Left)
	{
		current_animation = &data->player.walk_left;
		if (data->player.prev_x != data->player.x
			|| data->player.prev_y != data->player.y)
			current_animation->current_frame = 0;
	}
	else if (key == XK_w || key == XK_Up)
		put_img(data, &data->player.front, data->player.x, data->player.y);
	else if (key == XK_s || key == XK_Down)
		put_img(data, &data->player.back, data->player.x, data->player.y);
	if (current_animation)
	{
		if (current_animation->current_frame < current_animation->total_frames
			- 1)
		{
			current_animation->counter++;
			if (current_animation->counter >= current_animation->speed)
			{
				current_animation->current_frame++;
				current_animation->counter = 0;
			}
		}
		put_img(data, &current_animation->frames[current_animation->current_frame], data->player.x, data->player.y);
	}
	else
		put_img(data, &data->player.idle, data->player.x, data->player.y);
	data->player.prev_x = data->player.x;
	data->player.prev_y = data->player.y;
}

void	draw_hud(t_data *data)
{
	char	*collectibles;
	char	*moves;

	if (!data)
		return ;
	moves = ft_itoa(data->moves);
	collectibles = ft_itoa(data->map.collectibles);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 10, 10, 0xFFFFFF,
		"Moves: ");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 120, 10, 0xFFFFFF, moves);
	mlx_string_put(data->mlx_ptr, data->window_ptr, 10, 30, 0xFFFFFF, "Docs: ");
	mlx_string_put(data->mlx_ptr, data->window_ptr, 120, 30, 0xFFFFFF,
		collectibles);
	free(moves);
	free(collectibles);
}
