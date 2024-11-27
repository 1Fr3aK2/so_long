#include "../../../includes/so_long.h"

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
			if (data->map.map[y][x] == WALLS)
				mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
					data->sprites.wall.img, x * 64, y * 64);
			if (data->map.map[y][x] == EXIT)
			{
				if (data->map.collectibles == 0 && data->sprites.exit_2.img)
					mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
						data->sprites.exit_2.img, x * 64, y * 64);
				else if (data->sprites.exit.img)
					mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
						data->sprites.exit.img, x * 64, y * 64);
			}
			if (data->map.map[y][x] == SPACE
				|| data->map.map[y][x] == START_POS)
				mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
					data->sprites.floor.img, x * 64, y * 64);
			if (data->map.map[y][x] == COLLECTIBLE)
			{
				if (data->toggle_collectible == 0)
					mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
						data->sprites.collectibles.img, x * 64, y * 64);
				else
					mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
						data->sprites.floor.img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}

void	draw_player(int key, t_data *data)
{
	t_animation	*current_animation;

	current_animation = NULL;
	// Determinar qual animação usar
	if (key == XK_d || key == XK_Right)
	{
		current_animation = &data->player.walk_right;
		// Reiniciar a animação se a posição mudou
		if (data->player.prev_x != data->player.x
			|| data->player.prev_y != data->player.y)
		{
			current_animation->current_frame = 0;
		}
	}
	else if (key == XK_a || key == XK_Left)
	{
		current_animation = &data->player.walk_left;
		// Reiniciar a animação se a posição mudou
		if (data->player.prev_x != data->player.x
			|| data->player.prev_y != data->player.y)
		{
			current_animation->current_frame = 0;
		}
	}
	else if (key == XK_w || key == XK_Up)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->player.front.img, data->player.x * 64, data->player.y * 64);
	}
	else if (key == XK_s || key == XK_Down)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->player.back.img, data->player.x * 64, data->player.y * 64);
	}
	// Desenhar a animação atual
	if (current_animation)
	{
		// Verificar se a animação já foi completada
		if (current_animation->current_frame < current_animation->total_frames
			- 1)
		{
			// Controla o avanço da animação até o último quadro
			current_animation->counter++;
			if (current_animation->counter >= current_animation->speed)
			{
				current_animation->current_frame++;
				current_animation->counter = 0;
			}
		}
		// Desenhar o quadro atual da animação
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			current_animation->frames[current_animation->current_frame].img,
			data->player.x * 64, data->player.y * 64);
	}
	else
	{
		// Se não houver movimento, desenhar sprite parado
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->player.idle.img, data->player.x * 64, data->player.y * 64);
	}
	// Atualizar a posição anterior do jogador
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
