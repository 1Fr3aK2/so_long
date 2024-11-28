#include "../../../includes/so_long.h"

int	load_sprites(t_data *data)
{
	if (!data)
		return (-1);
	data->sprites.wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/walls/walls.xpm", &data->sprites.wall.width,
			&data->sprites.wall.height);
	if (!data->sprites.wall.img)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING WALL IMAGE\n");
	data->sprites.exit.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit/exit.xpm", &data->sprites.exit.width,
			&data->sprites.exit.height);
	if (!data->sprites.exit.img)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING EXIT IMAGE\n");
	data->sprites.exit_2.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/exit/exit_2.xpm", &data->sprites.exit.width,
			&data->sprites.exit.height);
	if (!data->sprites.exit_2.img)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING EXIT_2 IMAGE\n");
	data->sprites.floor.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/floor/floor.xpm", &data->sprites.floor.width,
			&data->sprites.floor.height);
	if (!data->sprites.floor.img)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING FLOOR IMAGE\n");
	data->sprites.collectibles.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/collectibles/collectibles.xpm",
			&data->sprites.collectibles.width,
			&data->sprites.collectibles.height);
	if (!data->sprites.collectibles.img)
		exit_error(data, "ERROR:\nLOAD_SPRITES: ERROR LOADING COLLECT IMAGE\n");
	return (1);
}

int	load_player(t_data *data)
{
	if (!data)
		return (-1);
	data->player.idle.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/static_img/player_right.xpm",
			&data->player.idle.width, &data->player.idle.height);
	if (!data->player.idle.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING PLAYER IMAGE\n");
	data->player.front.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/static_img/player_right.xpm",
			&data->player.front.width, &data->player.front.height);
	if (!data->player.front.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING PLAYER FRONT IMAGE\n");
	data->player.back.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/static_img/player_right.xpm",
			&data->player.back.width, &data->player.back.height);
	if (!data->player.back.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING PLAYER BACK IMAGE\n");
	data->player.right.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/static_img/player_right.xpm",
			&data->player.right.width, &data->player.right.height);
	if (!data->player.right.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING PLAYER RIGHT IMAGE\n");
	data->player.left.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/player/static_img/player_left.xpm",
			&data->player.left.width, &data->player.left.height);
	if (!data->player.left.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING PLAYER LEFT IMAGE\n");
	return (1);
}

/* static int	load_enemy(t_data *data)
{
	if (!data)
		return (-1);
	data->enemy.idle.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy/static_img/enemy_right.xpm",
			&data->enemy.idle.width, &data->enemy.idle.height);
	if (!data->enemy.idle.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING enemy IMAGE\n");
	data->enemy.front.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy/static_img/enemy_right.xpm",
			&data->enemy.front.width, &data->enemy.front.height);
	if (!data->enemy.front.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING enemy FRONT IMAGE\n");
	data->enemy.back.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy/static_img/enemy_right.xpm",
			&data->enemy.back.width, &data->enemy.back.height);
	if (!data->enemy.back.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING enemy BACK IMAGE\n");
	data->enemy.right.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy/static_img/enemy_right.xpm",
			&data->enemy.right.width, &data->enemy.right.height);
	if (!data->enemy.right.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING enemy RIGHT IMAGE\n");
	data->enemy.left.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"assets/enemy/static_img/enemy_left.xpm",
			&data->enemy.left.width, &data->enemy.left.height);
	if (!data->enemy.left.img)
		exit_error(data, "LOAD_SPRITES: ERROR LOADING enemy LEFT IMAGE\n");
	return (1);
} */