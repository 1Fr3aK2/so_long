#include "../../../../includes/so_long.h"

void	get_lines(t_data *data, char *file_name)
{
	static char	*line;

	if (!data || !file_name)
		exit_error(NULL, "ERROR:\nGET_LINES: Invalid pointer to file/struct\n");
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		exit_error(NULL, "ERROR:\nGET_LINES : Error opening the file\n");
	line = get_next_line(data->file.fd);
	if (!line)
		exit_error(data, "ERROR:\nGET_LINES: READING 1st LINE OF MAP\n");
	while (line)
	{
		++(data->map.height);
		if (data->map.height == 1)
			data->map.width = (ft_strlen(line) - 1);
		free(line);
		line = get_next_line(data->file.fd);
	}
	printf("height : %d\n", data->map.height);
	printf("width : %d\n", data->map.width);
	close(data->file.fd);
	ft_putstr_fd("get_lines passed\n", 2);
}

void	get_map(char *file_name, t_data *data)
{
	char	*file;
	int		i;

	i = 0;
	if (!file_name || !data)
		exit_error(NULL, "ERROR:\nGET_MAP: Invalid pointer to file/struct\n");
	if (data->map.height <= 0)
		exit_error(NULL, "ERROR:\nGET_MAP : Invalid number of lines\n");
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		exit_error(NULL, "ERROR:\nGET_MAP : Error opening the file\n");
	data->map.map = malloc(sizeof(char *) * (data->map.height + 1));
	if (!data->map.map)
		exit_error(NULL, "ERROR:\nGET_MAP : Memory allocation error\n");
	while (i < data->map.height + 1)
	{
		data->map.map[i] = NULL;
		i++;
	} //optimizar 
	i = 0;
	file = get_next_line(data->file.fd);
	if (!file)
		exit_error(data, "ERROR:\nGET_MAP : READING 1st LINE OF MAP\n");
	while (file)
	{
		if (i < data->map.height)
		{
			data->map.map[i] = ft_strdup(file);
			if (!data->map.map[i])
			{
				free(file);
				exit_error(data, "ERROR:\nGET_MAP: Mem alloc error strdup\n");
			}
			free(file);
			file = get_next_line(data->file.fd);
		}
		i++;
	}
	close(data->file.fd);
	/* data->map.height = 1999; */
	if (i != data->map.height)
	{
		if (data->map.height > i)
			data->map.height = i;
		exit_error(data, "ERROR:\nGET_MAP : expected != real lines\n");
	}
	for (int j = 0; j < i; j++)
	{
		write(1, data->map.map[j], ft_strlen(data->map.map[j]));
	}
	data->map.map[i] = NULL;
	ft_putstr_fd("\nGET_MAP : passed\n", 2);
}
