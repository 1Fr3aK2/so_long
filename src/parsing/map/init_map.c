/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:13:24 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:25 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

int	init_map(char *file, t_data *data)
{
	if (!file || !data)
		return (-1);
	check_map_name(file);
	get_lines(data, file);
	get_map(file, data);
	if (check_valid_map(&data->map, data) != 1)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR CHECKING THE MAP\n");
	if (get_positions(&data->map, data) != 1)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR GETTING POSITIONS\n");
	if (get_enemy_pos(&data->map, data) != 1)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR GETTING ENEMY POS\n");
	if (check_valid_path(&data->map, data) != 1)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR CHECKING VALID PATH\n");
	close_fds(0);
	return (1);
}
