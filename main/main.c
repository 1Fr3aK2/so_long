#include "../includes/so_long.h"

/* static int	animation(t_data *data)
{
	static int	flag_colletc1 = 0;
	int			y;
	int			x;

	y = -1;
	while (data->map.map[++y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'C')
			{
				if (flag_colletc1 == 0)
					mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
						data->sprites.collectibles.img, x * 64, y * 64);
				else
					mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
						data->sprites.collectibles.img, x * 64, y * 64);
			}
			x++;
		}
	}
	flag_colletc1 = !flag_colletc1;
	usleep(500000);
	return (0);
} */










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
	mlx_loop(data.mlx_ptr);
	/* mlx_string_put(data.mlx_ptr, data.window_ptr, 15, 15, 16777215, "0");
	mlx_loop_hook(data.mlx_ptr, animation, &data); */
	/* mlx_loop(data.mlx_ptr); */
	/* free_arr(data.map.map, data.map.height); //vai ser libertado em main; */
	return (0);
}

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data  imagem;


	mlx = mlx_init(); // iniciar uma conexao com api, iniciar minilibx
	mlx_win = mlx_new_window(mlx, 500, 500, "fck off"); //criar uma nova janela
	for (int y = 0; y < ALTURA - 50; ++y)
	{
		for (int x = 0; y < LARGURA - 50; ++x)
		{
			mlx_pixel_put(mlx, mlx_win, x + 200, y + 200, RED);
		}
	}
	mlx_loop(mlx); // mantem o programa a correr
} */

/* 	imagem.img = mlx_new_image(mlx, 600, 4801); //inicalizar a imagem
	imagem.addr = mlx_get_data_addr(imagem.img, &imagem.bits_per_pixel,
				&imagem.line_length, &imagem.endian); //obter o adress da imagem
	my_pixel_put(&imagem, 100, 5, 0x00FF0000); // estrutra, linha, coluna, cor
	mlx_put_image_to_window(mlx, mlx_win, imagem.img, 0,
		0);// colocar a imagem na janel */