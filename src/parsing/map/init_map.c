#include "../../../includes/so_long.h"

int	init_map(char *file, t_data *data)
{
	if (!file || !data)
		return (-1);
	check_map_name(file);
	get_lines(data, file);
	get_map(file, data);
	if (check_valid_map(&data->map, data) != 1)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR CHECKING THE MAP\n");
	if (get_positions(&data->map, data) != 1)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR GETTING POSITIONS\n");
	if (check_valid_path(&data->map, data) != 1)
		exit_error(data, "ERROR:\nINIT_MAP: ERROR CHECKING VALID PATH\n");
	close_fds(0);
	return (1);
}
