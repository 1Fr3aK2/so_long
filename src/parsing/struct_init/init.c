#include "../../../includes/so_long.h"

void    init_struct(t_data *data)
{
    if (!data)
        return ;
    data = ft_calloc(1, sizeof(t_data));
    if (!data)
        return ;
}
