/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:56:21 by rafael            #+#    #+#             */
/*   Updated: 2024/11/08 23:46:40 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
        ft_putstr_fd("Ivalide number of arguments\n ./so_long map.ber", 2);
    check_name(argv[1]);
}
