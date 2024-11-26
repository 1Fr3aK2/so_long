#include "../../../includes/so_long.h"

void load_player_animations_right(t_data *data)
{
    if (!data)
        return;

    // Carregar as imagens para a animação de "walk_right"
    data->player.walk_right.frames[0].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_0.xpm", &data->player.walk_right.frames[0].width, &data->player.walk_right.frames[0].height);
    data->player.walk_right.frames[1].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_1.xpm", &data->player.walk_right.frames[1].width, &data->player.walk_right.frames[1].height);
    data->player.walk_right.frames[2].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_2.xpm", &data->player.walk_right.frames[2].width, &data->player.walk_right.frames[2].height);
    data->player.walk_right.frames[3].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_3.xpm", &data->player.walk_right.frames[3].width, &data->player.walk_right.frames[3].height);
    data->player.walk_right.frames[4].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_4.xpm", &data->player.walk_right.frames[4].width, &data->player.walk_right.frames[4].height);
    data->player.walk_right.frames[5].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_5.xpm", &data->player.walk_right.frames[5].width, &data->player.walk_right.frames[5].height);
    data->player.walk_right.frames[6].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/right/right_6.xpm", &data->player.walk_right.frames[6].width, &data->player.walk_right.frames[6].height);
    int i = 0;
    while (i < 7) 
    {
        if (!data->player.walk_right.frames[i].img)
        {
            printf("LOAD_SPRITES: ERROR LOADING FRAME IMAGE[%d]\n", i);
            exit_error(data, NULL);
        }
        i++;
    }
    // A quantidade total de frames deve ser 7, já que você carregou 7 imagens
    data->player.walk_right.total_frames = 7;
    data->player.walk_right.current_frame = 0;
    data->player.walk_right.speed = 250;
    data->player.walk_right.counter = 0;
}

void	load_player_animations_left(t_data *data)
{
    if (!data)
        return;

    // Carregar as imagens para a animação de "walk_right"
    data->player.walk_left.frames[0].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/left/left_0.xpm", &data->player.walk_left.frames[0].width, &data->player.walk_left.frames[0].height);
    data->player.walk_left.frames[1].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/left/left_1.xpm", &data->player.walk_left.frames[1].width, &data->player.walk_left.frames[1].height);
    data->player.walk_left.frames[2].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/left/left_2.xpm", &data->player.walk_left.frames[2].width, &data->player.walk_left.frames[2].height);
    data->player.walk_left.frames[3].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/left/left_3.xpm", &data->player.walk_left.frames[3].width, &data->player.walk_left.frames[3].height);
    data->player.walk_left.frames[4].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/left/left_4.xpm", &data->player.walk_left.frames[4].width, &data->player.walk_left.frames[4].height);
    data->player.walk_left.frames[5].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/left/left_5.xpm", &data->player.walk_left.frames[5].width, &data->player.walk_left.frames[5].height);
    data->player.walk_left.frames[6].img = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/animations/left/left_6.xpm", &data->player.walk_left.frames[6].width, &data->player.walk_left.frames[6].height);
    int i = 0;
    while (i < 7) 
    {
        if (!data->player.walk_left.frames[i].img)
        {
            printf("LOAD_SPRITES: ERROR LOADING FRAME IMAGE[%d]\n", i);
            exit_error(data, NULL);
        }
        i++;
    }
    // A quantidade total de frames deve ser 7, já que você carregou 7 imagens
    data->player.walk_left.total_frames = 7;
    data->player.walk_left.current_frame = 0;
    data->player.walk_left.speed = 250;
    data->player.walk_left.counter = 0;
}



/* void animate_player(t_animation *animation, t_data *data)
{
    animation->counter++;
    if (animation->counter >= animation->speed)
    {
        animation->counter = 0;
        animation->current_frame = (animation->current_frame + 1) % animation->total_frames; // Corrigido de "frame" para "current_frame"
    }
    mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
        animation->frames.images[animation->current_frame], data->player.x * 64, data->player.y * 64); // Corrigido de "frame" para "current_frame"
}*/