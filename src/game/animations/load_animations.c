#include "../../../includes/so_long.h"

void load_player_animations(t_data *data)
{
    if (!data)
        return ;
    data->player.walk_right.frames[0] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/right/right_0.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames[1] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/right/right_1.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames[2] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/right/right_2.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames[3] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/right/right_3.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames[4] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/right/right_4.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames[5] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/right/right_5.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.frames[5] = mlx_xpm_file_to_image(data->mlx_ptr, "assets/player/right/right_6.xpm", &data->player.x, &data->player.y);
    data->player.walk_right.total_frames = 6;
    data->player.walk_right.current_frame = 0;
    data->player.walk_right.speed = 10;
    data->player.walk_right.counter = 0;
}

void animate_player(t_animation *animation, t_data *data)
{
    animation->counter++;
    if (animation->counter >= animation->speed)
    {
        animation->counter = 0;
        animation->current_frame = (animation->current_frame + 1) % animation->total_frames; // Corrigido de "frame" para "current_frame"
    }
    mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
        animation->frames[animation->current_frame], data->player.x * 64, data->player.y * 64); // Corrigido de "frame" para "current_frame"
}

