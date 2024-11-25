#include "../../includes/so_long.h"

int game_loop(t_data *data)
{
    static int frame;
      
    if (!data)
        return (0);

    // Incrementa o frame para animações
    frame++;
    if (frame >= 900) // Atualiza a cada 30 ciclos
    {
        data->toggle_collectible = !data->toggle_collectible;
        frame = 0;
    }


    // Redesenha os elementos do mapa e o jogador
    draw_elements(data);
    draw_player(-1, data);
    draw_hud(data);

    return (0);
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
    /* load_player_animations(data); */
}

