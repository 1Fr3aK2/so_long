#include "../../includes/so_long.h"

void	exit_error(t_data *data)
{
	int	freed;

	close_fds(0);
	check_open_fds();
	freed = 0;
	if (data->map.map)
	{
		free_arr(data->map.map);
		freed = 1;
	}
	if (data && freed == 0)
		free(data);
	exit(1);
}
