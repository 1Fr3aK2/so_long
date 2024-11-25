#include "../includes/so_long.h"


int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("Número inválido de argumentos\nUso: ./so_long map.ber\n",
			2);
		return (1);
	}
	/* printf("screen_width: %d screen_size: %d\n", data.screen_width, data.screen_size); */
	init_struct(&data);
	printf("width : %d\n", data.map.width);
	printf("height : %d\n", data.map.height);
	printf("start_pos  : %d\n", data.map.start_pos);
	printf("collectibles  : %d\n", data.map.collectibles);
	printf("exit : %d\n", data.map.exit);
	init_map(argv[1], &data);
	printf("width : %d\n", data.map.width);
	printf("height : %d\n", data.map.height);
	printf("start_pos : %d\n", data.map.start_pos);
	printf("collectibles : %d\n", data.map.collectibles);
	printf("exit : %d\n", data.map.exit);
	init_game(&data);
	mlx_loop_hook(data.mlx_ptr, game_loop, &data);
    mlx_key_hook(data.window_ptr, handle_key, &data);
	mlx_hook(data.window_ptr, DestroyNotify, StructureNotifyMask, press_X, &data);
    mlx_loop(data.mlx_ptr);
	return (0);
}

