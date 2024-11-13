/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:46:24 by rafael            #+#    #+#             */
/*   Updated: 2024/11/13 18:11:44 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/so_long.h"

void	check_map_name(char *file_name)
{
	t_file	file;
	int		len;

	if (!file_name)
		return ;
	file.fd = open(file_name, O_RDONLY);
	if (file.fd < 0)
	{
		ft_putstr_fd("CHECK_MAP : Error opening the file\n", 2);
		exit(1);
	}
	len = ft_strlen(file_name);
	if (len < 4 || ft_strncmp(&file_name[len - 4], ".ber", 4))
	{
		ft_putstr_fd("CHECK_MAP :Invalid map name\n", 2);
		close(file.fd);
		exit(1);
	}
	else
		ft_putstr_fd("check name passed\n", 1);
	close(file.fd);
}

