/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:12:44 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:12:45 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	move_player(int key, t_data *data)
{
	if (!data)
		return ;
	data->last_key = key;
	moves(data, key);
}

int	press_x(t_data *data)
{
	exit_error(data, "GAME OVER!\n");
	return (1);
}

int	handle_key(int key, t_data *data)
{
	if (!data)
		return (-1);
	if (key == XK_Escape)
		exit_error(data, "GAME OVER!\n");
	else
		move_player(key, data);
	return (1);
}
