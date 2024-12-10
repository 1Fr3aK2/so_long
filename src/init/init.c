/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raamorim <raamorim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:12:56 by raamorim          #+#    #+#             */
/*   Updated: 2024/12/10 15:12:57 by raamorim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_struct(t_data *data)
{
	if (!data)
		exit_error(NULL, "INIT_STRUCT : ERROR\n");
	ft_bzero(data, sizeof(t_data));
}
