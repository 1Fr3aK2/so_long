#include "../../../includes/so_long.h"

void	init_map(char *file, t_data *data)
{
	check_map_name(file);
	get_lines(data, file);
	get_map(file, data);
	check_format(&data->map, data);
	close_fds(0);
	check_open_fds();
	free_arr(data->map.map);
}
