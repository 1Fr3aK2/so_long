
#include "../../includes/so_long.h"

static void my_pixel_put(t_data *data, int x, int y, int color) //funcao criada pelo user para colocar pixeis na janela
{
    char *dst;
    
    if (!data)
        return ;
    dst = data->image.addr + (y * data->image.line_length + x * (data->image.bits_per_pixel/8));
    *(unsigned int *)dst = color;
}

void init(t_data *data)
{
    ft_bzero(data, sizeof(t_data));
    data->image.img = 
}

