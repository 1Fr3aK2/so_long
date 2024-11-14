#include "../../includes/so_long.h"

void	exit_error(t_data *data, char *str)
{
	int	freed;

	close_fds(0);
	check_open_fds();
	freed = 0;
	if (data && data->map.map)
	{
		free_arr(data->map.map, data->map.height);
		freed = 1;
	}
	if (data && freed == 0)
		free(data);
	if (!str)
		ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	exit(1);
}
