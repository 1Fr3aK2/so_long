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

#include "../../../includes/so_long.h"

void check_map_name(char *file_name)
{
    t_data data;
    int len;

    if (!file_name)
        return ;
    data.file.fd = open(file_name, O_RDONLY);
    if (data.file.fd < 0)
    {
        ft_putstr_fd("CHECK_MAP : Error opening the file\n", 2);
        exit(1);
    }

    len = ft_strlen(file_name);
    if(len < 4 || ft_strncmp(&file_name[len-4], ".ber", 4))
    {
        ft_putstr_fd("CHECK_MAP :Invalid map name\n", 2);
        close(data.file.fd);
        exit(1);
    }
    else
        ft_putstr_fd("check name passed\n", 1);
    close (data.file.fd);
}

void get_lines(t_data *data, char *file_name)
{
    static char *line;

    if (!data || !file_name)
        return ;
    data->map.height = 0;
    data->map.width = 0;
    data->file.fd = open(file_name, O_RDONLY);
    if (data->file.fd < 0)
    {
        ft_putstr_fd("GET_LINES : Error opening the file\n", 2);
        exit(1);
    }
    while ((line = get_next_line(data->file.fd)))
    {
        ++(data->map.height);
        if (data->map.height == 1)
            data->map.width = (ft_strlen(line) - 1);
        free(line);
    }
    printf("height : %d\n", data->map.height);
    printf("width : %d\n", data->map.width);
    close (data->file.fd);
}

void get_map(char *file_name, t_data *data)
{
    static char *file;
    int i;
    
    i = 0;
    if (data->map.height <= 0)
    {
        ft_putstr_fd("GET_MAP : Invalid number of lines\n", 2);
        exit(1);
    }
    data->file.fd = open(file_name, O_RDONLY);
    if (data->file.fd < 0)
    {
        ft_putstr_fd("GET_MAP : Error opening the file\n", 2);
        exit(1);
    }
    data->map.map = malloc(sizeof(char *) * (data->map.height + 1));
    if (!data->map.map)
    {
        ft_putstr_fd("GET_MAP : Memory allocation error\n", 2);
        close(data->file.fd);
        exit(1);
    }

    while ((file = get_next_line(data->file.fd)))
    {
        if (i < data->map.height)
        {
            data->map.map[i] = ft_strdup(file);
            if (!data->map.map[i])
            {
                ft_putstr_fd("GET_MAP : Memory allocation error during ft_strdup\n", 2);
                close(data->file.fd);
                exit(1);
            }
            free(file);
        }
        i++;
    }
    close(data->file.fd);
    // Verificar se todas as linhas foram lidas corretamente
    if (i != data->map.height)
    {
        ft_putstr_fd("GET_MAP : Mismatch in expected and actual lines\n", 2);
        close(data->file.fd);
        exit(1);
    }
    data->map.map[i] = NULL;
    /* for (int j = 0; j < i; j++)
    {
        write(1, data->map.map[j], ft_strlen(data->map.map[j]));
        free(data->map.map[j]);
    }
    free(data->map.map); */
}

