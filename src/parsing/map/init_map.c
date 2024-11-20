#include "../../../includes/so_long.h"

void	init_map(char *file, t_data *data)
{
	/* (void)data;
	(void)file; */
	if (!file || !data)
		return ;
	check_map_name(NULL);
	get_lines(data, file);
	get_map(file, data);
	check_valid_map(&data->map, data); //fix null data; -> QUANDO CHEGA ALI E IMPOSSIVEL SER NULL
	get_positions(&data->map, data);
	check_valid_path(&data->map, data);
	close_fds(0);
	check_open_fds();
	/* free_arr(data->map.map, data->map.height); */ //vai ser libertado em main;
}
 