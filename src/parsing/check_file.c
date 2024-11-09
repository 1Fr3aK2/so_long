/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 23:46:24 by rafael            #+#    #+#             */
/*   Updated: 2024/11/08 23:46:53 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int check_name(char *name)
{
    int len;
    
    if (!name)
        return (-1);
    len = ft_strlen(name);
    if(len < 4 || ft_strncmp(&name[len-4], ".ber", 4))
        ft_putstr_fd("Invalid map name", 2);
    return (0);
}