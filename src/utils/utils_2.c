/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:13:28 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:29 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	free_animation_frames(t_data *mlx_ptr, t_animation *animation)
{
	int	i;

	i = 0;
	while (i < animation->total_frames)
	{
		if (animation->frames[i].img)
		{
			mlx_destroy_image(mlx_ptr, animation->frames[i].img);
			animation->frames[i].img = NULL;
		}
		i++;
	}
}

int	put_img(t_data *data, t_image *img, int x, int y)
{
	if (!data || !img || !img->img)
		return (-1);
	mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, img->img, x * 32, y
		* 32);
	return (1);
}
