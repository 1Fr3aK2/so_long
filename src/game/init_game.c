/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:12:52 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:12:53 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	game_loop(t_data *data)
{
	static int	frame;

	if (!data)
		return (-1);
	frame++;
	if (frame >= 2000)
	{
		data->toggle_collectible = !data->toggle_collectible;
		frame = 0;
	}
	draw_elements(data);
	draw_player(data->last_key, data);
	draw_hud(data);
	return (-1);
}

int	init_game(t_data *data)
{
	if (!data)
		return (-1);
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		exit_error(data, "ERROR:\nINIT_GAME : ERROR WITH MLX_INIT\n");
	mlx_get_screen_size(data->mlx_ptr, &data->screen_width, &data->screen_size);
	if (((data->map.width * 32) > data->screen_width) || ((data->map.height
				* 32) > data->screen_size))
		exit_error(data, "ERROR:\nINIT_GAME: SCRENN BIGGER THAN EXPECTED\n");
	data->window_ptr = mlx_new_window(data->mlx_ptr, data->map.width * 32,
			data->map.height * 32, "so_long");
	if (!data->window_ptr)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR CREATING WINDOW\n");
	if (load_all(data) != 1)
		exit_error(data,
			"ERROR:\nERROR INIT_GAME: something wrong loading images\n");
	mlx_hook(data->window_ptr, KeyPress, KeyPressMask, handle_key, data);
	mlx_hook(data->window_ptr, DestroyNotify, StructureNotifyMask, press_x,
		data);
	return (1);
}
