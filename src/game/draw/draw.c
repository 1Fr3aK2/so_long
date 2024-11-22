#include "../../../includes/so_long.h"

void draw_elements(t_data *data)
{
    int y;
    int x;
    
    if (!data)
        return ;
    y = 0;
    while (data->map.map[y])
    {
        x = 0;
        while(data->map.map[y][x])
        {
            if (data->map.map[y][x] == WALLS)
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->sprites.wall.img, x * 64, y * 64);
            if (data->map.map[y][x] == EXIT)
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->sprites.exit.img, x * 64, y * 64);
            if (data->map.map[y][x] == SPACE  || data->map.map[y][x] == START_POS)
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->sprites.floor.img, x * 64, y * 64);
            if (data->map.map[y][x] == COLLECTIBLE)
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->sprites.collectibles.img, x * 64, y * 64);
            x++;
        }
        y++;
    }
}


void draw_player(int key, t_data *data)
{
    if (!data)
        return ;
    if (key == XK_w || key == XK_Up)
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->player.front.img , data->player.x * 64, data->player.y * 64);
    else if (key == XK_s || key == XK_Down)
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->player.back.img , data->player.x * 64, data->player.y * 64);
    else if (key == XK_a || key == XK_Left)
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,data->player.left.img, data->player.x * 64, data->player.y * 64);
    else if (key == XK_d || key == XK_Right)
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->player.right.img, data->player.x * 64, data->player.y * 64);

    else
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->player.idle.img, data->player.x * 64, data->player.y * 64);
}


void draw_hud(t_data *data)
{
    char    *collectibles;
    char    *moves;
    if (!data)
        return;
    moves = ft_itoa(data->moves);
    collectibles = ft_itoa(data->map.collectibles);
    mlx_string_put(data->mlx_ptr, data->window_ptr, 10, 10, 0xFFFFFF, "Moves: ");
    mlx_string_put(data->mlx_ptr, data->window_ptr, 120, 10, 0xFFFFFF, moves);
    mlx_string_put(data->mlx_ptr, data->window_ptr, 10, 30, 0xFFFFFF, "Docs: ");
    mlx_string_put(data->mlx_ptr, data->window_ptr, 120, 30, 0xFFFFFF, collectibles);
    free(moves);
    free(collectibles);
}
