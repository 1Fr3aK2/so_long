#include "../../includes/so_long.h"

void	init_struct(t_data *data)
{
	/* ft_calloc(1, sizeof(t_data)); */
	ft_bzero(data, sizeof(t_data));
}
