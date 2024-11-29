#include "../../../includes/so_long.h"

int	load_img(t_data *data, t_image *img, char *path)
{
	if (!data)
		return (-1);
	if (!img || !path)
		exit_error(data, "ERROR:\n LOAD_IMG INVALID POINTER\n");
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->width,
			&img->height);
	if (!img->img)
	{
		exit_error(data, "ERROR:\nLOAD_SPRITES: LOADING IMAGE\n");
	}
	return (1);
}

int	load_sprites(t_data *data)
{
	if (!data)
		return (-1);
	if (load_img(data, &data->sprites.wall, "assets/walls/walls.xpm") != 1)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING WALL IMAGE\n");
	if (load_img(data, &data->sprites.exit, "assets/exit/exit.xpm") != 1)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING EXIT IMAGE\n");
	if (load_img(data, &data->sprites.exit_2, "assets/exit/exit_2.xpm") != 1)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING EXIT_2 IMAGE\n");
	if (load_img(data, &data->sprites.floor, "assets/floor/floor.xpm") != 1)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING FLOOR IMAGE\n");
	if (load_img(data, &data->sprites.collectibles,
			"assets/collectibles/collectibles.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_SPRITES: ERROR LOADING COLLECTIBLES IMAGE\n");
	return (1);
}

int	load_player(t_data *data)
{
	if (!data)
		return (-1);
	if (load_img(data, &data->player.idle,
			"assets/player/static_img/player_right.xpm") != 1)
		exit_error(data, "ERROR:\nLOAD_PLAYER: ERROR LOADING PLAYER IMAGE\n");
	if (load_img(data, &data->player.front,
			"assets/player/static_img/player_right.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_PLAYER: ERROR LOADING PLAYER FRONT IMAGE\n");
	if (load_img(data, &data->player.back,
			"assets/player/static_img/player_right.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_PLAYER: ERROR LOADING PLAYER BACK IMAGE\n");
	if (load_img(data, &data->player.right,
			"assets/player/static_img/player_right.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_PLAYER: ERROR LOADING PLAYER RIGHT IMAGE\n");
	if (load_img(data, &data->player.left,
			"assets/player/static_img/player_left.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_PLAYER: ERROR LOADING PLAYER LEFT IMAGE\n");
	return (1);
}

int	load_enemy(t_data *data)
{
	if (!data)
		return (-1);
	if (!data)
		return (-1);
	if (load_img(data, &data->enemy.idle,
			"assets/enemy/static_img/enemy_right.xpm") != 1)
		exit_error(data, "ERROR:\nLOAD_ENEMY: ERROR LOADING ENEMY IMAGE\n");
	if (load_img(data, &data->enemy.front,
			"assets/enemy/static_img/enemy_right.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_ENEMY: ERROR LOADING ENEMY FRONT IMAGE\n");
	if (load_img(data, &data->enemy.back,
			"assets/enemy/static_img/enemy_right.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_ENEMY: ERROR LOADING ENEMY BACK IMAGE\n");
	if (load_img(data, &data->enemy.right,
			"assets/enemy/static_img/enemy_right.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_ENEMY: ERROR LOADING ENEMY RIGHT IMAGE\n");
	if (load_img(data, &data->enemy.left,
			"assets/enemy/static_img/enemy_left.xpm") != 1)
		exit_error(data,
			"ERROR:\nLOAD_ENEMY: ERROR LOADING ENEMY LEFT IMAGE\n");
	return (1);
}

int	load_all(t_data *data)
{
	if (!data)
		return (-1);
	if (load_sprites(data) != 1)
		return (-1);
	if (load_player(data) != 1)
		return (-1);
	if (load_enemy(data) != 1)
		return (-1);
	if (load_player_animations_left(data) != 1)
		return (-1);
	if (load_player_animations_right(data) != 1)
		return (-1);
	return (1);
}
