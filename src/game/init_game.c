#include "../../includes/so_long.h"

void    init_game(t_data *data)
{
    if (!data)
        exit_error(data, "INIT_GAME : INVALID POINTER\n");
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        exit_error(data, "INIT_GAME : ERROR WITH MLX_INIT\n");
    printf("screen_width: %d screen_size: %d\n", data->screen_width, data->screen_size);
    mlx_get_screen_size(data->mlx_ptr, &data->screen_width, &data->screen_size);
    printf("screen_width: %d screen_size: %d\n", data->screen_width, data->screen_size);
    
}