#include "../../../includes/so_long.h"

void	get_lines(t_data *data, char *file_name)
{
	static char	*line;

	if (!data || !file_name)
		return ;
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		exit_error(NULL, "GET_LINES : Error opening the file\n");
	while ((line = get_next_line(data->file.fd)))
	{
		++(data->map.height);
		if (data->map.height == 1)
			data->map.width = (ft_strlen(line) - 1);
		free(line);
	}
	printf("height : %d\n", data->map.height);
	printf("width : %d\n", data->map.width);
	close(data->file.fd);
}

void	get_map(char *file_name, t_data *data)
{
	char	*file;
	int		i;

	i = 0;
	if (data->map.height <= 0)
		exit_error(NULL, "GET_MAP : Invalid number of lines\n");
	data->file.fd = open(file_name, O_RDONLY);
	if (data->file.fd < 0)
		exit_error(NULL, "GET_MAP : Error opening the file\n");
	data->map.map = malloc(sizeof(char *) * (data->map.height + 1));
	/* data->map.map = my_malloc(sizeof(char *) * (data->map.height + 1)); */
	if (!data->map.map)
		exit_error(NULL, "GET_MAP : Memory allocation error\n");
/* 	file = get_next_line(data->file.fd); */
	while ((file = get_next_line(data->file.fd)))
	{
		if (i < data->map.height)
		{
			data->map.map[i] = ft_strdup(file);
			if (!data->map.map[i])
			{
				free(file);
				exit_error(data, "GET_MAP : Memory allocation error during ft_strdup\n");
			}
			free(file);
		}
		i++;
	}
	close(data->file.fd);
	/* data->map.height = 1999; */
	if (i != data->map.height)
	{
		if (data->map.height > i)
			data->map.height = i;
		exit_error(data, "GET_MAP : Mismatch in expected and actual lines\n");
	}
	for (int j = 0; j < i; j++)
	{
		write(1, data->map.map[j], ft_strlen(data->map.map[j]));
	}
	data->map.map[i] = NULL;
}
