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

void check_map(char *file_name)
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

    data->file.lines = 0;
    data->file.fd = open(file_name, O_RDONLY);
    if (data->file.fd < 0)
    {
        ft_putstr_fd("GET_LINES : Error opening the file\n", 2);
        exit(1);
    }
    while ((line = get_next_line(data->file.fd)))
    {
        ++(data->file.lines);
        free(line);
    }
    printf("lines : %d\n", data->file.lines);
    close (data->file.fd);
}

void get_map(char *file_name, t_data *data)
{
    static char *file;
    int i = 0;

    if (data->file.lines <= 0)
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
    data->map.map = malloc(sizeof(char *) * (data->file.lines + 1));
    if (!data->map.map)
    {
        ft_putstr_fd("GET_MAP : Memory allocation error\n", 2);
        close(data->file.fd);
        exit(1);
    }

    while ((file = get_next_line(data->file.fd)))
    {
        if (i < data->file.lines)
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

    // Verificar se todas as linhas foram lidas corretamente
    if (i != data->file.lines)
    {
        ft_putstr_fd("GET_MAP : Mismatch in expected and actual lines\n", 2);
        close(data->file.fd);
        exit(1);
    }

    data->map.map[i] = NULL;  // Finalize the map array with a NULL pointer

    // Print map contents and free memory
    for (int j = 0; j < i; j++)
    {
        write(1, data->map.map[j], ft_strlen(data->map.map[j]));
        free(data->map.map[j]);
    }
    free(data->map.map);
    close(data->file.fd);
}


static void check_open_fds()
{
    int fd;
    for (fd = 3; fd < 1024; ++fd) // Começa no 3 porque 0, 1, e 2 são stdin, stdout, stderr
    {
        if (fcntl(fd, F_GETFD) != -1) // F_GETFD retorna -1 se o FD não está em uso
        {
            printf("\nFD %d is still open\n", fd);
        }
    }
}

static void	close_fds(int i)
{
	i = 3;
	while (i < FOPEN_MAX)
	{
		close(i);
		i++;
	}
}
void	ft_free(char **cmd)
{
	size_t	i;

	if (!(*cmd) || !cmd)
		return ;
	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void init_map(char *file, t_data *data)
{
    check_map(file);
    get_lines(data, file);
    get_map(file, data);
    check_open_fds();
    close_fds(0);
}