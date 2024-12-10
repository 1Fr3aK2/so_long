#include "../includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr_fd("ERROR:\n", 2);
		ft_putstr_fd("Invalid number of arguments!!\n", 2);
		ft_putstr_fd("Use: ./so_long map.ber\n", 2);
		return (-1);
	}
	init_struct(&data);
	if (init_map(argv[1], &data) != 1)
		exit_error(&data, "ERROR:\nCouldn't initialize the map\n");
	if (init_game(&data) != 1)
		exit_error(&data, "ERROR:\nCouldn't initialize the game\n");
	mlx_loop_hook(data.mlx_ptr, game_loop, &data);
	mlx_loop(data.mlx_ptr);
	return (1);
}
