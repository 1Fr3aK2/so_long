/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:13:01 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:13:02 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	check_map_name(char *file_name)
{
	t_file	file;
	int		len;

	if (!file_name)
		exit_error(NULL, "ERROR:\nCHECK_MAP : Invalid pointer to file name\n");
	file.fd = open(file_name, O_RDONLY);
	if (file.fd < 0)
		exit_error(NULL, "ERROR:\nCHECK_MAP : Error opening the file\n");
	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(&file_name[len - 4], ".ber", 4) != 0)
		exit_error(NULL, "ERROR:\n: Invalid map name, should be .ber\n");
	close(file.fd);
}
