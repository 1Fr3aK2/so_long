#include "../../../../includes/so_long.h"

int	check_valid_map(t_map *map, t_data *data)
{
	if (!map || !data)
		return (-1);
	if (check_format(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/RECTANGULAR: RECTANGULAR ERROR\n");
	else
		ft_putstr_fd("CHECK_MAP/RECTANGULAR: PASSED\n", 2);
	if (valid_chars(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/CHARS: CHARS ERROR\n");
	else
		ft_putstr_fd("CHECK_MAP/CHARS : PASSED\n", 2);
	if (check_walls(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/WALLS: WALL ERROR\n");
	else
		ft_putstr_fd("CHECK_MAP/WALLS : PASSED\n", 2);
	if (check_exit(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/EXIT: EXIT ERROR\n");
	else
		ft_putstr_fd("CHECK_MAP/EXIT : PASSED\n", 2);
	if (check_collectibles(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/COLLECt: COLLECTIBLES ERROR\n");
	else
		ft_putstr_fd("CHECK_MAP/COLLECTIBLES: PASSED\n", 2);
	if (check_start_pos(map) != 1)
		exit_error(data, "ERROR:\nCHECK_MAP/START_POS: START_POS ERROR\n");
	else
		ft_putstr_fd("CHECK_MAP/START_POS: PASSED\n", 2);
	ft_putstr_fd("CHECK_VALID_MAP: PASSED\n", 2);
	return (1);
}
