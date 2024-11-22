#include "../../includes/so_long.h"

static void draw_elements(t_data *data)
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
            if (data->map.map[y][x] == SPACE)
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->sprites.floor.img, x * 64, y * 64);
            if (data->map.map[y][x] == COLLECTIBLE)
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->sprites.collectibles.img, x * 64, y * 64);
            x++;
        }
        y++;
    }
}


static void draw_player(int key, t_data *data)
{
    (void)key;
    if (!data)
        return ;
    /* if (key == XK_w || key == XK_Up)
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, , data->player.x * 64, data->player.y * 64);
    else if (key == XK_s || key == XK_Down)
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, , data->player.x * 64, data->player.y * 64);
    else if (key == XK_a || key == XK_Left)
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, , data->player.x * 64, data->player.y * 64); */
    /* else if (key == XK_d || key == XK_Right)
    {
        animate_player(&data->player.walk_right, data);
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->player.walk_right.frames.images[data->player.walk_right.current_frame], data->player.x * 64, data->player.y * 64);
    } */
    else
        mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->player.idle.img, data->player.x * 64, data->player.y * 64);
}




void    init_game(t_data *data)
{
    if (!data)
        exit_error(data, "INIT_GAME : INVALID POINTER\n");
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        exit_error(data, "INIT_GAME : ERROR WITH MLX_INIT\n");
    printf("screen_width: %d screen_size: %d\n", data->screen_width, data->screen_size);
    mlx_get_screen_size(data->mlx_ptr, &data->screen_width, &data->screen_size);
    if (((data->map.width * 64) + 32 > data->screen_width) || ((data->map.height * 64) + 32 > data->screen_size))
        exit_error(data, "INIT_GAME: SCRENN BIGGER THAN EXPECTED\n");
    data->window_ptr = mlx_new_window(data->mlx_ptr, data->map.width * 64, data->map.height * 64, "so_long");
    if (!data->window_ptr)
        exit_error(data, "INIT_MAP: ERROR CREATING WINDOW\n");  
    load_sprites(data);
    load_player(data);
    draw_elements(data);
    draw_player(-1 ,data);
}

