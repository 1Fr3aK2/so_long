#include "../../../includes/so_long.h"

void	check_valid_map(t_map *map, t_data *data)
{
	if (!map || !data)
		return ;
	if (check_format(map) != 1)
		exit_error(data, "CHECK_FORMAT/RECTANGULAR : RECTANGULAR ERROR\n");
	else
		ft_putstr_fd("CHECK_FORMAT/RECTANGULAR : PASSED\n", 2);
	if (valid_chars(map) != 1)
		exit_error(data, "CHECK_FORMAT/CHARS : CHARS ERROR\n");
	else
		ft_putstr_fd("CHECK_FORMAT/CHARS : PASSED\n", 2);
	if (check_walls(map) != 1)
		exit_error(data, "CHECK_FORMAT/WALLS : WALL ERROR\n");
	else
		ft_putstr_fd("CHECK_FORMAT/WALLS : PASSED\n", 2);
	if (check_exit(map) != 1)
		exit_error(data, "CHECK_FORMAT/EXIT : EXIT ERROR (less/more than 1 EXIT)\n");
	else
		ft_putstr_fd("CHECK_FORMAT/EXIT : PASSED\n", 2);
	if (check_collectibles(map) != 1)
		exit_error(data, "CHECK_FORMAT/COLLECTIBLES : COLLECTIBLES ERROR (less than 1)\n");
	else
		ft_putstr_fd("CHECK_FORMAT/COLLECTIBLES : PASSED\n", 2);
	if (check_start_pos(map) != 1)
		exit_error(data, "CHECK_FORMAT/START_POS : START_POS ERROR (less/more than 1 start_pos)\n");
	else
		ft_putstr_fd("CHECK_FORMAT/START_POS : PASSED\n", 2);
	/* if (check_valid_path(map) != 1)
		exit_error(data, "CHECK_FORMAT/VALID_PATH : VALID_PATH ERROR\n");
	else
		ft_putstr_fd("CHECK_FORMAT/VALID_PATH : PASSED\n", 2); */
	
}

void	init_map(char *file, t_data *data)
{
	check_map_name(file);
	get_lines(data, file);
	get_map(file, data);
	check_valid_map(&data->map, data);
	close_fds(0);
	check_open_fds();
	free_arr(data->map.map, data->map.height);
}
