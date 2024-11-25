#include "../../../includes/so_long.h"

/* void load_player_animations(t_data *data)
{
    if (!data)
        return;

    // Carregar as imagens para a animação de "walk_right"
    data->player.walk_right.frames.images[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_0.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_1.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_2.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[3] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_3.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[4] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_4.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[5] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_5.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[6] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_6.xpm", &data->player.x, &data->player.y);
    int i = 0;
    while (i < 7) 
    {
        if (!data->player.walk_right.frames.images[i])
        {
            printf("LOAD_SPRITES: ERROR LOADING FRAME IMAGE[%d]\n", i);
            exit_error(data, NULL);
        }
        i++;
    }

    // A quantidade total de frames deve ser 7, já que você carregou 7 imagens
    data->player.walk_right.total_frames = 7;
    data->player.walk_right.current_frame = 0;
    data->player.walk_right.speed = 10;
    data->player.walk_right.counter = 0;
} */


/* void load_player_animations(t_data *data)
{
    if (!data)
        return ;
    
    // Certifique-se de que a memória para as imagens foi alocada
    data->player.walk_right.frames.images = malloc(sizeof(void*) * 7);
    if (!data->player.walk_right.frames.images)
    {
        exit_error(data, "LOAD_SPRITES: ERROR ALLOCATING MEMORY FOR IMAGES\n");
        return;
    }

    // Carregar as imagens
    data->player.walk_right.frames.images[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_0.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_1.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_2.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[3] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_3.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[4] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_4.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[5] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_5.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames.images[6] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_6.xpm", &data->player.x, &data->player.y);

    // Verificação de erros no carregamento das imagens
    for (int i = 0; i < 7; i++)
    {
        if (!data->player.walk_right.frames.images[i])
        {
            char error_message[100];
            snprintf(error_message, sizeof(error_message), "LOAD_SPRITES: ERROR LOADING FRAME[%d] IMAGE\n", i);
            exit_error(data, error_message);
        }
    }

    // Inicializar as propriedades da animação
    data->player.walk_right.total_frames = 7; // Agora temos 7 quadros
    data->player.walk_right.current_frame = 0;
    data->player.walk_right.speed = 10;
    data->player.walk_right.counter = 0;
} */

void animate_player(t_animation *animation, t_data *data)
{
    animation->counter++;
    if (animation->counter >= animation->speed)
    {
        animation->counter = 0;
        animation->current_frame = (animation->current_frame + 1) % animation->total_frames; // Corrigido de "frame" para "current_frame"
    }
    mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
        animation->frames.images[animation->current_frame], data->player.x * 64, data->player.y * 64); // Corrigido de "frame" para "current_frame"
}
