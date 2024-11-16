#include "../../includes/so_long.h"

void	init_struct(t_data *data)
{
	if (!data)
		exit_error(NULL, "INIT_STRUCT : ERROR\n");
	ft_bzero(data, sizeof(t_data));
}
