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
            /* if (data->map.map[y][x] == START_POS)
                mlx_put_image_to_window(data->mlx_ptr, data->window_ptr, data->sprites.player.img, x * 64, y * 64); */
            x++;
        }
        y++;
    }
}
static void load_sprites(t_data *data)
{
    if (!data)
        return ;
    data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/walls/walls.xpm", &data->sprites.wall.width, &data->sprites.wall.height);
    data->sprites.exit.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/exit/exit.xpm", &data->sprites.exit.width, &data->sprites.exit.height);  
    data->sprites.player.img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/player.xpm", &data->sprites.player.width, &data->sprites.player.height);
    if (!data->sprites.wall.img || !data->sprites.exit.img || !data->sprites.player.img)
        exit_error(data, "LOAD_SPRITES: ERROR LOADING WALL IMAGE\n");

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
    draw_elements(data);
}

